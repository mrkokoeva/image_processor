#include "CropFilter.h"

CropFilter::CropFilter(int32_t width, int32_t height) : width_(width), height_(height) {}

Image CropFilter::applyFilter(Image &img) {
    Image res;
    int32_t width = std::min(width_, img.GetWidth());
    int32_t height = std::min(height_, img.GetHeight());
    std::vector<std::vector<Color>> new_img(height, std::vector<Color>(width));
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            new_img[i][j] = img.GetPixel(i + img.GetHeight() - height, j);
        }
    }
    res.SetImage(new_img);
    return res;
}

