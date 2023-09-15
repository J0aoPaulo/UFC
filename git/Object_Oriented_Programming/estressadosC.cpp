#include <iostream>
#include <algorithm>
#include <vector>
#include <fn.hpp>

using namespace fn;

std::vector<int> get_men(std::vector<int> vet) {
    std::vector<int> vetMen{};

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            continue;
        } else {
            vetMen.push_back(vet[i]);
        }
    }
    return vetMen;
}

std::vector<int> get_calm_women(std::vector<int> vet) {
    std::vector<int> vetWomen{};

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] > 0) {
            continue;
        } else if(vet[i] > -10){
            vetWomen.push_back(vet[i]);
        }
    }
    return vetWomen;
}

std::vector<int> sort(std::vector<int> vet) {
    int aux;

    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = 0; j < vet.size(); j++)
        {
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    return vet;
}

std::vector<int> sort_stress(std::vector<int> vet) {
    int aux, contNeg = 0, j = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
            contNeg++;
        }
    }
    
    int aux2[contNeg];

    for (int i = 0; i < vet.size(); i++)
    {
        if(vet[i] < 0) {
        vet[i] *= -1;
        aux2[j] = vet[i];
        j++;
        }
    }
    

    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = 0; j < vet.size(); j++)
        {
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    for (int i = 0; i < vet.size(); i++)
    {
        for (j = 0; j < contNeg; j++)
        {
            if(vet[i] == aux2[j]) {
                vet[i] *= -1;
            }
        }
    }
    return vet;
}

std::vector<int> reverse(std::vector<int> vet) {
    std::vector<int> aux (vet.size());

    for (int i = vet.size() -1, j = 0; i >= 0; i--, j++)
    {
        aux[j] = vet[i];
    }
    return aux;
}

std::vector<int> reverse_inplace(std::vector<int> vet) {
    
    for (int i = vet.size() -1, j = 0; i >= 0; i--, j++)
    {
        vet[j] = vet[i];
    }
    return vet;
}

std::vector<int> unique(std::vector<int> vet) {
    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = 0; j < vet.size(); j++)
        {
            if(vet[i] == vet[j] && i != j) {
                vet.erase(vet.begin() + j);
            }
        }
    }
    return vet;
}

std::vector<int> repeated(std::vector<int> vet) {
    int z = 0;
    bool flag = false;
    std::vector<int> aux (2);
    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = 0; j < vet.size(); j++)
        {
            if(vet[i] == vet[j] && i != j) {
                aux[z] = vet[i];
                z++;
                flag = true;    
            }
        }
    }
    if(!flag)
        return {};
    else return sort(aux);
}


int main() {
    auto strToVet = [](auto s) { return s.substr(1, s.size() - 2) | SPLIT(',') | MAP(FNT(x, (int)+x)); };

    while(true) {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if     (args[0] == "get_men"        ) { write(get_men(strToVet(args[1])));        }
        else if(args[0] == "get_calm_women" ) { write(get_calm_women(strToVet(args[1]))); }
        else if(args[0] == "sort"           ) { write(sort(strToVet(args[1])));           }
        else if(args[0] == "sort_stress"    ) { write(sort_stress(strToVet(args[1])));    }
        else if(args[0] == "reverse"        ) { write(reverse(strToVet(args[1])));        }
        else if(args[0] == "reverse_inplace") { write(reverse(strToVet(args[1])));        }
        else if(args[0] == "unique"         ) { write(unique(strToVet(args[1])));         }
        else if(args[0] == "repeated"       ) { write(repeated(strToVet(args[1])));       }
        else if(args[0] == "end"            ) { break;                                    }
    }
}