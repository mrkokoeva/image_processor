#ifndef IMAGE_PROCESSOR_CROPFILTER_H
#define IMAGE_PROCESSOR_CROPFILTER_H

#include "Filter.h"

class CropFilter : public Filter {
public:
    CropFilter(int32_t width, int32_t height);
    Image applyFilter(Image &img) override;
private:
    int32_t width_;
    int32_t height_;
};


#endif //IMAGE_PROCESSOR_CROPFILTER_H
