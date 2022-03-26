#include "BMPReader.h"

BMPReader::BMPReader(std::string path) : path_(path) {}

Image BMPReader::ReadBMP() {
    reader_.open(path_, std::ios::in | std::ios::binary);
    if (!reader_.is_open()) {
        throw std::runtime_error("ReadBMP: Trying to read input. No such file or directory");
    }
    unsigned char fileHeader[14];
    reader_.read(reinterpret_cast<char*>(fileHeader), 14);
    unsigned char infoHeader[40];
    reader_.read(reinterpret_cast<char*>(infoHeader), 40);
    int32_t width = infoHeader[4] + (infoHeader[5] << 8) + (infoHeader[6] << 16) + (infoHeader[7] << 24);
    int32_t height = infoHeader[8] + (infoHeader[9] << 8) + (infoHeader[10] << 16) + (infoHeader[11] << 24);
    Image image;
    image.SetSize(width, height);
    int32_t padding = ((4 - (width * 3) % 4) % 4);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            unsigned char color[3];
            reader_.read(reinterpret_cast<char*>(color), 3);
            double R = static_cast<double>(color[2]) / 255.0;
            double G = static_cast<double>(color[1]) / 255.0;
            double B = static_cast<double>(color[0]) / 255.0;
            image.SetPixel(i, j, Color(R, G, B));
        }
        reader_.ignore(padding);
    }
    reader_.close();
    return image;
}


