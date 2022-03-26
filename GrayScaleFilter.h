#pragma once

#include "Filter.h"

class GrayScaleFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
};
