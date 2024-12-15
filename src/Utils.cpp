#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>  // Para std::setw y std::right
#include <string>

#ifdef _WIN32
    #define CLEAR "cls"  // Comando para Windows
#else
    #define CLEAR "clear"  // Comando para Linux/Mac
#endif

using namespace std;

void print_uso(const char *prog_name) {
    cout << "Uso: " << prog_name << " -bc <ruta_base_conocimiento> -bh <ruta_base_hechos>\n";
}

void print_help(const char *prog_name) {
    print_uso(prog_name);
    std::cout << "Opciones:\n"
              << "  -bc <ruta>    Ruta al fichero de la base de conocimiento (obligatorio).\n"
              << "  -bh <ruta>    Ruta al fichero de la base de hechos (obligatorio).\n"
              << "  -h            Muestra esta ayuda.\n";
}

void print_header(const std::string& path_bc, const std::string& path_bh, const std::string& meta) {
    // Imprimir un encabezado visual
    std::cout << "=============================================\n"
              << "          SISTEMA BASADO EN REGLAS       \n"
              << "=============================================\n"
              << "\n";

    // Mostrar información clave con separadores
    std::cout << "Base de conocimiento: "
              << setw(23) << right << path_bc << "\n"
              << "---------------------------------------------\n"
              << "Base de hechos:       "
              << setw(23) << right << path_bh << "\n"
              << "---------------------------------------------\n"
              << "Meta:                 "
              << setw(23) << right << meta << "\n\n"
              << "=============================================\n\n";
}

void clear_screen() {
    system(CLEAR);  // Ejecuta el comando correspondiente para limpiar la pantalla
}
