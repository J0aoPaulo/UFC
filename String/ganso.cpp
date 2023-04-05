#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int qtd = 1;
    stringstream ss;
    string frase, aux = {' '}, fodase;
    bool x;
    getline(cin, frase);
    ss << frase;

    while (ss >> fodase)
    {
        if(fodase >= aux){
            x = true;
            aux = fodase;
        } else {
            x = false;
            break;
        }
    }
    if(x == true) cout << "sim";
    else cout << "nao";
}