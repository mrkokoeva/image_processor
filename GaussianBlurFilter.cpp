#include "GaussianBlurFilter.h"

GaussianBlurFilter::GaussianBlurFilter(double sigma) {
    sigma_ = sigma;
    sigmaSquared_ = sigma * sigma;
    PI_ = acos(-1);
}

Image GaussianBlurFilter::applyFilter(Image &img) {
    double mult1 = 1 / (2 * PI_ * sigmaSquared_);
    Image temp;
    temp.SetSize(img.GetWidth(), img.GetHeight());
    for (size_t x0 = 0; x0 < temp.GetHeight(); ++x0) {
        for (size_t y0 = 0; y0 < temp.GetWidth(); ++y0) {
            double R = 0;
            double G = 0;
            double B = 0;
            for (size_t x = 0; x < temp.GetHeight(); ++x) {
                for (size_t y = 0; y < temp.GetWidth(); ++ y) {
                    double multiplier = calculation(x0, y0, x, y) * mult1;
                    R += img.GetPixel(x, y).GetR() * multiplier;
                    G += img.GetPixel(x, y).GetG() * multiplier;
                    B += img.GetPixel(x, y).GetB() * multiplier;
                }
            }
            temp.SetPixel(x0, y0, Color(R, G, B));
        }
    }
    return temp;
}

double GaussianBlurFilter::calculation(double x0, double y0, double x, double y) const {
    double diff_x = std::abs(x0 - x);
    diff_x *= diff_x;
    double diff_y = std::abs(y0 - y);
    diff_y *= diff_y;
    return exp(-(diff_x + diff_y) / (2 * sigmaSquared_));
}
