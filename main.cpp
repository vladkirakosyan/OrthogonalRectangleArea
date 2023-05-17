#include <iostream>
#include <cmath>
#include "Polygon.h"

int main() {
    
    Polygon polygon;
    int numVertices;
    std::cout << "Enter the number of vertices (up to 12): ";
    std::cin >> numVertices;

    // Read the coordinates from std::cin
    for (int i = 0; i < numVertices; i++) {
        double x, y;
        std::cout << "Enter x" << i + 1 << ": ";
        std::cin >> x;
        std::cout << "Enter y" << i + 1 << ": ";
        std::cin >> y;
        polygon.addVertex(x, y);
    }

    // Check if the polygon is an orthogonal rectangle
    if (polygon.isOrthogonalRectangle()) {
        double area = polygon.calculateArea();
        double perimeter = polygon.calculatePerimeter();
        std::cout << "The area of the rectangle is " << area << std::endl;
        std::cout << "The perimeter of the rectangle is " << perimeter << std::endl;
    } else {
        std::cout << "The provided coordinates do not form an orthogonal rectangle." << std::endl;
        return 1;
    }
    return 0;
}
