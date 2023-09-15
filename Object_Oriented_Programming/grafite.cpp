#include <iostream>
#include <sstream>
#include <memory>  //sharedptr
#include <iomanip> //setprecision
#include <utility> //exchange
#include <fn.hpp>
using namespace std;

class Lead {
float thickness;
std::string hardness;
int size;

public:
Lead(float thickness, std::string hardness, int size) {
    this->thickness = thickness;
    this->hardness = hardness;
    this->size = size;
}
git fodase = mod;

int usagePerSheet() const {
    if (hardness == "HB")
        return getSize() - 1;
    else if (hardness == "2B")
        return getSize() - 2;
    else if (hardness == "4B")
        return getSize() - 4;
    else 
    return getSize() - 6;
}

float getThickness() const {
    return thickness;
}

std::string getHardness() const {
    return hardness;
}

int getSize() const {
    return size;
}

void setSize(int size) {
    this->size = size;
}

void setThickness(float thickness) {
    this->thickness = thickness;
}
std::string str() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) 
        << thickness << ":" << hardness << ":" << size;
    return ss.str();
}
};

std::ostream& operator<<(std::ostream& ss, Lead gr) {
return ss << gr.str();
}

struct Pencil {
float thickness {0.f};
std::shared_ptr<Lead> tip {nullptr};

Pencil(float thickness = 0.0) :
thickness {thickness} {
}

bool hasGrafite() {
    if(tip != nullptr) {
        return true;
    } else {
        return false;
    }
}

bool insert(std::shared_ptr<Lead> grafite) {
    if(!hasGrafite()) {
        if(grafite->getThickness() == this->thickness) {
            tip = grafite;
            return true;
        } else {
            cout << "fail: calibre incompativel\n";
            return false;
        }
    }
    cout << "fail: ja existe grafite\n";
    return false;
}

std::shared_ptr<Lead> remove() {
    if(hasGrafite()) {
        tip = nullptr;
    }
    return tip;
}

void writePage() {
    if(hasGrafite()) {
        if(tip->getSize() > 10) {
            if(tip->usagePerSheet() < 10) {
                tip->setSize(10);
                cout << "fail: folha incompleta\n";
            } else 
                tip->setSize(tip->usagePerSheet());
        } else 
            cout << "fail: tamanho insuficiente\n";
    } else 
        cout << "fail: nao existe grafite\n";
}

std::string str() {
    std::stringstream ss;
    ss << "calibre: " << thickness << ", grafite: ";
    if (tip != nullptr)
        ss << "[" << *tip << "]";
    else
        ss << "null";
    return ss.str();
}
};

std::ostream& operator<<(std::ostream& os, Pencil l) {
    return os << l.str();
}

using namespace fn;

int main() {
Pencil pencil;

while (true) {
    auto line = input();
    write("$" + line);
    auto args = split(line);

    if      (args[0] == "end"   ) { break;                                                                                  }
    else if (args[0] == "show"  ) { write(pencil);                                                                    }
    else if (args[0] == "init"  ) { pencil = Pencil(number(args[1]));                                                       }
    else if (args[0] == "insert") { pencil.insert(std::make_shared<Lead>(number(args[1]), args[2], (int) number(args[3]))); }
    else if (args[0] == "remove") { pencil.remove();                                                                        }
    else if (args[0] == "write" ) { pencil.writePage();                                                                     }
}
}