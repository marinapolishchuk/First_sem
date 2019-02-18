#include <iostream>
#include <cmath>
#include <vector>
//Розкласти в ланцюговий дріб введене користувачем дійсне число
using namespace std;
#define EPS 1e-6

int main() {
    
    double num;
    cout << "Enter the number: ";
    cin >> num;
    
    int integralPart = num;
    double fractionPart = num - integralPart;
    vector<int> vecResult;
    
    while (abs(fractionPart)>EPS) {
        integralPart = num;
        vecResult.push_back(integralPart);
        fractionPart = num - integralPart;
        num = 1 / fractionPart;
    }
    
    cout << "{ ";
    for (auto a : vecResult) { cout << a << " "; }
    cout << "}" << endl;
    
    return 0;
}

