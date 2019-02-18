// 2^N while N < 1000
#include <iostream>
using namespace std;

int main () {
    
    int pow;
    cout << "Enter the pow " << endl;
    cin >> pow;
    
    if (pow < 1000) {
        
        long double num = 2;
        
        for (int i = 1; i < pow; i++) {
            num *= 2;
        }
        
        cout << "2 to the power of " << pow << " is " << num << endl;
       
    } else {
        cout << "Pow needs to be less than 1000." << endl;
    }
    
    return 0;
}
