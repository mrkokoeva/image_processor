#pragma once

#include "Image.h"

class Filter {
public:
    virtual Image applyFilter(Image &img) = 0;
};
