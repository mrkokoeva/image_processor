#ifndef IMAGE_PROCESSOR_FILTER_H
#define IMAGE_PROCESSOR_FILTER_H

#include "Image.h"

class Filter {
public:
    virtual Image applyFilter(Image &img) = 0;
private:
};


#endif //IMAGE_PROCESSOR_FILTER_H
