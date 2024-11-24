#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::string replaceDigitsWithWords(const std::string& text) {

    std::unordered_map<char, std::string> digitToWord = {

        {'0', "zero"}, {'1', "one"}, {'2', "two"},
        {'3', "three"}, {'4', "four"}, {'5', "five"},
        {'6', "six"}, {'7', "seven"}, {'8', "eight"},
        {'9', "nine"}
    };

    std::string result;

    for (char ch : text) {
        if (isdigit(ch)) {
            result += digitToWord[ch] + " ";
        }
        else {
            result += ch;
        }
    }
    return result;
}

int main() {

    std::string inputFileName, outputFileName;
    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;
    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {

        std::cerr << "Error: Cannot open input file!" << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {

        std::cerr << "Error: Cannot open output file!" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::string modifiedLine = replaceDigitsWithWords(line);
        outputFile << modifiedLine << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Processing complete. Check the output file." << std::endl;

    return 0;
}
