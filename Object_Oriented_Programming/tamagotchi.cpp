#include <fn.hpp>
using namespace fn;
using namespace std;

class Pet
{
private:
    bool alive;
    int clean, cleanMax, 
    energy, energyMax, 
    hungry, hungryMax, 
    age, diamonds;

    void sethungryMax(int hungryMax) {
        this->hungryMax = hungryMax;
    }

    void setenergyMax(int energyMax) {
        this->energyMax = energyMax;
    }

    void setcleanMax(int cleanMax) {
        this->cleanMax = cleanMax;
    }

protected:
    bool testAlive() {
        if(clean <= 0) {
            return false;
        } else if(energy <= 0) {
            return false;
        } else if(hungry <= 0) {
            return false;
        } else return true;
    }

public:
    Pet() {

    }
    
    Pet(int energy, int hungry, int clean) {
        this->energy = energy;
        this->hungry = hungry;
        this->clean = clean;
        this->energyMax = energy;
        this->hungryMax = hungry;
        this->cleanMax = clean;
        this->age = 0;
        this->diamonds = 0;
        this->alive = true;
    }

    int getClean() {
        return clean;
    }

    int getEnergy() {
        return energy;
    }

    int getHungry() {
        return hungry;
    }

    int getCleanMax() {
        return cleanMax;
    }

    int getEnergyMax() {
        return energyMax;
    }

    int getHungryMax() {
        return hungryMax;
    }

    void setClean(int clean) {
        if(clean <= 0) {
            clean = 0;
        } else if(clean > cleanMax) {
            clean = cleanMax;
        }
        this->clean = clean;
    }

    void setEnergy(int energy) {
        if(energy <= 0) {
            energy = 0;
        } else if(energy > energyMax) {
            energy = energyMax;
        }
        this->energy = energy;
    }

    void setHungry(int hungry) {
        if(hungry <= 0) {
            hungry = 0;
        } else if(hungry > hungryMax) {
            hungry = hungryMax;
        } 
        this->hungry = hungry;
    }

    void causa() {
        if(getEnergy() == 0) {
            cout << "fail: pet morreu de fraqueza\n";
        } else if(getClean() == 0) {
            cout << "fail: pet morreu de sujeira\n";
        } else {
            cout << "fail: pet morreu de fome\n";
        }
    }

    void eat() {
        if(alive) {
            setEnergy(getEnergy() - 1);
            setHungry(hungry + 4);
            setClean(getClean() - 2);
            age += 1;
            if(!testAlive()) {
                causa();
                alive = false;
            }     
        } else {
            cout << "fail: pet esta morto\n";
        }    
    }
    
    void play() {
        if(alive) {
            setEnergy(getEnergy() - 2);
            setHungry(getHungry() - 1);
            setClean(getClean() - 3);
            diamonds += 1;
            age += 1;
            if(!testAlive()) {
                causa();
                alive = false;
            }     
        } else {
            cout << "fail: pet esta morto\n";
        }    
    }
    
    void shower() {
        if(alive) {
            setEnergy(getEnergy() - 3);
            setHungry(getHungry() - 1);
            setClean(getCleanMax());
            age += 2;
            if(!testAlive()) {
                causa();
                alive = false;
            }     
        } else {
            cout << "fail: pet esta morto\n";
        }    
    }

    void sleep() {
        if(alive) {
            if(energy <= energyMax - 5) {
                setEnergy(getEnergyMax());
                setHungry(getHungry() - 1);
                age += 5;
            } else {
                cout << "fail: nao esta com sono\n";
            }
            if(!testAlive()) {
                causa();
                alive = false;
            } 
        } else {
            cout << "fail: pet esta morto\n";
        }
    }

    string toString() {
        return format("E:{}/{}, S:{}/{}, L:{}/{}, D:{}, I:{}", 
        energy, energyMax, 
        hungry, hungryMax, 
        clean, cleanMax, 
        diamonds, age);
    }
};

int main() {
    Pet tamagotchi;

    while (true) {
        auto line = input();
        write("$" + line);
        vector<string> args = split(line, ' ');

        if(args[0] == "end") {
            break;
        } else if(args[0] == "init") {
            tamagotchi = Pet(stoi(args[1]), stoi(args[2]), stoi(args[3]));
        } else if(args[0] == "show") {
            write(tamagotchi.toString());
        } else if(args[0] == "play") {
            tamagotchi.play();
        } else if(args[0] == "eat") {
            tamagotchi.eat();
        } else if(args[0] == "sleep") {
            tamagotchi.sleep();
        } else if(args[0] == "shower") {
            tamagotchi.shower();
        }
    }
}