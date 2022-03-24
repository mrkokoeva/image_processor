#ifndef IMAGE_PROCESSOR_GRAYSCALEFILTER_H
#define IMAGE_PROCESSOR_GRAYSCALEFILTER_H

#include "Filter.h"

class GrayScaleFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
private:
};


#endif //IMAGE_PROCESSOR_GRAYSCALEFILTER_H
