#ifndef IMAGE_PROCESSOR_IMAGE_H
#define IMAGE_PROCESSOR_IMAGE_H

#include <stdint.h>
#include "Color.h"

class Image {
public:
    void SetSize(int32_t width, int32_t height);
    void SetImage(std::vector<std::vector<Color>> image);
    Color GetPixel(size_t x, size_t y) const;
    void SetPixel(size_t x, size_t y, Color c);
    int32_t GetHeight() const;
    int32_t GetWidth() const;
    Color GetClosestPixel(int32_t x, int32_t y) const;
    std::vector<std::vector<Color>> GetImage() const;
private:
    int32_t width_;
    int32_t height_;
    std::vector<std::vector<Color>> image_;
};


#endif //IMAGE_PROCESSOR_IMAGE_H
