//main.cpp
#include <iostream>
#include "header.h"
#include "rectangle.cpp"

int main() {
    std::cout << std::endl;
    Shapes::Rectangle rectangle1;
    rectangle1.display();

    Shapes::Rectangle rectangle2(5, 3); 
    rectangle2.display();
    std::cout << std::endl;

    std::cout << "Area: " << rectangle2.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle2.calculatePerimeter() << std::endl;
    std::cout << "Pyramid Volume with height 4: " << rectangle2.calculatePyramidVolume(4) << std::endl;
    std::cout << std::endl;

    return 0;
}