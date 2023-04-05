#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++) {
        if(frase[i] == ' ') {
            if(frase[i - 1] == frase[i + 1]) {
                frase.erase(i --, 2);
            }
        }
    }
    cout << frase;
}