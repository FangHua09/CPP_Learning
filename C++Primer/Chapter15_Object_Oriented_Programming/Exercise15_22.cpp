/*
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <numeric>
#include <bitset>
#include <climits>
#include <functional>
#include <iterator>
#include <memory>
using namespace std;

class Shape
{
public:
    Shape() = default;
    // 2D
    Shape(double x, double y) : x(x), y(y) {}
    // 3D
    Shape(double x, double y, double z) : x(x), y(y), z(z) {}
    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual void debug() const = 0;
    virtual ~Shape() = default;

protected:
    // 圆心坐标(x, y) 中心点z
    double x = 0, y = 0, z = 0;
};

// 圆：2D
class Circle : public Shape
{
public:
    Circle(double cx, double cy, double r) : Shape(cx, cy), radius(r) {}

    double area() const override { return 3.14159 * radius * radius; }
    double volume() const override { return 0.0; }
    void debug() const override
    {
        cout << "Circle: center(" << x << "," << y << "), radius=" << radius << endl;
    }

private:
    double radius;
};

// 矩形2D
class Rectangle : public Shape
{
public:
    Rectangle(double cx, double cy, double w, double h) : Shape(cx, cy), width(w), height(h) {}

    double area() const override { return width * height; }
    double volume() const override { return 0.0; }
    void debug() const override
    {
        cout << "Rectangle: center(" << x << "," << y << "), w=" << width << ", h=" << height << endl;
    }

private:
    double width, height;
};

// 球体3D
class Sphere : public Shape
{
public:
    Sphere(double cx, double cy, double cz, double r) : Shape(cx, cy, cz), radius(r) {}

    double area() const override { return 4 * 3.14159 * radius * radius; }
    double volume() const override { return (4.0 / 3.0) * 3.14159 * radius * radius * radius; }
    void debug() const override
    {
        cout << "Sphere: center(" << x << "," << y << "," << z << "), radius=" << radius << endl;
    }

private:
    double radius;
};

// 圆锥3D
class Cone : public Shape
{
public:
    Cone(double cx, double cy, double cz, double r, double h) : Shape(cx, cy, cz), radius(r), height(h) {}

    double area() const override
    {
        return 3.14159 * radius * (radius + sqrt(radius * radius + height * height));
    }
    double volume() const override { return (1.0 / 3.0) * 3.14159 * radius * radius * height; }
    void debug() const override
    {
        cout << "Cone: center(" << x << "," << y << "," << z << "), radius=" << radius << ", height=" << height << endl;
    }

private:
    double radius, height;
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
