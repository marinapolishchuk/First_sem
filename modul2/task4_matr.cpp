#include <iostream>
using namespace std;

const int size = 4;

void turn(int matr[][size]){
    int buff[size][size];
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
             buff[i][j] = matr[i][j];
        }
    }
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            matr[i][j] = buff[size - j - 1][i];
        }
    }
    
    return;
}

int main(){
    int matr[size][size] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    turn(matr);
    
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            cout << matr[i][j] << ' ';
        }
        cout << endl;
    }
}
