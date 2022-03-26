#include "Color.h"

Color::Color() : red_(0), green_(0), blue_(0) {}

Color::Color(double red, double green, double blue) : red_(red), green_(green), blue_(blue) {}

Color Color::Multiply(const std::vector<double> coeffs) const {
    if (coeffs.size() != 3) {
        return Color();
    }
    return Color(this->red_ * coeffs[0], this->green_ * coeffs[1], this->blue_ * coeffs[2]);
}

Color Color::Inverse() const {
    return Color(1 - this->red_, 1 - this->green_, 1 - this->blue_);
}

Color Color::Multiply(double x) const {
    return Color(this->red_ * x, this->green_ * x, this->blue_ * x);
}

Color Color::operator+(const Color &other) const {
    //может возвращать некорректный цвет :(
    return Color(this->red_ + other.red_, this->green_ + other.green_, this->blue_ + other.blue_);
}

void Color::PrintValues() const {
    std::cout << red_ << " " << green_ << " " << blue_ << "\n";
}

double Color::GetRed() const {
    return red_;
}

double Color::GetGreen() const {
    return green_;
}

double Color::GetBlue() const {
    return blue_;
}


