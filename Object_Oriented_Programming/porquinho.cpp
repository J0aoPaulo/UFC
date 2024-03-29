#include <fn.hpp>
#include <iostream>
#include <utility>
#include <list> 
using namespace fn;
using namespace std;

class Coin {
double value;
int volume;
std::string label;

Coin(double value, int volume, std::string label) :
    value(value), volume(volume), label(label) {
}
public:
const static Coin C10;
const static Coin C25;
const static Coin C50;
const static Coin C100;

double getValue() const { 
    return value; 
}
int getVolume() const { 
    return volume; 
}
std::string getLabel() const { 
    return label; 
}

std::string str() const {
    return fn::format("{%.2f}:{}", value, volume);
}
};

const Coin Coin::C10 {0.10, 1, "C10"};
const Coin Coin::C25 {0.25, 2, "C25"};
const Coin Coin::C50 {0.50, 3, "C50"};
const Coin Coin::C100 {1.00, 4, "C100"};

std::ostream& operator<<(std::ostream& os, const Coin& coin) {
return os << coin.str();
}

class Item {
std::string label;
int volume;
public:
Item(std::string label, int volume) : 
    label {label}, volume {volume} {

}
int getVolume() const {
    return volume;
}
std::string getLabel() const {
    return label;
}
void setVolume(int volume) {
    this->volume = volume;
}
void setLabel(std::string label) {
    this->label = label;
}
std::string str() const {
    return format("{%s}:{%d}", label, volume);
}
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
return os << item.str();
}

class Pig {
std::vector<Item> itens;
std::vector<Coin> coins;

int volumeMax {0};
bool broken {false};

public:
Pig(int volumeMax = 0) { 
    this->volumeMax = volumeMax;
}

bool addCoin(Coin coin) {
    if(!broken) {
        if(coin.getVolume() + getVolume() < volumeMax) {
            coins.push_back(coin);
            return true;
        } else
            write("fail: the pig is full");
            return false;
    } else 
        write("fail: the pig is broken");
    return false;
}

bool addItem(Item item) {
    if(!broken) {
        if(item.getVolume() + getVolume() < volumeMax) {
            itens.push_back(item);
            return true;
        } else
            write("fail: the pig is full");
            return false;
    } else 
        write("fail: the pig is broken");
    return false;
}

bool breakPig() {
    if(!broken) {
        broken = true;
        return true;
    } else 
        return false;
}

std::vector<Coin> extractCoins() {
    vector<Coin> extract;
    if(!broken) {
        write("fail: you must break the pig first");
        return extract;
    } else {
        extract = coins;
        coins.clear();
        return extract;
    }
}

std::vector<Item> extractItems() {
    vector<Item> extract;
    if(!broken) {
        write("fail: you must break the pig first");
        return extract;
    } else {
        extract = itens;
        itens.clear();
        return extract;
    }
}

double sumValue() const {
    double sumValue {0};
    for (auto &&elemen : coins)
        sumValue += elemen.getValue();
    return sumValue;
}

double getValue() const {
    return sumValue();
}

int sumAllVolume() const{
    int sumVolume {0};
    for (auto &&elemen : coins)
        sumVolume += elemen.getVolume();

    for (auto &&elemen : itens)
        sumVolume += elemen.getVolume();
    return sumVolume;
}

int getVolume() const {
    if(!broken)
        return sumAllVolume();
    else return 0;
}

int getVolumeMax() const {
    return volumeMax;
}

std::string str() const {
    return format("state={} : coins={} : items={} : value={%.2f} : volume={}/{}",
    (this->broken ? "broken" : "intact"), coins, itens, getValue(), getVolume(), getVolumeMax());
}
};

std::ostream& operator<<(std::ostream& os, const Pig& pig) {
return os << pig.str();
}


int main() {

Pig pig;
while (true) {
    auto line = fn::input();
    fn::write("$" + line);
    auto args = fn::split(line);

    if      (args[0] == "end"    ) { break; }
    else if (args[0] == "addCoin") { 
        if      (args[1] == "10" ) pig.addCoin(Coin::C10);
        else if (args[1] == "25" ) pig.addCoin(Coin::C25);
        else if (args[1] == "50" ) pig.addCoin(Coin::C50);
        else if (args[1] == "100") pig.addCoin(Coin::C100);
    }
    else if (args[0] == "init"        ) { pig = Pig( (int) +(args[1]));                 }
    else if (args[0] == "addItem"     ) { pig.addItem(Item(args[1], (int) +(args[2]))); }
    else if (args[0] == "break"       ) { pig.breakPig();                               }
    else if (args[0] == "extractCoins") { fn::write(pig.extractCoins());                }
    else if (args[0] == "extractItems") { fn::write(pig.extractItems());                }
    else if (args[0] == "show"        ) { fn::write(pig);                               }
    else                                { fn::write("fail: invalid command");           }
}
}