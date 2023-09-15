#include <fn.hpp>
using namespace std;
using namespace fn;

struct Car {
  int pass {0};
  int passMax {2};
  int gas {0};
  int gasMax {100};
  int km {0};

  void entrar() {
    if(pass == passMax) {
      write("fail: limite de pessoas atingido");
      return;
    } 
      pass += 1;
  }
  
  void leave() {
    if(pass == 0) {
      write("fail: nao ha ninguem no carro");
      return;
    }
      pass -= 1;
  }

  void fuel(int value) {
    if(value > gasMax) {
      gas += gasMax;
      return;
    } 
      gas += value;
  }

  void drive(int distance) {
    if(pass == 0) {
      write("fail: nao ha ninguem no carro");
    } else if(gas == 0) {
      write("fail: tanque vazio");
    } else if(gas < distance) {
      km += gas;  
      write("fail: tanque vazio apos andar " + tostr(gas) + " km");
      gas = 0;
    } else {
      km += distance;
      gas -= distance;
    }
  }

  string str() {
    return "pass: " 
    + tostr(pass) 
    + ", gas: " 
    + tostr(gas) 
    + ", km: " 
    + tostr(km);
  }
};

int main(){
  Car car; 

  while(true) {
    auto line = input();
    write("$" + line);
    vector<string> args = split(line, ' ');

    if (args[0] == "end") {
      break;
    } else if(args[0] == "show") {
      write(car.str());
    } else if(args[0] == "enter") {
      car.entrar();
    } else if(args[0] == "fuel") {
      car.fuel(stoi(args[1]));
    } else if(args[0] == "leave") {
      car.leave();
    } else if(args[0] == "drive") {
      car.drive(stoi(args[1]));
    }
  }
}