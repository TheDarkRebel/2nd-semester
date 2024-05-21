//rectangle.cpp
#include "header.h"
#include <iostream>

namespace Shapes {
    Rectangle::Rectangle() : length(0), width(0) {}

    Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

    double Rectangle::getLength() const {
        return length;
    }

    double Rectangle::getWidth() const {
        return width;
    }

    void Rectangle::setLength(double l) {
        length = l;
    }

    void Rectangle::setWidth(double w) {
        width = w;
    }

    double Rectangle::calculateArea() const {
        return length * width;
    }

    double Rectangle::calculatePerimeter() const {
        return 2 * (length + width);
    }

    double Rectangle::calculatePyramidVolume(double height) const {
        return (length * width * height) / 3.0;
    }

    void Rectangle::display() const {
        std::cout << "Rectangle: Length = " << length << ", Width = " << width << std::endl;
    }
}
