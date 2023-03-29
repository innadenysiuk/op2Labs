#include "filePointer.h"

FILE * inFile;
FILE * outFile;

void createFile_p (char * nameFile) {
    inFile = fopen(nameFile, "w");
    if (inFile == NULL) {
        std::cout << "ERROR! Cannot create file." << std::endl;
    }
    else {
        std::cout << "File is created." << std::endl;
    }
    fclose(inFile);
}

void addText_p (char * nameFile) {
    char text[1000];
    int n;
    inFile = fopen(nameFile, "a");
    std::cout << "Adding data to file..." << std::endl;
    std::cout << "Enter the number of lines:" << std::endl;
    std::cin >> n;
    std::cout << "Enter text to add:" << std::endl;
    std::cin.ignore();
    for (int i = 0; i < n; i++)
    {
        fgets(text, sizeof text, stdin);
        fputs(text, inFile);
    }
    std::cout << "Data has been added to the file." << std::endl;
    fclose (inFile);
}

int is_number(char* str) {
    int i, n;
    n = strlen(str);
    for (i = 0; i < n; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void process_p(char* nameFile) {
    inFile = fopen(nameFile, "r");
    if (inFile == NULL) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    outFile = fopen("outfilep.txt", "w");
    if (outFile == NULL) {
        std::cout << "ERROR!" << std::endl;
        fclose(inFile);
        return;
    }
    char line[1000];
    while (fgets(line, sizeof(line), inFile)) {
        int numbers[100];
        int numCount = 0;
        int minNum = 0;
        int i;
        char* words[100];
        int wordCount = 0;
        char* word = strtok(line, " ");
        while (word != NULL) {
            if (is_number(word)) {
                int num = atoi(word);
                numbers[numCount] = num;
                numCount++;
                if (minNum == 0 || num < minNum) {
                    minNum = num;
                }
            }
            else {
                words[wordCount] = word;
                wordCount++;
            }
            word = strtok(NULL, " ");
        }
        if (numCount > 0) {
            fprintf(outFile, "%d", minNum);
            for (i = numCount - 1; i >= 0; i--) {
                if (numbers[i] != minNum) {
                    fprintf(outFile, ", %d", numbers[i]);
                }
            }
            for (i = 0; i < wordCount; i++) {
                fprintf(outFile, ", %s", words[i]);
            }
        }
    }
    fclose(inFile);
    fclose(outFile);
}

void fileOutput_p (char * nameFile) {
    char inText[1000];
    std::cout << "Input file:" << std::endl;
    std::cout << "----------------------" << std::endl;
    inFile = fopen(nameFile, "r");
    if (inFile != NULL) {
        while (fgets(inText, 1000, inFile)) {
            std::cout << inText << std::endl;
        }
        fclose(inFile);
    }
    else {
        std::cout << "ERROR!" << std::endl;
    }
    char outText[1000];
    std::cout << "Output file:" << std::endl;
    std::cout << "----------------------" << std::endl;
    outFile = fopen("outfilep.txt", "r");
    if (outFile != NULL) {
        while (fgets(outText, 1000, outFile)) {
            std::cout << outText << std::endl;
        }
        fclose(outFile);
    }
    else {
        std::cout << "ERROR!" << std::endl;
    }
}