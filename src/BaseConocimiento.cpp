#include "BaseConocimiento.h"
#include "Regla.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

/* CONSTANTES GLOBALES */
const string SEP_SI = ": Si ";
const string SEP_ENT = " Entonces ";
const string SEP_FC = ", FC=";

BaseConocimiento::BaseConocimiento() {
}

BaseConocimiento::BaseConocimiento(istream& fic) {
    init(fic);
}

BaseConocimiento::~BaseConocimiento() {
}

std::list<Regla>& BaseConocimiento::getReglas() {
    return reglas;
}

int BaseConocimiento::getNumReglas() {
    return n_reglas;
}

void BaseConocimiento::init(istream& fic) {
    string linea, regla, n_regla, antecedentes, consecuente, fc_str;

    getline(fic, linea);
    n_reglas = stoi(linea);

    for (int i=0; i<n_reglas && getline(fic, linea); i++) {
        regla = linea.substr(0, linea.find(SEP_FC));
        n_regla = regla.substr(0, regla.find(SEP_SI));
        antecedentes = regla.substr(n_regla.length() + SEP_SI.length(), regla.find(SEP_ENT)- (n_regla.length() + SEP_SI.length()));
        consecuente = regla.substr(linea.find(SEP_ENT) + SEP_ENT.length(), regla.length());
        fc_str = linea.substr(linea.find(SEP_FC) + SEP_FC.length(), linea.length());
        reglas.emplace_back(i + 1, antecedentes, consecuente, std::atof(fc_str.c_str()));
    }
}
