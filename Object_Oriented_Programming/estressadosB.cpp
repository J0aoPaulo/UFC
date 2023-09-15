#include <iostream>
#include <vector>

int count(std::vector<int> vet, int x) {
    int cont = 0;

    for (auto elemen : vet)
    {
        if(elemen == x) cont++;
    }
    return cont;
}

int sum(std::vector<int> vet) {
    int soma = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            vet[i] *= -1;
            soma += vet[i];
        } else {
            soma += vet[i];
        }
    }
    return soma;
}

double average(const std::vector<int>& vet) {
    float soma = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            soma += vet[i] * -1;
        } else {
            soma += vet[i];
        }
    }
    return soma / vet.size();
}

std::string more_men(const std::vector<int>& vet) {
    int contMen = 0, contWomen = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] > 0) {
            contMen++;
        } else if(vet[i] < 0) {
            contWomen++;
        }
    }
    
    if(contMen > contWomen) {
        return "men";
    } else if(contMen < contWomen) {
        return "women";
    } else {
        return "draw";
    }
}

std::string half_compare(const std::vector<int>& vet) {
    int meTam = vet.size() / 2, priMetade = 0, segMetade = 0;

    for (int i = 0; i < meTam; i++)
    {
        if(vet[i] < 0) {
            priMetade += (vet[i] * -1);
        } else {
            priMetade += vet[i];
        }
    }
    
    for (int i = meTam; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            segMetade += (vet[i] * -1);
        } else {
            segMetade += vet[i];
        }
    }
    
    if(priMetade > segMetade) {
        return "first";
    } else if(priMetade < segMetade) {
        return "second";
    } else return "draw";
}

std::string sex_battle(const std::vector<int>& vet) {
    int sumMen = 0, sumWomen = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            sumWomen += (vet[i] * -1);
        } else {
            sumMen += vet[i];
        }
    }
    
    if(sumMen > sumWomen) {
        return "men";
    } else if(sumMen < sumWomen) {
        return "women";
    } else {
        return "draw";
    }
}

#include <fn.hpp>
using namespace fn;

int main() {

    auto str2vet = [](auto s) { return s.substr(1, s.size() - 2) | SPLIT(',') | MAP(FNT(x, (int)+x)); };

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"              ) { break;                                              }
        else if (args[0] == "count"            ) { count(str2vet(args[1]), +args[2])         | WRITE();}
        else if (args[0] == "sum"              ) { sum(str2vet(args[1]))                     | WRITE();}
        else if (args[0] == "more_men"         ) { more_men(str2vet(args[1]))                | WRITE();} 
        else if (args[0] == "half_compare"     ) { half_compare(str2vet(args[1]))            | WRITE();}
        else if (args[0] == "more_men_or_women") { more_men(str2vet(args[1]))                | WRITE();}
        else if (args[0] == "sex_battle"       ) { sex_battle(str2vet(args[1]))              | WRITE();}
        else if (args[0] == "average"          ) { average(str2vet(args[1])) | TOSTR("%.2f") | WRITE();}
        else                                     { "fail: unknown command"                   | WRITE();}
    }     
}
