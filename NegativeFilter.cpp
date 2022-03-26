#include "NegativeFilter.h"

Image NegativeFilter::applyFilter(Image &img) {
    Image res;
    res.SetSize(img.GetWidth(), img.GetHeight());
    for (size_t i = 0; i < res.GetHeight(); ++i) {
        for (size_t j = 0; j < res.GetWidth(); ++j) {
            double R = 1 - img.GetPixel(i, j).GetRed();
            double G = 1 - img.GetPixel(i, j).GetGreen();
            double B = 1 - img.GetPixel(i, j).GetBlue();
            res.SetPixel(i, j, Color(R, G, B));
        }
    }
    return res;
}
