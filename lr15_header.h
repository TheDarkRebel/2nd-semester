//header.h
#pragma once

namespace Shapes {
    class Rectangle {
    private:
        double length;
        double width;
    public:
        Rectangle();
        Rectangle(double l, double w);
        double getLength() const;
        double getWidth() const;
        void setLength(double l);
        void setWidth(double w);
        double calculateArea() const;
        double calculatePerimeter() const;
        double calculatePyramidVolume(double height) const;
        void display() const;
    };
};
