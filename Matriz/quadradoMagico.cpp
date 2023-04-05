#include <iostream>
using namespace std;

int horizontal(int vector[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += vector [0][i];
    }
    return sum;
}

int vertical(int vector[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += vector [i][0];
    }
    return sum;
}

int diagonal(int vector[3][3]){
    int lin = 0, sum = 0;
    for (int i = 0; i < 3; i++){
        sum += vector[i][lin++];
    }
    return sum;
}

int main(){
    
    int a, b, c, vector[3][3];
    
    for (int i = 0; i < 3; i++) {
        cin >> vector[i][0];
        cin >> vector[i][1];
        cin >> vector[i][2];
    }
    
    if (horizontal(vector) == vertical(vector) && vertical(vector) == diagonal(vector)) {
        cout << "sim" << endl;
    } else cout << "nao" << endl;
}