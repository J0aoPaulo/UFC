#include <iostream>
#include <sstream>
using namespace std;

bool negativo(string palavra) {
    for (auto str : palavra)
    {
        if(str == '-') {
            return true;
        }
    }
    return false;
}

bool str(string palavra) {
    for (auto str : palavra)
    {
        if(str >= 'a' && str <= 'z' || (str >= 'A' && str <= 'Z')) {
            return true;
        }
    }
    return false;
}

bool p_flutuante(string palavra) {
    for (auto str : palavra)
    {
        if(str == '.') {
            return true;
        } 
    }
    return false;
}

int main() {
    string frase, palavra;
    getline(cin, frase);
    stringstream ss;
    string out;
    ss << frase;

    while (ss >> palavra)
    {
        if(str(palavra) == true) {
            out += "str ";
        } else if(p_flutuante(palavra) == true) {
            out += "float ";
        } else {
            out += "int ";
        }
    }
    out.pop_back();
    cout << out;
}