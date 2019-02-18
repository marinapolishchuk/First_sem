#include <iostream>
#include <cmath>

using namespace std;

struct Vector{
    double x;
    double y;
    
    Vector operator+(const Vector& vec) const;
    double sc_mult(const Vector& vec) const;
    Vector& turn(int degree);
    double length() const;
};

istream& operator>>(istream& istr, Vector& vec);
ostream& operator<<(ostream& ostr, const Vector& vec);

int main(){
    cout << Vector{1, 2}.sc_mult(Vector{2, -1}) << endl;
    cout << (Vector{1, 2} + Vector{2, 4}).turn(-90) << endl;
    cout << Vector{3, 4}.length() << endl;
    return 0;
}

Vector Vector::operator+(const Vector& vec) const {
    return Vector{x + vec.x, y + vec.y};
}

double Vector::sc_mult(const Vector &vec) const {
    return x * vec.x + y * vec.y;
}

Vector& Vector::turn(int degree) {
    double rad = degree * M_PI / 180;
    double tX = x, tY = y;
    x = tX * cos(rad) - tY * sin(rad);
    y = tX * sin(rad) + tY * cos(rad);
    return *this;
}

double Vector::length() const {
    return sqrt(x * x + y * y);
}

istream& operator>>(istream& istr, Vector& vec) {
    istr >> vec.x >> vec.y;
    return istr;
}

ostream& operator<<(ostream& ostr, const Vector& vec) {
    ostr << "(" << vec.x << ", " << vec.y << ")";
    return ostr;
}
