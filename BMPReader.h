#ifndef IMAGE_PROCESSOR_BMPREADER_H
#define IMAGE_PROCESSOR_BMPREADER_H

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
#endif //IMAGE_PROCESSOR_BMPREADER_H
