#include "BaseHechos.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <iterator>

#define NOHECHO -999999

using namespace std;

/* CONSTANTES GLOBALES */
const string SEP_FC = ", FC=";

BaseHechos::BaseHechos() {
}

BaseHechos::BaseHechos(istream& fic) {
    init(fic);
}


BaseHechos::~BaseHechos() {
}

void BaseHechos::addHecho(Hecho h) {
    hechos.push_back(h);
    n_hechos++;
}


Hecho BaseHechos::getObjetivo() {
    return objetivo;
}

// Devuelve el hecho de la base de hechos. Si el hecho no esta en la BH devuelve un hecho "vacio" con fc=NOHECHO
Hecho BaseHechos::getHecho(Hecho h) {
    list<Hecho>::iterator it;
    for (it=hechos.begin(); it!=hechos.end(); ++it) {
        if (it->getID() == h.getID())
            return *it;
    }

    // El hecho no está en la base de hechos
    Hecho noHecho = Hecho("", NOHECHO);
    return noHecho;
}

void BaseHechos::muestraBH() {
    cout << "Base de hechos con " << n_hechos << " hechos." << endl;
    list<Hecho>::iterator it;
    it = hechos.begin();
    for (it = hechos.begin(); it != hechos.end(); ++it) {
        cout << it->getID() << ", FC=" << it->getFC() << endl;
    }
    cout << "Objetivo: " << objetivo.getID() << endl;
}

void BaseHechos::init(istream& fic) {
    string linea, hecho, fc_str, obj_str, null;

    getline(fic, linea);
    n_hechos = stoi(linea);

    for (int i=0; i<n_hechos && getline(fic, linea); i++) {
        hecho = linea.substr(0, linea.find(SEP_FC));
        fc_str = linea.substr(linea.find(SEP_FC) + SEP_FC.length(), linea.length());
        Hecho h = Hecho(hecho, atof(fc_str.c_str()));
        hechos.push_back(h);
    }

    getline(fic, null);
    getline(fic, obj_str);
    Hecho o = Hecho(obj_str, 0);
    objetivo = o;
}
