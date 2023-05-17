#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

class Polygon {
public:
    Polygon() = default;
    void addVertex(double x, double y);
    double calculatePerimeter() const;
    double calculateArea() const;
    bool isOrthogonalRectangle() const;
    
private:
    std::vector<double> xCoordinates;
    std::vector<double> yCoordinates;
};

#endif  // POLYGON_H
