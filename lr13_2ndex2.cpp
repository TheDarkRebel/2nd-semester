#include <iostream>
#include <fstream>
#include <string>

void formatParagraphs(int lineWidth) {
    std::string inputFileName;
    std::cout << "Введите имя входного файла: ";
    std::cin >> inputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    std::string outputFileName;
    std::cout << "Введите имя выходного файла: ";
    std::cin >> outputFileName;

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    std::string paragraph;
    std::string word;
    while (inputFile >> word) {
        if (word.back() == '.' || word.back() == '?' || word.back() == '!') {
            paragraph += word;
            paragraph += '\n'; 
            outputFile << paragraph;
            paragraph.clear();
        } else {
            paragraph += word;
            paragraph += ' '; 
            if (paragraph.size() > lineWidth) {
                paragraph += '\n';
                outputFile << paragraph;
                paragraph.clear();
            }
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    int lineWidth;

    std::cout << "Введите ширину строки: ";
    std::cin >> lineWidth;

    formatParagraphs(lineWidth);

    std::cout << "Файл успешно переформатирован." << std::endl;

    return 0;
}
