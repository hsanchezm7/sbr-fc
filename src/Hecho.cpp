#include "Hecho.h"
#include <string>

using namespace std;

Hecho::Hecho(string id, float fc) {
    this->id = id;
    this->fc = fc;
}

Hecho::~Hecho() {
}

string Hecho::getID() {
    return id;
}

float Hecho::getFC() {
    return fc;
}
