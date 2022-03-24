#include "GrayScaleFilter.h"

Image GrayScaleFilter::applyFilter(Image &img) {
    Image res;
    res.SetSize(img.GetWidth(), img.GetHeight());
    for (size_t i = 0; i < res.GetHeight(); ++i) {
        for (size_t j = 0; j < res.GetWidth(); ++j) {
            double R = 0.299 * img.GetPixel(i, j).GetR();
            double G = 0.587 * img.GetPixel(i, j).GetG();
            double B = 0.114 * img.GetPixel(i, j).GetB();
            double clr = R + G + B;
            res.SetPixel(i, j, Color(clr, clr, clr));
        }
    }
    return res;
}
