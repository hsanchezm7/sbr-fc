#ifndef REGLA_H
#define REGLA_H

#include <string>

class Regla {
    private:
        int id;
        std::string antecedentes;
        std::string consecuente;
        float fc;

    public:
        Regla() { }
        Regla(int id, std::string antecedente, std::string consecuente, float certeza);
        ~Regla();

        int getID();
        std::string getAntecedentes();
        std::string getConsecuente();
        float getFC();
};

#endif // REGLA_H
