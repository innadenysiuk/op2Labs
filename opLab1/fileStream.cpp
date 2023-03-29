#include "fileStream.h"

void createFile_s (std::string nameFile) {
    std::fstream inFile;
    inFile.open(nameFile, std::ios::out);
    if (!inFile.is_open()) {
        std::cout << "ERROR! Cannot create file." << std::endl;
    }
    else {
        std::cout << "File is created." << std::endl;
    }
    inFile.close();
}

void addText_s (std::string nameFile) {
    std::cout << "Adding data to file..." << std::endl;
    std::fstream inFile;
    inFile.open(nameFile, std::ios::app);
    if (!inFile.is_open()) {
        std::cout << "ERROR!" << std::endl;
    }
    else {
        std::cout << "Enter text to add. To end, enter 'stop'." << std::endl;
        std::cin.ignore();
        std::string text;
        while (1) {
            std::getline(std::cin, text);
            if (text == "stop") {
                break;
            }
            inFile << text << std::endl;
        }
        std::cout << "Data has been added to the file." << std::endl;
    }
    inFile.close();
}

void process_s (std::string nameFile) {
    std::ifstream inFile(nameFile);
    std::ofstream outFile("outfiles.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cout << "ERROR!" << std::endl;
    }
    else {
        std::string line;
        while (getline(inFile, line)) {
            std::stringstream ss(line);
            int smallest = INT_MAX;
            bool foundNumber = false;
            std::string word;
            std::stringstream numsReversed;
            while (ss >> word) {
                if (isdigit(word[0])) {
                    foundNumber = true;
                    int num = stoi(word);
                    smallest = std::min(smallest, num);
                    numsReversed.str(std::to_string(num) + " " + numsReversed.str());
                }
            }
            if (foundNumber) {
                ss.clear();
                ss.seekg(0);
                outFile << smallest;
                numsReversed.seekg(0);
                std::string s = std::to_string(smallest);
                while (numsReversed >> word) {
                    if (word != s) {
                        outFile << ", " << word;
                    }
                }
                ss.clear();
                ss.seekg(0);
                while (ss >> word) {
                    if (!isdigit(word[0])) {
                        outFile << ", " << word;
                    }
                }
                outFile << std::endl;
            }
        }
        inFile.close();
        outFile.close();
    }
}

void fileOutput_s(std::string nameFile) {
    std::cout << "Input file:" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::ifstream inFile(nameFile);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    }
    else {
        std::cout << "ERROR!" << std::endl;
    }
    std::cout << "Output file:" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::ifstream outFile("outfiles.txt");
    if (outFile.is_open()) {
        std::string line;
        while (std::getline(outFile, line)) {
            std::cout << line << std::endl;
        }
        outFile.close();
    }
    else {
        std::cout << "ERROR!" << std::endl;
    }
}
