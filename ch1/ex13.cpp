#include <iostream>
using namespace std;

class shape {
public:
    virtual double area() = 0;
};

class triangle : public shape {
public:
    triangle(double base, double height) {
        attr_base = base;
        attr_height = height;
    }
    
    double area() { return (attr_base * attr_height) / 2; }
private:
    double attr_base;
    double attr_height;
};

int main() {
    triangle tri(3, 4);
    
    cout << "Area of \'tri\': " << tri.area() << endl;
    
    return 0;
}
