#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Sum(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 >= n2) {
        swap(s1, s2);
        swap(n1, n2);
    }
    string s3;
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    int left = 0;
    for (int i = 0; i < n1; i++) {
        int sum = ((s1[i] - '0') + (s2[i] - '0') + left);
        s3.push_back(sum % 10 + '0');
        left = sum / 10;
    }
    for (int i = n1; i < n2; i++) {
        int sum = ((s2[i] - '0') + left);
        s3.push_back(sum % 10 + '0');
        left = sum / 10;
    }
    
    if (left != 0)
        s3.push_back(left + '0');
        reverse(s3.begin(), s3.end());
        return s3;
    
}

int main() {
    string s1, s2;
    cout << "Enter two numbers " << endl;
    cin >> s1 >> s2;
    cout << "The sum is " << Sum(s1, s2) << endl;
    return 0;
}
