#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

bool eh_maiuscula(char letra) {
    if(letra >= 'A' && letra <= 'Z') return true;
    else return false;
}

string maiuscula(string frase) {
    for (int i = 0; frase[i + 1] != '\0'; i++)
    {
        if(frase[i] == ' ' || frase[i] == ',') {
            continue;
        } else if(eh_maiuscula(frase[i]) == true) {
            continue;
        } else {
            frase[i] -= 32;
        }
    }
    return frase;
}

string minuscula(string frase) {
    for (int i = 0; frase[i + 1] != '\0'; i++)
    {
        if(frase[i] == ' ' || frase[i] == ',') {
            continue;
        } else if(eh_maiuscula(frase[i]) == true) {
            frase[i] += 32;
        }
    } 
    return frase;
}

bool artigo(char letra) {
    if(letra == 'A' || letra == 'E' || letra == 'O') {
        return true;
    }
    return false;
}

string p_maiuscula(string frase) {
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if(frase[i - 1] == ' ' && frase[i + 1] == ' ') {
            continue;
        } else if(artigo(frase[0]) == true) {
            frase[0] += 32;
        } else if(frase[i] == ' ') {
            continue;
        } else if(frase[i - 1] == ' ') {
            if(eh_maiuscula(frase[i]) == true) {
                continue;
            } else frase[i] -= 32;
        }
    }
    return frase;
}

string inverter(string frase) {
    for (int i = 0; frase[i + 1] != '\0'; i++)
    {
        if(frase[i] == ' ' || frase[i] == ',') {
            continue;
        } else if(eh_maiuscula(frase[i]) == true) {
            frase[i] += 32;
        } else {
            frase[i] -= 32;
        }
    }
    return frase;
}

int main() {
    string frase;
    getline(cin, frase);
    char c;
    cin >> c;

    if(c == 'M') {
        cout << maiuscula(frase);
    } else if(c == 'm') {
        cout << minuscula(frase);
    } else if(c == 'p') {
        cout << p_maiuscula(frase);
    } else if(c == 'i') {
        cout << inverter(frase);
    }
}