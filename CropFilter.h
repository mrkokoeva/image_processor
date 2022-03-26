#pragma once

#include "Filter.h"

class CropFilter : public Filter {
public:
    CropFilter(int32_t width, int32_t height);
    Image applyFilter(Image &img) override;
private:
    int32_t width_;
    int32_t height_;
};
