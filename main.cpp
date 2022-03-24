#include <iostream>
#include "BMPReader.h"
#include "BMPWriter.h"
#include "CropFilter.h"
#include "GrayScaleFilter.h"
#include "NegativeFilter.h"
#include "SharpeningFilter.h"
#include "EdgeDetectionFilter.h"
#include "GaussianBlurFilter.h"
#include "windows.h"

void PrintHelp() {

    std::cout << "Описание формата аргументов командной строки:\n"
                 "{имя программы} {путь к входному файлу} "
                 "{путь к выходному файлу} [-{имя фильтра 1} [параметр фильтра 1] [параметр фильтра 2] ...] "
                 "[-{имя фильтра 2} [параметр фильтра 1] [параметр фильтра 2] ...] ...\n"
                 "Доступные фильтры: \n"
                 "-crop width height\n"
                 "-gs\n"
                 "-neg\n"
                 "-sharp\n"
                 "-edge threshold\n"
                 "-blur sigma\n";
}

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    if (argc == 1) {
        PrintHelp();
        return 0;
    }
    if (argc < 3) {
        std::cout << "Недостаточно аргументов командной строки";
        return 0;
    }
    std::string path_to_input = argv[1];
    std::string path_to_output = argv[2];

    BMPReader reader(path_to_input);
    Image img = reader.ReadBMP();

    size_t idx = 3;
    while (idx < argc) {
        std::string filterType = argv[idx++];
        if (filterType == "-crop") {
            int32_t width, height;
            try {
                std::string width_str = static_cast<std::string>(argv[idx++]);
                std::string height_str = static_cast<std::string>(argv[idx++]);
                width = stoi(width_str);
                height = stoi(height_str);
            } catch (std::exception &e) {
                std::cout << "Неправильные аргументы width, height" << std::endl;
                return 0;
            }
            CropFilter filter(width, height);
            img = filter.applyFilter(img);
        } else if (filterType == "-gs") {
            GrayScaleFilter filter;
            img = filter.applyFilter(img);
        } else if (filterType == "-neg") {
            NegativeFilter filter;
            img = filter.applyFilter(img);
        } else if (filterType == "-sharp") {
            SharpeningFilter filter;
            img = filter.applyFilter(img);
        } else if (filterType == "-edge") {
            double threshold;
            try {
                std::string threshold_str = static_cast<std::string>(argv[idx++]);
                threshold = stof(threshold_str);
            } catch (std::exception &e) {
                std::cout << "Неправильный аргумент threshold" << std::endl;
                return 0;
            }
            EdgeDetectionFilter filter(threshold);
            img = filter.applyFilter(img);
        } else if (filterType == "-blur") {
            double sigma;
            try {
                std::string sigma_str = static_cast<std::string>(argv[idx++]);
                sigma = stof(sigma_str);
            } catch (std::exception &e) {
                std::cout << "Неправильный аргумент threshold" << std::endl;
                return 0;
            }
            GaussianBlurFilter filter(sigma);
            img = filter.applyFilter(img);
        } else {
            std::cout << "Неправильные аргументы";
            return 0;
        }
    }
    BMPWriter writer(path_to_output);
    writer.WriteBMP(img);
    return 0;
}
