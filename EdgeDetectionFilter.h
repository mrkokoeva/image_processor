#ifndef IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H
#define IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H

#include "Filter.h"
#include "GrayScaleFilter.h"

class EdgeDetectionFilter : public Filter {
public:
    EdgeDetectionFilter(double threshold);
    Image applyFilter(Image &img) override;
private:
    double threshold_;
};


#endif //IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H
