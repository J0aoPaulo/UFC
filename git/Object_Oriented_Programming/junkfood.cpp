#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fn.hpp>

using namespace std;
using namespace fn;

class Slot {
string name;
float price;
int quantity;

public: 
Slot(string name = "empty", float price = 0.0, int quantity = 0) :
    name {name}, price {price}, quantity {quantity}
{}

string getname() const {
    return name;
}

void setname(string name) {
    this->name = name;
}

float getprice() const {
    return price;
}

void setprice(float price) {
    this->price = price;
}

int getquantity() const {
    return quantity;
}

void setquantity(int quantity) {
    this->quantity = quantity;
}

string str() {
    stringstream ss;
    if(name == "empty") {
        ss << "["  << "   " << name << " : " << quantity << " U "
    << ": " << fixed << setprecision(2) << price << " RS" << "]";
    return ss.str();
    } else {
        ss << "["  << " " << name << " : " << quantity << " U "
    << ": " << fixed << setprecision(2) << price << " RS" << "]";
    return ss.str();
    }
}   
};

class VendingMachine {
vector<Slot> slots;
float profit;
float cash = 0.0;
int capacity;

public:
VendingMachine(int capacity = 0) :
    capacity {capacity} {
    for (int i = 0; i < capacity; i++) {
        slots.push_back(Slot("empty", 0, 0.0));
    }
}

Slot getSlot(int index) const {
    return slots[index];
}

void setSlot(int index, string name, int quantity, float price) {
    if(index > capacity - 1)
        write("fail: indice nao existe");
    else {
        slots[index].setname(name);
        slots[index].setprice(price);
        slots[index].setquantity(quantity);
    }
}

void clearslots(int index) {
    slots[index].setname ("empty");
    slots[index].setprice (0.0);
    slots[index].setquantity (0);
}

void setCash(float cash) {
    this->cash += cash;
}

void withdrawCash() {
    cout << "voce recebeu " << fixed 
    << setprecision(2) << cash << " RS" << "\n";
    cash = 0.0;
}

float getcash() {
    return cash;
}

float getprofit() {
    return profit;
}

void buyItem(int index) {
    if(index > capacity - 1)
        write("fail: indice nao existe");
    else if(slots[index].getprice() <= cash) {
        if(slots[index].getquantity() > 0) {
            slots[index].setquantity(slots[index].getquantity() - 1);
            cash -= slots[index].getprice();
            cout << "voce comprou um " << slots[index].getname() << "\n";
        } else 
            write("fail: espiral sem produtos");
        } else 
            write("fail: saldo insuficiente"); 
}

string str() {
    stringstream ss;
    int i = 0;
    ss << "saldo: " << fixed 
    << setprecision(2) << cash << "\n";
    for (auto &&elemen : slots)
        if(i == slots.size() - 1)
            ss << i++ << " " << elemen.str();
        else
            ss << i++ << " " << elemen.str() << "\n";
    return ss.str();
}
};

int main() {
VendingMachine machine;

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "show") {
            write(machine.str());
        } else if (args[0] == "init") {
            machine = VendingMachine(stoi(args[1]));
        } else if (args[0] == "set") {
            machine.setSlot(stoi(args[1]), args[2], stoi(args[3]), stof(args[4]));
        } else if (args[0] == "limpar") {
            machine.clearslots(stoi(args[1]));
        } else if (args[0] == "dinheiro") {
            machine.setCash(stof(args[1]));
        } else if (args[0] == "troco") {
            machine.withdrawCash();
        } else if (args[0] == "comprar") {
            machine.buyItem(stoi(args[1]));
        }
    }
    }