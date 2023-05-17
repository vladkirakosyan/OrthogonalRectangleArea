#include "Polygon.h"
#include <cmath>

void Polygon::addVertex(double x, double y) {
    xCoordinates.push_back(x);
    yCoordinates.push_back(y);
}

double Polygon::calculateArea() const {
    double area = 0.0;
    int n = xCoordinates.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += xCoordinates[i] * yCoordinates[j];
        area -= xCoordinates[j] * yCoordinates[i];
    }
    return 0.5 * std::abs(area);
}

bool Polygon::isOrthogonalRectangle() const {
   size_t n = xCoordinates.size();
    if (n < 4) {
        return false;
    }

    double xDiff = std::abs(xCoordinates[1] - xCoordinates[0]);
    double yDiff = std::abs(yCoordinates[1] - yCoordinates[0]);
    bool isOrthogonal = (xDiff == 0 && yDiff != 0) || (xDiff != 0 && yDiff == 0);
    if (!isOrthogonal) return false;

    for (size_t i = 2; i < n; ++i) {
        double currentXDiff = std::abs(xCoordinates[i] - xCoordinates[i - 1]);
        double currentYDiff = std::abs(yCoordinates[i] - yCoordinates[i - 1]);
        isOrthogonal = (currentXDiff == 0 && currentYDiff != 0) || (currentXDiff != 0 && currentYDiff == 0);
        if (!isOrthogonal) {
            return false;
        }
    }
    return true;
}

double Polygon::calculatePerimeter() const {
    double perimeter = 0.0;
    int n = xCoordinates.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        double dx = xCoordinates[j] - xCoordinates[i];
        double dy = yCoordinates[j] - yCoordinates[i];
        perimeter += std::sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}
