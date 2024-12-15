#include "MotorInferencia.h"
#include "BaseConocimiento.h"
#include "BaseHechos.h"
#include "Regla.h"
#include "Hecho.h"
#include <sstream>
#include <math.h>

#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/* VARIABLES GLOBALES */
extern BaseConocimiento BC;

list<Regla> equiparar_cons(Hecho meta) {
    list<Regla> reglas_bc = BC.getReglas();
    list<Regla> reglas_equi;

    // Recorrer las reglas de la base de conocimiento
    for (list<Regla>::iterator it = reglas_bc.begin(); it != reglas_bc.end(); ++it) {
        if (meta.getID() == it->getConsecuente()) {
            reglas_equi.push_back(*it);     // Si el consecuente es igual a la meta, agregar la regla
        }
    }

    return reglas_equi;
}

list<string> extraerAntecedentesyTipo(Regla R) {
    list<string> antecedentesTipo;
    string antecedentesR = R.getAntecedentes();

    stringstream ss(antecedentesR);
    string antecedente;
    string tipo = " ";

    while(getline(ss, antecedente, ' '))
    {
        if (antecedente == "o")
            tipo = "o";
        else if (antecedente == "y")
            tipo = "y";
        else
            antecedentesTipo.push_back(antecedente);
    }
    antecedentesTipo.push_back(tipo);
    return antecedentesTipo;
}

float calcularFCAnt(Regla R, list<float> fcNuevasMetas, string tipo) {
    list<float>::iterator it = fcNuevasMetas.begin();
    if ((fcNuevasMetas.size() > 1) && (tipo != " ")) {
        if (tipo == "y") {
            float min = 1;
            while(it != fcNuevasMetas.end()) {
                if (*it < min)
                    min = *it;
                ++it;
            }
            cout << "\tCaso 1: " << R.getAntecedentes() << ", FC=" << min << endl;
            return min;
        }
        else {
            float max = -1;
            while(it != fcNuevasMetas.end()) {
                if (*it > max)
                    max = *it;
                ++it;
            }
            cout << "\tCaso 1: " << R.getAntecedentes() << ", FC=" << max << endl;
            return max;
        }
    } else {
        return *it;
    }
}

float calcularFCMetaR(Hecho meta, float fcAntecedentesR, float fcR) {
    if (fcAntecedentesR <= 0) {
        cout << "\tCaso 3: " << meta.getID() << ", FC=0" << endl;
        return 0;
    } else {
        float res = fcR*fcAntecedentesR;
        cout << "\tCaso 3: " << meta.getID() << ", FC=" << res << endl;
        return res;
    }
}

float calcularFCcombinacion(Hecho meta, list<float> fcMetas) {
    list<float>::iterator it;
    float res;
    if (fcMetas.size() == 2) {
        it = fcMetas.begin();
        float fc1 = *it;
        float fc2 = *(++it);;
        if ((fc1 >= 0) && (fc2 >= 0))
            res = fc1 + fc2*(1-fc1);
        else if ((fc1 <= 0) && (fc2 <= 0))
            res = fc1 + fc2*(1+fc1);
        else
            res = (fc1 + fc2)/(1-min(fabs(fc1), fabs(fc2)));

        cout << "Caso 2: " << meta.getID() << ", FC=" << res << endl;
        return res;
    } else {
        float fc1 = fcMetas.back();
        fcMetas.pop_back();
        float fc2 = calcularFCcombinacion(meta, fcMetas);
        if ((fc1 >= 0) && (fc2 >= 0))
            res = fc1 + fc2*(1-fc1);
        else if ((fc1 <= 0) && (fc2 <= 0))
            res=fc1 + fc2*(1+fc1);
        else
            res =(fc1 + fc2)/(1-min(fabs(fc1), fabs(fc2)));

        cout << "Caso 2: " << meta.getID() << ", FC=" << res << endl;
        return res;
    }
}


float backward_chaining(Hecho meta, BaseHechos BH) {
    // Obtener el factor de certeza (FC) del hecho correspondiente a la meta desde la BH
    float fc = BH.getHecho(meta).getFC();

    // Si es hecho conocido, devolver su FC directamente
    if (fc >= -1) {
        return fc;
    } else {
        // Buscar las reglas en la BC cuyos consecuentes sean la meta
        list<Regla> cjto_reglas;
        cjto_reglas = equiparar_cons(meta);

        // Lista que almacena los FC de las metas calculadas para cada regla
        list<float> fcMetas;

        while (!cjto_reglas.empty()) {
            // Tomar la primera regla del conjunto de reglas
            Regla r = cjto_reglas.front();
            cjto_reglas.pop_front();  // Eliminar la regla procesada del conjunto

            // Obtener el FC de la regla actual
            float fc_r = r.getFC();

            // Extraer los antecedentes y el tipo de la regla (conjunción o disyunción)
            list<string> antecedentesTipo = extraerAntecedentesyTipo(r);
            string tipo = antecedentesTipo.back();  // El tipo define si los antecedentes son una conjunción o disyunción
            antecedentesTipo.pop_back();  // Eliminar el tipo de la lista para quedarnos solo con los antecedentes

            // Lista de nuevas metas a evaluar
            list<string> nuevasMetas = antecedentesTipo;
            list<float> fcNuevasMetas;  // Lista que almacenará el FC de las nuevas metas

            // Procesar cada nueva meta en la lista de antecedentes
            while (!nuevasMetas.empty()) {
                // Tomar la primera meta de la lista de nuevas metas
                string nMeta = nuevasMetas.front();
                nuevasMetas.pop_front();  // Eliminar la meta procesada de la lista

                // Crear un objeto Hecho para la nueva meta y calcular su FC mediante backward chaining
                Hecho hechoNMeta = Hecho(nMeta, 0);
                float fc = backward_chaining(hechoNMeta, BH);  // Llamada recursiva para calcular el FC de la nueva meta
                fcNuevasMetas.push_back(fc);  // Almacenar el FC calculado para la nueva meta
            }

            // Imprimir información sobre la regla procesada
            cout << "R" << r.getID() << ":\n";

            // Calcular el FC combinado de los antecedentes de la regla según el tipo (conjunción o disyunción)
            float fcAntecedentesR = calcularFCAnt(r, fcNuevasMetas, tipo);

            // Calcular el FC de la meta a partir de la regla procesada
            float fcMetaR = calcularFCMetaR(meta, fcAntecedentesR, fc_r);
            fcMetas.push_back(fcMetaR);  // Almacenar el FC de la meta calculado por la regla
        }

        float fcMeta;

        // Si solo hay una regla que conduce a la meta, usar su FC
        if (fcMetas.size() == 1)
            fcMeta = fcMetas.front();
        else
            // Si hay múltiples reglas, combinar sus FC
            fcMeta = calcularFCcombinacion(meta, fcMetas);

        return fcMeta;  // Retornar el FC final calculado para la meta
    }
}
