#include <iostream>
#include <memory>
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

std::vector<std::shared_ptr<Filter>> ParsedResults(int argc, char* argv[]) {
    std::vector<std::shared_ptr<Filter>> res;
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
                return {};
            }
            res.push_back(std::make_shared<CropFilter>(width, height));
        } else if (filterType == "-gs") {
            res.push_back(std::make_shared<GrayScaleFilter>());
        } else if (filterType == "-neg") {
            res.push_back(std::make_shared<NegativeFilter>());
        } else if (filterType == "-sharp") {
            res.push_back(std::make_shared<SharpeningFilter>());
        } else if (filterType == "-edge") {
            double threshold;
            try {
                std::string threshold_str = static_cast<std::string>(argv[idx++]);
                threshold = stof(threshold_str);
            } catch (std::exception &e) {
                std::cout << "Неправильный аргумент threshold" << std::endl;
                return {};
            }
            res.push_back(std::make_shared<EdgeDetectionFilter>(threshold));
        } else if (filterType == "-blur") {
            double sigma;
            try {
                std::string sigma_str = static_cast<std::string>(argv[idx++]);
                sigma = stof(sigma_str);
            } catch (std::exception &e) {
                std::cout << "Неправильный аргумент sigma" << std::endl;
                return {};
            }
            res.push_back(std::make_shared<GaussianBlurFilter>(sigma));
        } else {
            std::cout << "Неправильные аргументы";
            return {};
        }
    }
    return res;
}

void ApplyFilters(std::string& path_to_input, std::string& path_to_output,
                   std::vector<std::shared_ptr<Filter>> &filters) {
    BMPReader reader(path_to_input);
    Image img = reader.ReadBMP();
    for (auto filter : filters) {
        img = filter->applyFilter(img);
    }
    BMPWriter writer(path_to_output);
    writer.WriteBMP(img);
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
    std::vector<std::shared_ptr<Filter>> filters = ParsedResults(argc, argv);
    ApplyFilters(path_to_input, path_to_output, filters);
    return 0;
}
