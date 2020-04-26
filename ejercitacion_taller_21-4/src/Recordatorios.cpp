#include <iostream>
#include <list>

using namespace std;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    int dia_;
    int mes_;
};

Fecha::Fecha(int mes, int dia) : dia_(dia), mes_(mes) {}

int Fecha::mes() {
    return this->mes_;
}

int Fecha::dia() {
    return this->dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes() ;
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

void Fecha::incrementar_dia() {
    if(this->dia() == dias_en_mes(this->mes())) {
        this->mes_++;
        this->dia_ = 1;
    } else {
        this->dia_++;
    }
}
// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator==(Horario h);
        bool operator<(Horario h);

    private:
        uint min_;
        uint hora_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {}

uint Horario::hora() {
    return this->hora_;
}

uint Horario::min() {
    return this->min_;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora();
    bool igual_min = this->min() == h.min();
    return igual_min && igual_hora;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min() ;
    return os;
}

bool Horario::operator<(Horario h) {
    if(this->hora_ < h.hora_) {
        return true;
    } else if(this->hora_ == h.hora_) {
        return this->min() < h.min();
    }
    return false;
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    string mensaje();
    Horario horario();
    Fecha fecha();
    bool operator<(Recordatorio r);

private:
    Horario horario_;
    Fecha fecha_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje) :
    fecha_(fecha.mes(), fecha.dia()),
    horario_(horario.hora(), horario.min()),
    mensaje_(mensaje) {}

Fecha Recordatorio::fecha() {
    return this->fecha_;
}

Horario Recordatorio::horario() {
    return this->horario_;
}

string Recordatorio::mensaje() {
    return this->mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario() ;
    return os;
}

bool Recordatorio::operator<(Recordatorio r) {
    return this->horario() < r.horario();

}

// Ejercicio 14

// Clase Agenda
class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

private:
    Fecha fecha_actual_;
    list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial) : fecha_actual_(fecha_inicial.mes(), fecha_inicial.dia()), recordatorios_() {};

void Agenda::agregar_recordatorio(Recordatorio rec) {
    this->recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    this->fecha_actual_.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> response = {};
    for (Recordatorio rec: this->recordatorios_) {
        if(rec.fecha() == this->hoy()) {
            response.push_back(rec);
        }
    }
    return response;
}

Fecha Agenda::hoy() {
    return this->fecha_actual_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << '\n';
    os << "=====" << '\n';
    list<Recordatorio> recordatoriosHoy = a.recordatorios_de_hoy();
    recordatoriosHoy.sort();
    for (Recordatorio rec: recordatoriosHoy) {
        os << rec << '\n';
    }
    return os;
}





