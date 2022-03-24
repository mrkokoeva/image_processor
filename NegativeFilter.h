#ifndef IMAGE_PROCESSOR_NEGATIVEFILTER_H
#define IMAGE_PROCESSOR_NEGATIVEFILTER_H

#include "Filter.h"

class NegativeFilter : public Filter {
public:
    Image applyFilter(Image &img) override;
private:
};


#endif //IMAGE_PROCESSOR_NEGATIVEFILTER_H
