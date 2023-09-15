#include <fn.hpp>


class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number = "") : id{id}, number{number} {}

    std::string getId() {
        return id;
    }
    std::string getNumber() {
        return number;
    }
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

std::ostream& operator<<(std::ostream& out, Contact contato) { return out << contato.str(); }
std::ostream& operator<<(std::ostream& out, Fone fone      ) { return out << fone.str();    }


int main() {
    Contact contato;
    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line, ' ');

        if(args[0] == "end") {
            break;
        }
        else if(args[0] == "init") {//name
            contato = Contact(args[1]);
        }
        else if(args[0] == "add") {//id fone
            contato.addFone(args[1], args[2]);
        }
        else if(args[0] == "rm") {//id
            contato.rmFone(+args[1]);
        }
        else if(args[0] == "tfav") {
            contato.toogleFavorited();
        }
        else if(args[0] == "show") {
            fn::write(contato);
        }
        else {
            fn::write("fail: comando invalido");
        }
    }
}