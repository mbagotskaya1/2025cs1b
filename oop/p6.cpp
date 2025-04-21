#include<iostream> 
using namespace std; 

class Point {
    private:
    int x;
    int y;

    public:
    Point(int x, int y) : x(x), y(y) {};
    Point() : x(0), y(0) {};
    void displayPoint() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
};

class Circle {
    private:
    Point center;
    double radius;

    public:
    Circle (Point c, double r) : center(c), radius(r < 0 ? 1.0 : r) {}
    Circle (int x, int y, double r) : center(Point(x, y)), radius(r < 0 ? 1.0 : r) {}
    double getArea() const {
        return 3.1415 * radius * radius;
    }
    void displayCircle() const {
        cout << "center: \n";
        center.displayPoint();

    }
};

int main() {
    Point p;
    p.displayPoint();

    Circle c1(2, 2, 5);
    c1.displayCircle();
    Circle c2(p, 10);
    c2.displayCircle();
    Circle c3(2, 2, -5);
    c3.displayCircle();
}