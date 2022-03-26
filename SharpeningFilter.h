#pragma once

#include "Filter.h"
#include <algorithm>

class SharpeningFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
};
