#include <fn.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

class Point2D {
public:
    double x;
    double y;

    std::string str() {
        return fn::format("({%.2f}, {%.2f})", x, y);
    }
};

struct Calc {
    static double pointDistance(const Point2D& a, const Point2D& b) {
        return std::sqrt(pow(b.y - a.x, 2) + pow(b.y - a.y, 2));
    }
};

class Shape {
    std::string name;
public:
    Shape(const std::string& name) : name(name) {}

    virtual std::string getName() {
        return name;
    }

    virtual bool inside(const Point2D& point) = 0;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    virtual std::string str() = 0;
};

class Circle : public Shape {
    Point2D center;
    double radius;   
public:
    Circle(const Point2D& center, double radius) : Shape("Circ"),
    center (center), radius(radius) {}

    bool inside(const Point2D& point) override {
        double distance = Calc::pointDistance(point, center);
        return distance <= radius;
    }

    double getArea() override {
        return M_PI * pow(radius, 2);
    }

    double getPerimeter() override {
        return 2 * M_PI * radius;
    }

    std::string str() override {
        return fn::format("Circ: C={}, R={%.2f}", center.str(), radius);
    }
};

class Rectangle : public Shape {
    Point2D P1;
    Point2D P2;
public:
    Rectangle(const Point2D& P1, const Point2D& P2) :  Shape("Rect"), P1(P1), P2(P2) {}
    
    bool inside(const Point2D& point) override {
        return point.x >= P1.x && point.x <= P2.x && point.y >= P1.y && point.y <= P2.y;
    }

    double getArea() override{
        double base = P2.x - P1.x;
        double alt = P2.y - P1.y;
        return std::abs(base * alt);
    } 

    double getPerimeter() override{
        double base = P2.x - P1.x;
        double alt = P2.y - P1.y;
        return std::abs(2 * (base + alt));
    }

    std::string str() override{
        return fn::format("Rect: P1={} P2={}", P1.str(), P2.str());
    }
};

int main() {
    std::vector<std::shared_ptr<Shape>> shapes;

    while (true) {
        auto line = fn::input();
        auto args =  fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")  { 
            break;                                  
        }
        else if (args[0] == "show") { 
            shapes | fn::MAP([](auto shape){ return shape->str(); })
             | fn::JOIN("\n")
             | fn::WRITE();
        }
        else if (args[0] == "circle") { 
            auto x = +args[1];
            auto y = +args[2]; 
            auto r = +args[3];
            shapes.push_back(std::make_shared<Circle>(Point2D{x, y}, r));
        }
        else if (args[0] == "rect") { 
            auto p1 = Point2D{+args[1], +args[2]};
            auto p2 = Point2D{+args[3], +args[4]};
            shapes.push_back(std::make_shared<Rectangle>(p1, p2));
        }
        else if (args[0] == "info") {
            for (auto shape : shapes) {
                fn::print("{}: A={%.2f} P={%.2f}\n", 
                shape->getName(), shape->getArea(), shape->getPerimeter());
            }
        }
        else {
            fn::write("fail: invalid command");
        }
    }
}