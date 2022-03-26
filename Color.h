#pragma once

#include <vector>
#include <iostream>

class Color {
public:
    Color();
    Color(double red, double green, double blue);
    Color Multiply(const std::vector<double> coeffs) const;
    Color Inverse() const;
    Color Multiply(double x) const;
    Color operator+(const Color &other) const;
    void PrintValues() const;
    double GetRed() const;
    double GetGreen() const;
    double GetBlue() const;
private:
    double red_, green_, blue_;
};
