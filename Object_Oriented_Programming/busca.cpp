#include <fn.hpp>
#include <algorithm>
#include <string>

class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number= "") : id{id}, number{number} {}
    std::string getId() {
        return id;
    }
    std::string getNumber() {
        return number;
    }
    String mod = "modificação necessaria";
    bool isValid() {
        bool isValid = true;

        for (char elemen : number) {
            if(std::isalpha(elemen)) {
                isValid = false;
                return false;
            } 
        }
        return true;
    }
    std::string str() {
        return fn::format("{}:{}", id, number);
    }   
};

class Contact{
    std::string name;
    bool favorited;
    std::vector<Fone> fones;
public:
    Contact(std::string name = "") : name{name}, favorited{false} {
        fones;
    }

    std::string getName() {
        return name;
    }

    std::vector<Fone> getFones() {
        return fones;
    }

    void addFone(std::string id, std::string number) {
        Fone fone(id, number);

        if(fone.isValid()) {
            fones.push_back(fone);
        } else {
            fn::write("fail: invalid number");
        }
    }

    void rmFone(int index) {
        if(index <= fones.size()) {
            fones.erase(fones.begin() + index);
        }
    }

    void toogleFavorited() {
        if(isFavorited())
            favorited = false;
        else 
            favorited = true;
    }

    bool isFavorited() {
        if(favorited)
            return true;
        else 
            return false;
    }

    std::string str() {
        std::stringstream ss;

        if(isFavorited()) {
            ss << "@ " << getName() << " [";
        } else {
            ss << "- " << getName() << " [";
        }

        for (int i = 0; i < fones.size(); i++) {
            if(i == fones.size() - 1) {
                ss << fones[i].str();
            } else {
                ss << fones[i].str() << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }
};

class Agenda {
    std::vector<Contact> contatos;

    int findContact(std::string id) {
        for (int i = 0; i < contatos.size(); i++) {
            if(contatos[i].getName() == id) {
                return i;
            }
        }
        return -1;
    }

public:
    //add contato que não existe ou adicionar fones ao contato que existe
    void addContato(std::string name, std::vector<Fone> fones) {
        int index = findContact(name);

        if(index != -1) {
            for (int i = 0; i < fones.size(); i++) {
                contatos[index].addFone(fones[i].getId(), fones[i].getNumber());
            }
        } else {
            Contact newContact(name);

            for (int i = 0; i < fones.size(); i++) {
                newContact.addFone(fones[i].getId(), fones[i].getNumber());
            }
            contatos.push_back(newContact);
            std::sort(contatos.begin(), contatos.end(), [](auto a, auto b) {return a.getName() < b.getName();});
        }
    }

    void rmContact(std::string name) {
        int index = findContact(name);

        if(index != -1) {
            contatos.erase(contatos.begin() + index);
        }
    }

    Contact * getContact(std::string id) {
        int index = findContact(id);

        if (index != -1) {
            return &contatos[index];
        }
        return nullptr;
    }

    std::vector<Contact> getContatos() {
        return contatos;
    }

    std::vector<Contact> search(std::string pattern) {
        std::vector<Contact> result;

        for (auto &&contato : contatos) {
            if(contato.str().find(pattern) != std::string::npos) {
                result.push_back(contato);
            }
        }
        return result;
    }

    std::vector<Contact> getFavorited() {
        std::vector<Contact> favoritedList;

        for (auto &&contato : contatos) {
            if(contato.isFavorited()) {
                favoritedList.push_back(contato);
            }
        }
        return favoritedList;
    }

    std::string str() {
        std::stringstream ss;

        for (int i = 0; i < contatos.size(); i++) {
            if(i == contatos.size() - 1) 
                ss << contatos[i].str();
            else 
                ss << contatos[i].str() << std::endl;   
        }
        return ss.str();
    }
};


std::ostream& operator<<(std::ostream& out, Fone fone      ) { return out << fone.str();    }
std::ostream& operator<<(std::ostream& out, Contact contato) { return out << contato.str(); }
std::ostream& operator<<(std::ostream& out, Agenda agenda  ) { return out << agenda.str();  }

int main() {
    Agenda agenda;
    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line, ' ');
        if(args[0] == "end") {
            break;
        }
        else if(args[0] == "add") {//name id:fone id:fone ...
            std::vector<Fone> fones;
            for (int i = 2; i < (int) args.size(); i++) {
                auto parts = fn::split(args[i], ':');
                fones.push_back(Fone(parts[0], parts[1]));
            }
            agenda.addContato(args[1], fones);
        }
        else if(args[0] == "show") {
            fn::write(agenda);
        }
        else if(args[0]== "rmFone") {//id index
            Contact * contato = agenda.getContact(args[1]);
            if(contato != nullptr)
                contato->rmFone((int) +args[2]);
        }
        else if(args[0] == "rm") {//id
            agenda.rmContact(args[1]);
        }
        else if(args[0] == "tfav") {//id 1 ou 0
            Contact * contato = agenda.getContact(args[1]);
            if(contato != nullptr)
                contato->toogleFavorited();
        }
        else if(args[0] == "favs") {
            agenda.getFavorited() | fn::JOIN("\n") | fn::WRITE();
        }
        else if(args[0] == "search") {//pattern
            agenda.search(args[1]) | fn::JOIN("\n") | fn::WRITE();
        }
        else{
            fn::write("fail: comando invalido");
        }
    }
}