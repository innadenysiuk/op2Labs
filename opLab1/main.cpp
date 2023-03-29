#include "filePointer.h"
#include "fileStream.h"

int main(int argc, char* argv[]) {

    std::string modeFlag(argv[1]);
    std::string mode(argv[2]);

    if (modeFlag != "-mode") {
        std::cout << "ERROR!" << std::endl;
    }

    if (mode == "fileStream" || mode == "FileStream") {
        std::cout << "FileStream mode..." << std::endl;
        std::cout << "Enter a file name[to create]:" << std::endl;
        std::string nameFile;
        std::cin >> nameFile;
        createFile_s (nameFile);
        addText_s (nameFile);
        process_s (nameFile);
        fileOutput_s (nameFile);
        std::cout << "Do you want add text to file? yes/no" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice == "yes") {
            addText_s (nameFile);
            process_s (nameFile);
            fileOutput_s (nameFile);
        }
    }
    else if (mode == "filePointer" || mode == "FilePointer") {
        std::cout << "FilePointer mode..." << std::endl;
        std::cout << "Enter a file name[to create]:" << std::endl;
        char nameFile[50];
        std::cin >> nameFile;
        createFile_p (nameFile);
        addText_p(nameFile);
        process_p(nameFile);
        fileOutput_p (nameFile);
        std::cout << "Do you want add text to file? yes/no" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice == "yes") {
            addText_p (nameFile);
            process_p (nameFile);
            fileOutput_p (nameFile);
        }
    }
    else {
        std::cout << "ERROR! Invalid input." << std::endl;
    }
    return 0;
}