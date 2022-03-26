#pragma once

#include <fstream>
#include "Image.h"

class BMPWriter {
public:
    BMPWriter(std::string path);
    void WriteBMP(Image &img);

private:
    std::string path_;
    std::ofstream writer_;

    void WriteFileHeader(int32_t fileSize);
    void WriteInfoHeader(int32_t width, int32_t height);
};
