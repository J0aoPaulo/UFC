#include <iostream>
using namespace std;

int main(){
    int n1 = 0, n2 = 0, cont = 0;
    
    cin >> n1;
    cin >> n2;
    
    int vector[n1][n2];
    
    for (int i = 0; i < n1; i++) {
        for (int j =0; j < n2; j++) {
            cin >> vector[i][j];
        }
    }
    
    for (int j = 0; j < n2; j++) {
            for (int i = 0; i < n1 - 1; i++) {
            if (vector[i][j] > vector[i + 1][j]){
                cont++;
            }
        }
    }
    cout << cont;
}