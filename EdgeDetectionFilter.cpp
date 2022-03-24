#include "EdgeDetectionFilter.h"

Image EdgeDetectionFilter::applyFilter(Image &img) {
    GrayScaleFilter filter;
    Image res = filter.applyFilter(img);
    for (size_t i = 0; i < res.GetHeight(); ++i) {
        for (size_t j = 0; j < res.GetWidth(); ++j) {
            double clr = 4 * img.GetClosestPixel(i, j).GetR();
            clr -= img.GetClosestPixel(i - 1, j).GetR();
            clr -= img.GetClosestPixel(i + 1, j).GetR();
            clr -= img.GetClosestPixel(i, j - 1).GetR();
            clr -= img.GetClosestPixel(i, j + 1).GetR();
            clr = std::min(1.0, std::max(0.0, clr));
            if (clr > threshold_) {
                res.SetPixel(i, j, Color(1, 1, 1));
            } else {
                res.SetPixel(i, j, Color(0, 0, 0));
            }
        }
    }
    return res;
}

EdgeDetectionFilter::EdgeDetectionFilter(double threshold) {
    threshold_ = threshold;
}
