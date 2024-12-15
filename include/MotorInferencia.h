#ifndef MOTOR_INFERENCIA_H
#define MOTOR_INFERENCIA_H

#include "Hecho.h"
#include "Regla.h"
#include "BaseConocimiento.h"
#include "BaseHechos.h"
#include <string>
#include <list>

/**
 * Filtra las reglas de la base de conocimiento que tienen un consecuente igual a la meta proporcionada.
 *
 * @param meta Objeto de tipo Hecho que representa la meta (consecuente) a buscar en las reglas.
 * @return list<Regla> Lista de reglas cuya consecuencia es igual al identificador de la meta.
 */
std::list<Regla> equiparar_cons(Hecho meta);

std::list<std::string> extraerAntecedentesyTipo(Regla R);

float calcularFCAnt(Regla R, std::list<float> fcNuevasMetas, std::string tipo);

// Calcula el FC de una meta por la regla R (Caso 3).
float calcularFCMetaR(Hecho meta, float fcAntecedentesR, float fcR);

// Calcula el FC de una meta si hay mas de 2 reglas que nos llevan a esa meta (Caso 2).
float calcularFCcombinacion(Hecho meta, std::list<float> fcMetas);

/**
 * Realiza el proceso de encadenamiento hacia atrás (Backward Chaining) para calcular el factor de certeza (FC)
 * de una meta dada, basándose en una base de hechos proporcionada.
 *
 * @param meta Objeto de tipo Hecho que representa la meta que se quiere alcanzar.
 * @param BH Objeto de tipo BaseHechos que contiene los hechos conocidos hasta el momento.
 * @return float El factor de certeza calculado para la meta proporcionada.
 */
float backward_chaining(Hecho meta, BaseHechos BH);

#endif // MOTOR_INFERENCIA_H
