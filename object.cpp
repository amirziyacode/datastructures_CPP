#include <iostream>
#include <ostream>
using namespace std;

class Quadrilateral {
    public:
    virtual void calculateArea() const = 0;
    virtual void calculatePerimeter() const = 0;
    virtual void displaySides() const = 0;
    virtual ~Quadrilateral() = default;

};

class Square : public Quadrilateral{
    private:
       double side;
    public:
    Square(double _side) {
        setSide(_side);
    }
    void setSide(double _side) {
        if (_side > 0) {
            side = _side;
        }else {
            _side = 0;
        }
    };
    double getSide() {
        return side;
    }
    void calculateArea() const {
        double area = side * side;
        cout << "Squar's Area:" << area << endl;
    };

    void  displaySides()const {
        cout << "Square's Sides:" << side << endl;
    }

    void calculatePerimeter() const {
        double perimeter = side * 4;
        cout << "Square's Perimeter:" << perimeter << endl;
    }

};

class Rectangle : public Quadrilateral {
    private:
    double width;
    double height;
    public:
    Rectangle(double _width, double _height) {
        setWidth(_width);
        setHeight(_height);
    }
    void setWidth(double _width) {
        if (_width > 0) {
            width = _width;
        }else {
            width = 0;
        }

    }
    double getWidth() {
        return width;
    }
    void setHeight(double _height) {
        if (_height > 0) {
            height = _height;
        }else {
            height = 0;
        }

    }
    double getHeight() {
        return height;
    }
    void calculateArea()const {
        double area = width * height;
        cout << "Rectangle's Area:" << area << endl;
    };

    void displaySides()const {
        cout << "Rectangle's Sides: Width=" << width  << " Height=" << height << endl;
    }

    void calculatePerimeter() const {
        double perimeter = (width + height) * 2;
        cout << "Rectangle's Perimeter:" << perimeter << endl;
    }


};


class Trapezoid : public Quadrilateral {
    private:
    double a;
    double b;
    double c;
    double d;
    double height;
    public:
    Trapezoid(double _a, double _b,double _c,double _d, double _height) {
        setA(_a);
        setB(_b);
        setC(_c);
        setD(_d);
        setHeight(_height);
    };
    void setA(double _a) {
        if (_a > 0) {
            a = _a;
        }else {
            a = 0;
        }
    }
    double getA() {
        return a;
    }
    void setHeight(double _height) {
        if (_height > 0) {
            height = _height;
        }else {
            height = 0;
        }
    }
    double getHeight() {
        return height;
    }

    void setB(double _b) {
        if (_b > 0) {
            b = _b;
        }else {
            b = 0;
        }
    }
    double getB() {
        return b;
    }

    void setC(double _c) {
        if (_c > 0) {
            c = _c;
        }else {
            c = 0;
        }
    }

    double getC() {
        return c;
    }

    void setD(double _d) {
        if (_d > 0) {
            d = _d;
        }else {
            d = 0;
        }
    }

    double getD() {
        return d;
    }

    void calculateArea()const {
        double area = (a+b) * height/2;
        cout << "Trapezoid's Area:" << area << endl;
    }

    void displaySides()const {
        cout << "Trapezoid's Sides : Small diameter=" << a << " Big diameter=" << b << " height=" << height << endl;
    }

    void calculatePerimeter() const {
        double perimeter = a+b+c+d;

        cout << "Trapezoid's Perimeter:" << perimeter << endl;
    }
};


int main() {


    Square squar(10);
    Square squar2(5);
    Square square4(40);
    Square squar3 (5);
    Rectangle rectangle (10,5);
    Rectangle rectangle2 (14,10);
    Rectangle rectangle3 (20,10);
    Trapezoid trap  (10,30,20,15,10);
    Trapezoid trap2 (12,27,20,15,15);
    Trapezoid trap3 (5,20,15,8,9);



    cout << "============ Sides =========== " << endl;
    squar.displaySides();
    squar2.displaySides();
    squar3.displaySides();
    square4.displaySides();

    rectangle.displaySides();
    rectangle2.displaySides();
    rectangle3.displaySides();

    trap.displaySides();
    trap2.displaySides();
    trap3.displaySides();

    cout << "============ calculateArea =========== " << endl;
    squar.calculateArea();
    squar2.calculateArea();
    squar3.calculateArea();

    rectangle.calculateArea();
    rectangle2.calculateArea();
    rectangle3.calculateArea();

    trap.calculateArea();
    trap2.calculateArea();
    trap3.calculateArea();

    cout << "============ calculatePerimeter ===========" << endl;
    squar.calculatePerimeter();
    squar2.calculatePerimeter();
    squar3.calculatePerimeter();


    rectangle.calculatePerimeter();
    rectangle2.calculatePerimeter();
    rectangle3.calculatePerimeter();

    trap.calculatePerimeter();
    trap2.calculatePerimeter();
    trap3.calculatePerimeter();




    return 0;
}