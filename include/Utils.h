#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * Muestra un mensaje básico de uso del programa.
 * @param prog_name Nombre del programa.
 */
void print_uso(const char *prog_name);

/**
 * Muestra un mensaje de ayuda detallado con las opciones disponibles en la línea de comandos.
 * @param prog_name Nombre del programa, que se muestra al inicio del mensaje de ayuda.
 */
void print_help(const char *prog_name);

/**
 * Imprime un encabezado visual con la información de la base de conocimiento, base de hechos y meta.
 * @param path_bc Ruta al fichero de la base de conocimiento.
 * @param path_bh Ruta al fichero de la base de hechos.
 * @param meta Identificador de la meta (objetivo) en el sistema basado en reglas.
 */
void print_header(const std::string& path_bc, const std::string& path_bh, const std::string& meta);

/**
 * Limpia la pantalla de la consola, ejecutando el comando adecuado según el sistema operativo.
 * Dependiendo del entorno (Windows o Unix), se ejecuta el comando `cls` o `clear`.
 */
void clear_screen();

#endif // UTILS_H
