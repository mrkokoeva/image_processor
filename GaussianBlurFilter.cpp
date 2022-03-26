#include "GaussianBlurFilter.h"

GaussianBlurFilter::GaussianBlurFilter(double sigma) {
    sigma_ = sigma;
    sigmaSquared_ = sigma * sigma;
    PI_ = acos(-1);
}

Image GaussianBlurFilter::applyFilter(Image &img) {
    double mult1 = 1 / (2 * PI_ * sigmaSquared_);
    Image res;
    res.SetSize(img.GetWidth(), img.GetHeight());
    for (size_t x0 = 0; x0 < res.GetHeight(); ++x0) {
        for (size_t y0 = 0; y0 < res.GetWidth(); ++y0) {
            double R = 0;
            double G = 0;
            double B = 0;
            for (size_t x = 0; x < res.GetHeight(); ++x) {
                for (size_t y = 0; y < res.GetWidth(); ++ y) {
                    double multiplier = calculation(x0, y0, x, y) * mult1;
                    R += img.GetPixel(x, y).GetRed() * multiplier;
                    G += img.GetPixel(x, y).GetGreen() * multiplier;
                    B += img.GetPixel(x, y).GetBlue() * multiplier;
                }
            }
            res.SetPixel(x0, y0, Color(R, G, B));
        }
    }
    return res;
}

double GaussianBlurFilter::calculation(double x0, double y0, double x, double y) const {
    double diff_x = std::abs(x0 - x);
    diff_x *= diff_x;
    double diff_y = std::abs(y0 - y);
    diff_y *= diff_y;
    return exp(-(diff_x + diff_y) / (2 * sigmaSquared_));
}
