#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

class Disciplina; // Declaração antecipada da classe Disciplina

class Aluno {
    std::string id;
    std::map<std::string, Disciplina*> disciplinas;

public:
    Aluno(const std::string& id) : id(id) {}

    std::string getId() const {
        return id;
    }

    std::vector<Disciplina*> getDisciplinas() const;

    void addDisciplina(Disciplina* disciplina);

    void removeDisciplina(const std::string& disciplinaId);
};

class Sistema;

std::ostream& operator<<(std::ostream& os, const Sistema& sistema);

class Disciplina {
    std::string id;
    std::map<std::string, Aluno*> alunos;

public:
    Disciplina(const std::string& id) : id(id) {}

    std::string getId() const {
        return id;
    }

    std::vector<Aluno*> getAlunos() const;

    void addAluno(Aluno* aluno);

    void removeAluno(const std::string& alunoId);
};

std::vector<Disciplina*> Aluno::getDisciplinas() const {
    std::vector<Disciplina*> vetorDisciplinas;
    for (const auto& elemen : disciplinas) {
        vetorDisciplinas.push_back(elemen.second);
    }
    return vetorDisciplinas;
}

void Aluno::addDisciplina(Disciplina* disciplina) {
    disciplinas[disciplina->getId()] = disciplina;
    disciplina->addAluno(this);
}

void Aluno::removeDisciplina(const std::string& disciplinaId) {
    if (disciplinas.count(disciplinaId)) {
        Disciplina* disciplina = disciplinas[disciplinaId];
        disciplinas.erase(disciplinaId);
        disciplina->removeAluno(id);
    }
}

std::vector<Aluno*> Disciplina::getAlunos() const {
    std::vector<Aluno*> vetorAlunos;
    for (const auto& elemen : alunos) {
        vetorAlunos.push_back(elemen.second);
    }
    return vetorAlunos;
}

void Disciplina::addAluno(Aluno* aluno) {
    alunos[aluno->getId()] = aluno;
    aluno->addDisciplina(this);
}

void Disciplina::removeAluno(const std::string& alunoId) {
    if (alunos.count(alunoId)) {
        alunos[alunoId]->removeDisciplina(id);
        alunos.erase(alunoId);
    }
}

class Sistema {
    std::map<std::string, Disciplina*> disciplinas;
    std::map<std::string, Aluno*> alunos;

public:
    std::vector<Disciplina*> obterDisciplinas() const;

    std::vector<Aluno*> obterAlunos() const;

    void adicionarAluno(const std::string& idAluno);

    void adicionarDisciplina(const std::string& idDisciplina);

    void matricular(const std::string& idAluno, const std::string& idDisciplina);

    void desmatricular(const std::string& idAluno, const std::string& idDisciplina);

    void removerAluno(const std::string& idAluno);

    void removerDisciplina(const std::string& idDisciplina);

    friend std::ostream& operator<<(std::ostream& os, const Sistema& sistema);
};

std::vector<Disciplina*> Sistema::obterDisciplinas() const {
    std::vector<Disciplina*> disciplinasVec;
    for (const auto& par : disciplinas) {
        disciplinasVec.push_back(par.second);
    }
    return disciplinasVec;
}

std::vector<Aluno*> Sistema::obterAlunos() const {
    std::vector<Aluno*> alunosVec;
    for (const auto& par : alunos) {
        alunosVec.push_back(par.second);
    }
    return alunosVec;
}

void Sistema::adicionarAluno(const std::string& idAluno) {
    if (!alunos.count(idAluno)) {
        Aluno* aluno = new Aluno(idAluno);
        alunos[idAluno] = aluno;
    }
}

void Sistema::adicionarDisciplina(const std::string& idDisciplina) {
    if (!disciplinas.count(idDisciplina)) {
        Disciplina* disciplina = new Disciplina(idDisciplina);
        disciplinas[idDisciplina] = disciplina;
    }
}

void Sistema::matricular(const std::string& idAluno, const std::string& idDisciplina) {
    if (alunos.count(idAluno) && disciplinas.count(idDisciplina)) {
        Aluno* aluno = alunos[idAluno];
        Disciplina* disciplina = disciplinas[idDisciplina];
        aluno->addDisciplina(disciplina);
    }
}

void Sistema::desmatricular(const std::string& idAluno, const std::string& idDisciplina) {
    if (alunos.count(idAluno) && disciplinas.count(idDisciplina)) {
        Aluno* aluno = alunos[idAluno];
        aluno->removeDisciplina(idDisciplina);
    }
}

void Sistema::removerAluno(const std::string& idAluno) {
    if (alunos.count(idAluno)) {
        Aluno* aluno = alunos[idAluno];
        std::vector<Disciplina*> disciplinasAluno = aluno->getDisciplinas();
        for (Disciplina* disciplina : disciplinasAluno) {
            disciplina->removeAluno(idAluno);
        }
        alunos.erase(idAluno);
        delete aluno;
    }
}

void Sistema::removerDisciplina(const std::string& idDisciplina) {
    if (disciplinas.count(idDisciplina)) {
        Disciplina* disciplina = disciplinas[idDisciplina];
        std::vector<Aluno*> alunosDisciplina = disciplina->getAlunos();
        for (Aluno* aluno : alunosDisciplina) {
            aluno->removeDisciplina(idDisciplina);
        }
        disciplinas.erase(idDisciplina);
        delete disciplina;
    }
}

std::ostream& operator<<(std::ostream& os, const Sistema& sistema) {
    os << "- alunos\n";
    for (const auto& par : sistema.obterAlunos()) {
        os  << par->getId() << " []\n";
    }
    os << "- discps\n";
    for (const auto& par : sistema.obterDisciplinas()) {
        os << par->getId() << " []\n";
    }
    return os;
}

int main(){
    std::string line, cmd;
    Sistema sistema;
    while(true){
        try{
            getline(std::cin, line);
            std::cout << "$" << line << '\n';
            std::stringstream ss(line);
            std::vector<std::string> ui(std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>());
            std::string cmd = ui[0];
            if(cmd == "end"){
                break;
            }else if(cmd == "nwalu"){
                for(size_t i = 1; i < ui.size(); i++)
                    sistema.adicionarAluno(ui[i]);
            }else if(cmd == "nwdis"){
                for(size_t i = 1; i < ui.size(); i++)
                    sistema.adicionarDisciplina(ui[i]);
            }else if(cmd == "show"){
                std::cout << sistema;
            }else if(cmd == "tie"){
                for(size_t i = 2; i < ui.size(); i++)
                    sistema.matricular(ui[1], ui[i]);
            }else if(cmd == "untie"){
                for(size_t i = 2; i < ui.size(); i++)
                    sistema.desmatricular(ui[1], ui[i]);
            }else if(cmd == "rmalu"){
                sistema.removerAluno(ui[1]);
            }else{
                std::cout << "comando invalido " << "[" << cmd << "]\n";
            }
        }catch(std::string e){
            std::cout << e << '\n';
        }
    }
}
