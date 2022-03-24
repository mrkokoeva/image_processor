#include "SharpeningFilter.h"

Image SharpeningFilter::applyFilter(Image &img) {
    Image res;
    res.SetSize(img.GetWidth(), img.GetHeight());
    for (size_t i = 0; i < res.GetHeight(); ++i) {
        for (size_t j = 0; j < res.GetWidth(); ++j) {
            double R = 5 * img.GetPixel(i, j).GetR();
            R -= img.GetClosestPixel(i - 1, j).GetR();
            R -= img.GetClosestPixel(i + 1, j).GetR();
            R -= img.GetClosestPixel(i, j - 1).GetR();
            R -= img.GetClosestPixel(i, j + 1).GetR();
            R = std::min(1.0, std::max(0.0, R));
            double G = 5 * img.GetPixel(i, j).GetG();
            G -= img.GetClosestPixel(i - 1, j).GetG();
            G -= img.GetClosestPixel(i + 1, j).GetG();
            G -= img.GetClosestPixel(i, j - 1).GetG();
            G -= img.GetClosestPixel(i, j + 1).GetG();
            G = std::min(1.0, std::max(0.0, G));
            double B = 5 * img.GetPixel(i, j).GetB();
            B -= img.GetClosestPixel(i - 1, j).GetB();
            B -= img.GetClosestPixel(i + 1, j).GetB();
            B -= img.GetClosestPixel(i, j - 1).GetB();
            B -= img.GetClosestPixel(i, j + 1).GetB();
            B = std::min(1.0, std::max(0.0, B));
            res.SetPixel(i, j, Color(R, G, B));
        }
    }
    return res;
}
