#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct employee {
    int num;        // Employee ID number
    char name[10];  // Employee name
    double hours;   // Number of hours worked
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_binary_file> <report_file> <hourly_rate>" << std::endl;
        return 1;
    }

    std::string inputBinaryFile = argv[1];
    std::string reportFile = argv[2];
    double hourlyRate;

    try {
        hourlyRate = std::stod(argv[3]);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: hourly rate must be a valid number. More presize error: " << e.what() << std::endl;
        return 1;
    }

    std::ifstream infile(inputBinaryFile, std::ios::binary);
    if (!infile) {
        std::cerr << "Error opening input binary file" << std::endl;
        return 1;
    }

    std::ofstream outfile(reportFile);
    if (!outfile) {
        std::cerr << "Error opening report file" << std::endl;
        return 1;
    }

    outfile << "Report for file \"" << inputBinaryFile << "\"" << std::endl;
    outfile << "Employee ID | Name       | Hours | Salary" << std::endl;
    outfile << "-----------------------------------------" << std::endl;

    employee emp;
    while (infile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        double salary = emp.hours * hourlyRate;
        outfile << std::setw(11) << emp.num << " | "
            << std::setw(10) << emp.name << " | "
            << std::setw(5) << emp.hours << " | "
            << std::fixed << std::setprecision(2) << salary << std::endl;
    }

    infile.close();
    outfile.close();

    if (!infile.good() || !outfile.good()) {
        std::cerr << "Error processing files" << std::endl;
        return 1;
    }

    std::cout << "Report successfully generated in file " << reportFile << std::endl;
    return 0;
}
