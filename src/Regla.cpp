#include "Regla.h"
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

Regla::Regla(int id, string antecedentes, string consecuente, float fc) {
    this->id = id;
    this->antecedentes = antecedentes;
    this->consecuente = consecuente;
    this->fc = fc;
}

Regla::~Regla() {
}

int Regla::getID() {
    return id;
}

string Regla::getAntecedentes() {
    return antecedentes;
}

string Regla::getConsecuente() {
    return consecuente;
}

float Regla::getFC() {
    return fc;
}
