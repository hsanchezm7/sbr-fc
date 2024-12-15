#ifndef BASECONOCIMIENTO_H
#define BASECONOCIMIENTO_H

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include "Regla.h"

// Clase que representa una base de conocimiento
class BaseConocimiento {
    private:
        int n_reglas;                        // N�mero de reglas en la base de conocimiento
        std::list<Regla> reglas;             // Lista de reglas que conforman la base de conocimiento

    public:
        // Constructor vac�o que crea una base de conocimiento vac�a
        BaseConocimiento();

        // Constructor que inicializa la base de conocimiento a partir de un flujo de entrada
        BaseConocimiento(std::istream& fic);

        // Constructor de copia que crea una nueva base de conocimiento a partir de otra existente
        BaseConocimiento(const BaseConocimiento& BC);

        // Destructor que limpia los recursos de la base de conocimiento
        ~BaseConocimiento();


        std::list<Regla>& getReglas();
        int getNumReglas();

        // Funci�n de inicializaci�n
        void init(std::istream& fic);
};

#endif // BASECONOCIMIENTO_H
