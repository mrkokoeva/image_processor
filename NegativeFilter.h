#pragma once

#include "Filter.h"

class NegativeFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
};
