#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Aluno
{
    char nome[100];
    int matricula;
    char disciplina[120];
    double nota;
};

string maiorNota(Aluno aluno1, Aluno aluno2) {
    stringstream ss;
    
    if(aluno1.nota == aluno2.nota) {
        ss << fixed << setprecision(1) << aluno1.nota;
        return string(aluno1.nome) + " e " + string(aluno2.nome) + " , " + ss.str();
    } else if(aluno1.nota > aluno2.nota) {
        ss << fixed << setprecision(1) << aluno1.nota;
        return string(aluno1.nome) + " , " + ss.str();
    } else if(aluno1.nota < aluno2.nota) {
        ss << fixed << setprecision(1) << aluno2.nota;
        return string(aluno2.nome) + " , " + ss.str();
    }
}

int main() {
    Aluno aluno1;
    Aluno aluno2;

    cin.getline(aluno1.nome, 100);
    cin >> aluno1.matricula;
    cin.ignore();
    cin.getline(aluno1.disciplina, 120);
    cin >> aluno1.nota;
    cin.ignore();

    cin.getline(aluno2.nome, 100);
    cin >> aluno2.matricula;
    cin.ignore();
    cin.getline(aluno2.disciplina, 120);
    cin >> aluno2.nota;

    cout << maiorNota(aluno1, aluno2) << endl;
}