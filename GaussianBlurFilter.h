#pragma once

#include "Filter.h"
#include "cmath"

class GaussianBlurFilter : public Filter {
public:
    GaussianBlurFilter(double sigma);
    Image applyFilter(Image &img) override;
private:
    double sigma_;
    double PI_;
    double sigmaSquared_;
    double calculation(double x0, double y0, double x, double y) const;

};
