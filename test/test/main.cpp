#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int priority(char operation) {
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    if (operation == '^') return 3;
    return 0;
}

string polishNotation(string standartNot) {
    string result = "";
    stack<char> operations;
    
    for (int i = 0; i < standartNot.length(); ++i) {
        
        if (standartNot[i] == '(') {
            operations.push(standartNot[i]);
            continue;
        }
        
        if (standartNot[i] == ')') {
            while (operations.top() != '(') {
                result.push_back(operations.top());
                operations.pop();
            }
            operations.pop();
            continue;
        }
        if (standartNot[i] >= '0' && standartNot[i] <= '9') {
            result.push_back(standartNot[i]);
        }
        
        else {
            if (operations.empty() || priority(standartNot[i]) >= priority(operations.top())) {
                operations.push(standartNot[i]);
            }
            else {
                while (priority(standartNot[i]) < priority(operations.top())) {
                    operations.push(standartNot[i]);
                    result.push_back(operations.top());
                    operations.pop();
                    continue;
                }
            }
        }
    }
    while (!operations.empty()) {
        result.push_back(operations.top());
        operations.pop();
    }
    
    return result;
}

int getResult(string S) {
    int i;
    stack<int>nums;
    
    for (i = 0; i < S.size(); i++) {
        if (S[i] >= '0' && S[i] <= '9') {
            nums.push(S[i] - '0');
            
        }
        else {
            int a, b, c;
            a = nums.top(); nums.pop();
            b = nums.top(); nums.pop();
            switch (S[i]) {
                    
                case '+': c = a + b; break;
                case '-': c = b - a; break;
                case '*': c = a*b; break;
                case '/': c = b / a; break;
                case '^': c = pow(b, a); break;
                    
            }
            nums.push(c);
        }
    }
    
    return nums.top();
}


int main() {
    string standart;
    cout << "Enter string in traditional notation: ";
    cin >> standart;
    string polish = polishNotation(standart);
    int result = getResult(polish);
    cout << "Polish notation: " << polish << endl;
    cout << "The result is: " << result << endl;
    return 0;
}

