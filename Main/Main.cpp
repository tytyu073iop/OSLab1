#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

struct employee {
    int num;        // Employee ID number
    char name[10];  // Employee name
    double hours;   // Number of hours worked
};

void printBinaryFileContent(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    if (!infile) {
        std::cerr << "Error opening binary file" << std::endl;
        return;
    }

    employee emp;
    while (infile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        std::cout << "Employee ID: " << emp.num << ", Name: " << emp.name << ", Hours: " << emp.hours << std::endl;
    }

    infile.close();
}

void printReportFileContent(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening report file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    infile.close();
}

int main() {
    std::string binaryFileName;
    int numRecords;
    std::string exe;


    std::cout << "E t w to exe: ";
    std::cin >> exe;
    std::cout << "Enter the name of the binary file: ";
    std::cin >> binaryFileName;
    std::cout << "Enter the number of records: ";
    std::cin >> numRecords;

    // Step 2: Run Creator
    std::string creatorCmd = exe + " " + binaryFileName + " " + std::to_string(numRecords);
    STARTUPINFO siCreator = { sizeof(siCreator) };
    PROCESS_INFORMATION piCreator;

    if (!CreateProcess(NULL, const_cast<char *>(creatorCmd.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &siCreator, &piCreator)) {
        std::cerr << "Error: Unable to start Creator process:" << GetLastError() << std::endl;
        return 1;
    } else {
        std::cout << "Creator started sucsesfully\n";
    }

    // Step 3: Wait for Creator to finish
    WaitForSingleObject(piCreator.hProcess, INFINITE);

    std::cout << "closed Creator\n";
    CloseHandle(piCreator.hProcess);
    CloseHandle(piCreator.hThread);

    // Step 4: Print binary file content
    printBinaryFileContent(binaryFileName);

    // Step 5: Get report file name and hourly rate
    std::string reportFileName;
    double hourlyRate;

    std::cout << "E t w to exe: ";
    std::cin >> exe;
    std::cout << "Enter the name of the report file: ";
    std::cin >> reportFileName;
    std::cout << "Enter the hourly rate: ";
    std::cin >> hourlyRate;

    // Step 6: Run Reporter
    std::string reporterCmd = exe + " " + binaryFileName + " " + reportFileName + " " + std::to_string(hourlyRate);
    STARTUPINFO siReporter = { sizeof(siReporter) };
    PROCESS_INFORMATION piReporter;

    
    if (!CreateProcess(NULL, const_cast<char*>(reporterCmd.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &siReporter, &piReporter)) {
        std::cerr << "Error: Unable to start Reporter process: " << GetLastError() << std::endl;
        return 1;
    }

    // Step 7: Wait for Reporter to finish
    WaitForSingleObject(piReporter.hProcess, INFINITE);
    CloseHandle(piReporter.hProcess);
    CloseHandle(piReporter.hThread);

    // Step 8: Print report file content
    printReportFileContent(reportFileName);

    return 0;
}
