#include "Image.h"

void Image::SetSize(int32_t width, int32_t height) {
    width_ = width;
    height_ = height;
    image_.resize(height_, std::vector<Color>(width_));
}

void Image::SetImage(std::vector<std::vector<Color>> image) {
    height_ = image.size();
    width_ = image[0].size();
    image_ = image;
}

Color Image::GetPixel(size_t x, size_t y) const {
    return image_[x][y];
}

void Image::SetPixel(size_t x, size_t y, Color c) {
    image_[x][y] = c;
}

int32_t Image::GetHeight() const {
    return height_;
}

int32_t Image::GetWidth() const {
    return width_;
}

Color Image::GetClosestPixel(int32_t x, int32_t y) const {
    if (x >= 0 && x < height_ && y >= 0 && y < width_) {
        return image_[x][y];
    }
    if (x < 0) {
        ++x;
    } else if (x >= height_) {
        --x;
    }
    if (y < 0) {
        ++y;
    } else if (y >= width_) {
        --y;
    }
    return image_[x][y];
}

std::vector<std::vector<Color>> Image::GetImage() const {
    return image_;
}
