#include "Utils.h"
#include "BaseConocimiento.h"
#include "BaseHechos.h"
#include "Regla.h"
#include "Hecho.h"
#include "MotorInferencia.h"
#include <cstdlib>

/* VARIABLES GLOBALES */
BaseConocimiento BC;

using namespace std;

/**
 * Función principal del programa.
 * @return Código de salida del programa.
 */
int main(int argc, char *argv[]) {
    string path_bc, path_bh;    // Rutas a los archivos de base de conocimiento y hechos
    ifstream f_bc, f_bh;

    // Verificar si los argumentos son suficientes y válidos
    if (argc < 5 && string(argv[1]) != "-h") {
        print_uso(argv[0]);
        return EXIT_FAILURE;
    }

    // Procesar los argumentos proporcionados al programa
    for (int i=1; i < argc; ++i) {
        if (string(argv[i]) == "-h") {
            print_help(argv[0]); // Si el argumento es "-h", muestra la ayuda
            return EXIT_SUCCESS;
        }
        else if (string(argv[i]) == "-bc" && i + 1 < argc) {
            path_bc = argv[++i]; // Obtiene la ruta de la base de conocimiento
        }
        else if (string(argv[i]) == "-bh" && i + 1 < argc) {
            path_bh = argv[++i]; // Obtiene la ruta de la base de hechos
        }
        else {
            // Manejo de errores en los argumentos
            cerr << "Error: Opción o argumento no válido: " << argv[i] << "\n";
            print_help(argv[0]);
            return EXIT_FAILURE;
        }
    }

    // Intentar abrir los archivos proporcionados en modo lectura
    f_bc.open(path_bc);
    f_bh.open(path_bh);

    // Verificamos ambos archivos
    if (!f_bc.is_open() | !f_bh.is_open()) {
        cerr << "Error: Compruebe que la lectura de los ficheros sea correcta y su ruta exista.\n";
        return EXIT_FAILURE;
    }

    // Crear base de hechos e inicializar la base de conocimiento
    BaseHechos bh_ini = BaseHechos(f_bh);
    BC.init(f_bc);

    // Obtener el objetivo (meta) de la base de hechos
    Hecho meta = bh_ini.getObjetivo();

    clear_screen();

    // Mostrar información sobre los archivos y el objetivo
    print_header(path_bc, path_bh, meta.getID());

    // Ejecutar el algoritmo del SBR
    cout << endl << meta.getID() << ", FC=" << backward_chaining(meta, bh_ini) << "\n";

    f_bc.close();
    f_bh.close();

    return EXIT_SUCCESS;
}
