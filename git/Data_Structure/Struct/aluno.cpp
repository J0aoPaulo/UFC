#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Aluno
{
    char nome[100];
    int matricula;
    char disciplina[120];
    double nota;
};

string final(Aluno aluno) {
    if(aluno.nota >= 7) {
        return string(aluno.nome) + " aprovado(a) em " + string(aluno.disciplina);
    } else  {
        return string(aluno.nome) + " reprovado(a) em " + string(aluno.disciplina);
    }
}

int main() {
    Aluno aluno;

    cin.getline(aluno.nome, 100);
    cin >> aluno.matricula;
    cin.ignore();
    cin.getline(aluno.disciplina, 120);
    cin >> aluno.nota;

    cout << final(aluno);
}