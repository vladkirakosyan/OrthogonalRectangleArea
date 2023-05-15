#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double polygonArea(const std::vector<Point>& polygon) {
    double area = 0.0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y;
        area -= polygon[j].x * polygon[i].y;
    }
    return 0.5 * abs(area);
}

double polygonPerimeter(const std::vector<Point>& polygon) {
    double perimeter = 0.0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += distance(polygon[i], polygon[j]);
    }
    return perimeter;
}

int main() {
    std::vector<Point> polygon = {{0.0, 0.0}, {6.0, 0.0}, {6.0, 2.0}, {4.0, 2.0}, {4.0, 4.0}, {1.0, 4.0}, {1.0, 3.0}, {0.0, 3.0}};
    double perimeter = polygonPerimeter(polygon);
    std::cout << "The perimeter of the polygon is " << perimeter << std::endl;
    double area = polygonArea(polygon);
    std::cout << "The area of the polygon is " << area << std::endl;
    return 0;
}
