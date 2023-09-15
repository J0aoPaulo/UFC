#include <fn.hpp>
using namespace fn;
using namespace std;

class Time
{
private:
    int hora {0};
    int minuto {0};
    int segundo {0};

public:
    int maxMin {59};
    int maxHora {23};

    Time(int hora, int minuto, int segundo) {
        this->hora = hora;
        this->minuto = minuto;
        this->segundo = segundo;
    }

    int getHora() {
        return hora;
    }

    int getMinuto() {
        return minuto;
    }

    int getmaxMin() {
        return maxMin;
    }

    int getSegundo() {
        return segundo;
    }

    void setHora(int hora) {
        if(hora > 24 || hora < 0) {
            write("fail: hora invalida");
        } else this->hora = hora;
    }

    void setMinuto(int minuto) {
        if(minuto > 60 || minuto < 0) {
            write("fail: minuto invalido");
        } else this->minuto = minuto;
    }

    void setSegundo(int segundo) {
        if(segundo > 60 || segundo < 0) {
            write("fail: segundo invalido");
        } else this->segundo = segundo;
    }

    void nextsecond() {
        setSegundo (0);
        if(getMinuto() == maxMin) {
            setMinuto (0);
            if(getHora() == maxHora) {
                setHora (0);
            } else setHora(hora + 1);
        }
    }

    void init(int hora, int minuto, int segundo) {
        if(hora > maxHora || hora < 0) {
            setHora(0);
            write("fail: hora invalida");
        } else {
            this->hora = hora;
        }
        if(minuto > maxMin || segundo < 0) {
            setMinuto(0);
            write("fail: minuto invalido");
        } else {
            this->minuto = minuto;
        }
        if(segundo > maxMin || segundo < 0) {
            setSegundo(0);
            write("fail: segundo invalido");
        } else {
            this->segundo = segundo;
        }
    }

    string str() {
        return format("{%02d}:{%02d}:{%02d}", hora, minuto, segundo);
    }
};

int main() {
    Time relogio (0, 0, 0);

    while (true) {
        auto line = input();
        write("$" + line);
        vector<string> args = split(line, ' ');

        if(args[0] == "show") {
            write(relogio.str());
        } else if(args[0] == "end") {
            break;
        } else if(args[0] == "set") {
            relogio.setHora(stoi(args[1]));
            relogio.setMinuto(stoi(args[2]));
            relogio.setSegundo(stoi(args[3]));
        } else if(args[0] == "next") {
            relogio.nextsecond();
        } else {
            relogio.init(stoi(args[1]), 
            stoi(args[2]), stoi(args[3]));
        }
    }
}   