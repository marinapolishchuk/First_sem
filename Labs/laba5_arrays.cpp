#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
// Дано послідовність, елементами якої є цілі числа. Знайти максимальну зростаючу підпослідовність цієї послідовності (елементи не обов'язково мають бути розташовані підряд).

int main() {
    
    const int size = 8;
    int arr[size] = {5, 10, 4, 12, 13, 24, 7, 6};
    int max[size] = {1, 1, 1, 1, 1, 1, 1, 1};

    for (int j = 1; j < size; j++) {
       for (int i = 0; i < j; i++) {
            if(arr[j] > arr[i]) {
                if(max[j] <= max[i]) { max[j] = max[i] + 1; }
            }
       }
    }
    
    /* for (int i = 0; i < size; i++) {
        cout << max[i] << " ";
    } */
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int maxLength = max[0];
    for (int i = 0; i < size; i++) {
        if(maxLength < max[i]) maxLength = max[i];
    }
    
    vector<int> vecSubArr;
    int t = maxLength;
    for (int i = size - 1; i >= 0 ; i--) {
        if (max[i] == t) {
            vecSubArr.insert(vecSubArr.begin(), arr[i]);
            t--;
        }
    }
    copy(vecSubArr.begin(), vecSubArr.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    return 0;
}
