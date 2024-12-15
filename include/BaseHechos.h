#ifndef BASEHECHOS_H
#define BASEHECHOS_H

#include "Hecho.h"
#include <iostream>
#include <list>

// Clase que representa la base de hechos de un sistema basado en reglas
class BaseHechos {
    private:
        std::list<Hecho> hechos;    // Lista de hechos que conforman la base de hechos
        int n_hechos;               // Número de hechos en la base de hechos
        Hecho objetivo;             // Hecho objetivo que representa el objetivo del sistema

    public:
        // Constructor vacío de la base de hechos. Inicializa la base sin hechos ni objetivo.
        BaseHechos();

        // Constructor que inicializa la base de hechos a partir de un flujo de entrada.
        BaseHechos(std::istream& fic);

        // Destructor de la base de hechos. Elimina los hechos almacenados y libera recursos si es necesario.
        ~BaseHechos();

        int getNumHechos();
        Hecho getHecho(Hecho h);
        Hecho getObjetivo();
        void addHecho(Hecho h);
        void muestraBH();

        // Inicializa la base de hechos
        void init(std::istream& fic);
};

#endif // BASEHECHOS_H
