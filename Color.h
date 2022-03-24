#ifndef IMAGE_PROCESSOR_COLOR_H
#define IMAGE_PROCESSOR_COLOR_H

#include <vector>
#include <iostream>

class Color {
public:
    Color();
    Color(double R, double G, double B);
    Color Multiply(const std::vector<double> coeffs) const;
    Color Inverse() const;
    Color Multiply(double x) const;
    Color operator+(const Color &other) const;
    void PrintValues() const;
    double GetR() const;
    double GetG() const;
    double GetB() const;
private:
    double R_, G_, B_;
};


#endif //IMAGE_PROCESSOR_COLOR_H
