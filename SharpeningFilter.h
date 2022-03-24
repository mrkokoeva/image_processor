#ifndef IMAGE_PROCESSOR_SHARPENINGFILTER_H
#define IMAGE_PROCESSOR_SHARPENINGFILTER_H

#include "Filter.h"
#include <algorithm>

class SharpeningFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
private:
};


#endif //IMAGE_PROCESSOR_SHARPENINGFILTER_H
