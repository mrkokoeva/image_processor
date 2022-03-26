#pragma once

#include <fstream>
#include <vector>
#include "Color.h"
#include "Image.h"
#include <iostream>

class BMPReader {
public:
    BMPReader(std::string path);
    Image ReadBMP();
private:
    std::string path_;
    std::ifstream reader_;
};
