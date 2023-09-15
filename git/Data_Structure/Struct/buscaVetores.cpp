#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

struct Aluno
{
    int matricula;
    char nome[100];
    float media;
};

string print(Aluno aluno[], int numMatricula, int n) {
    stringstream ss;

    for (int i = 0; i < n; i++)
    {
        if(aluno[i].matricula == numMatricula) {
            ss << fixed << setprecision(1) << aluno[i].media;
            return string(aluno[i].nome) + "\n" + ss.str(); 
        }
    }
    return string("NAO ENCONTRADA");
}

int main() {    
    int n;
    cin >> n;
    Aluno aluno[n];

    for (int i = 0; i < n; i++)
    {
        cin >> aluno[i].matricula;
        cin.ignore();
        cin.getline(aluno[i].nome, 100);
        cin >> aluno[i].media;
    }

    int numMatricula;
    cin >> numMatricula;

    cout << print(aluno, numMatricula, n);
}