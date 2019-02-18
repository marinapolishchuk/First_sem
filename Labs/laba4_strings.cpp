#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(string str) {
    for (int i = 0; i < str.size() / 2; ++i) {
        if(str[i] != str[str.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    
    string str = "madama";
    string temp;
    
    for (int i = 0; !isPalindrom(str + temp); ++i) {
        temp.insert(temp.begin(), str[i]);
    }
    cout << str + temp << endl;

    return 0;
}
