#include "BMPWriter.h"

BMPWriter::BMPWriter(std::string path) {
    path_ = path;
}

void BMPWriter::WriteBMP(Image &img) {
    writer_.open(path_, std::ios::out | std::ios::binary);
    if (!writer_.is_open()) {
        throw std::runtime_error("WriteBMP: Trying to write output. No such file or directory");
    }
    int32_t height = img.GetHeight();
    int32_t width = img.GetWidth();
    unsigned char padding[3] = {0, 0 , 0};
    int32_t paddingLength = ((4 - (width * 3) % 4) % 4);
    int32_t fileHeaderSize = 14;
    int32_t infoHeaderSize = 40;
    int32_t fileSize = fileHeaderSize + infoHeaderSize + height * width * 3 + paddingLength * height;
    WriteFileHeader(fileSize);
    WriteInfoHeader(width, height);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            Color colorPixel = img.GetPixel(i, j);
            unsigned char R = static_cast<unsigned char>(colorPixel.GetR() * 255.0);
            unsigned char G = static_cast<unsigned char>(colorPixel.GetG() * 255.0);
            unsigned char B = static_cast<unsigned char>(colorPixel.GetB() * 255.0);
            unsigned char color[3] = {B, G, R};
            writer_.write(reinterpret_cast<char*>(color), 3);
        }
        writer_.write(reinterpret_cast<char*>(padding), paddingLength);
    }
    writer_.close();
}

void BMPWriter::WriteFileHeader(int32_t fileSize) {
    int32_t fileHeaderSize = 14;
    int32_t infoHeaderSize = 40;
    unsigned char fileHeader[fileHeaderSize];
    fileHeader[0] = 'B';
    fileHeader[1] = 'M';
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;
    fileHeader[6] = 0;
    fileHeader[7] = 0;
    fileHeader[8] = 0;
    fileHeader[9] = 0;
    fileHeader[10] = infoHeaderSize + fileHeaderSize;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;
    writer_.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
}

void BMPWriter::WriteInfoHeader(int32_t width, int32_t height) {
    int32_t fileHeaderSize = 14;
    int32_t infoHeaderSize = 40;
    unsigned char infoHeader[infoHeaderSize];
    infoHeader[0] = infoHeaderSize;
    infoHeader[1] = 0;
    infoHeader[2] = 0;
    infoHeader[3] = 0;
    infoHeader[4] = width;
    infoHeader[5] = width >> 8;
    infoHeader[6] = width >> 16;
    infoHeader[7] = width >> 24;
    infoHeader[8] = height;
    infoHeader[9] = height >> 8;
    infoHeader[10] = height >> 16;
    infoHeader[11] = height >> 24;
    infoHeader[12] = 1;
    infoHeader[13] = 0;
    infoHeader[14] = 24;
    infoHeader[15] = 0;
    for (size_t i = 16; i <= 39; ++i) {
        infoHeader[i] = 0;
    }
    writer_.write(reinterpret_cast<char*>(infoHeader), infoHeaderSize);
}
