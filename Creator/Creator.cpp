#include <iostream>
#include <fstream>
#include <string>
#include <limits>

struct employee {
    int num;        // Employee ID number
    char name[10];  // Employee name
    double hours;   // Number of hours worked
};

bool get_int(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool get_double(double& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file_name> <number_of_records>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int num_records;
    try {
        num_records = std::stoi(argv[2]);
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error: number of records must be a number. More presize information: " << e.what() << std::endl;
        return 1;
    }

    if (num_records <= 0) {
        std::cerr << "Error: number of records must be a positive number" << std::endl;
        return 1;
    }

    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile) {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    for (int i = 0; i < num_records; ++i) {
        employee emp;
        std::cout << "Enter details for employee #" << (i + 1) << std::endl;

        std::cout << "ID Number: ";
        while (!get_int(emp.num)) {
            std::cerr << "Error: enter a valid number for ID" << std::endl;
            std::cout << "ID Number: ";
        }

        std::cout << "Name: ";
        std::cin.ignore();
        std::cin.getline(emp.name, 10);

        std::cout << "Hours: ";
        while (!get_double(emp.hours)) {
            std::cerr << "Error: enter a valid number for hours" << std::endl;
            std::cout << "Hours: ";
        }

        outfile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
    }

    outfile.close();
    if (!outfile.good()) {
        std::cerr << "Error writing file" << std::endl;
        return 1;
    }

    std::cout << "Records successfully saved to file " << filename << std::endl;
    return 0;
}
