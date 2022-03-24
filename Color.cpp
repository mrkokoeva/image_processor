#include "Color.h"

Color::Color() {
    this->R_ = 0;
    this->G_ = 0;
    this->B_ = 0;
}

Color::Color(double R, double G, double B) {
    this->R_ = R;
    this->G_ = G;
    this->B_ = B;
}

Color Color::Multiply(const std::vector<double> coeffs) const {
    if (coeffs.size() != 3) {
        return Color();
    }
    return Color(this->R_ * coeffs[0], this->G_ * coeffs[1], this->B_ * coeffs[2]);
}

Color Color::Inverse() const {
    return Color(1 - this->R_, 1 - this->G_, 1 - this->B_);
}

Color Color::Multiply(double x) const {
    return Color(this->R_ * x, this->G_ * x, this->B_ * x);
}

Color Color::operator+(const Color &other) const {
    //может возвращать некорректный цвет :(
    return Color(this->R_ + other.R_, this->G_ + other.G_, this->B_ + other.B_);
}

void Color::PrintValues() const {
    std::cout << R_ << " " << G_ << " " << B_ << "\n";
}

double Color::GetR() const {
    return R_;
}

double Color::GetG() const {
    return G_;
}

double Color::GetB() const {
    return B_;
}


