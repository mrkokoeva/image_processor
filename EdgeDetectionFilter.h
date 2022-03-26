#pragma once

#include "Filter.h"
#include "GrayScaleFilter.h"

class EdgeDetectionFilter : public Filter {
public:
    EdgeDetectionFilter(double threshold);
    Image applyFilter(Image &img) override;
private:
    double threshold_;
};
