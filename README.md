# Sistema Basado en Reglas con Factores de Certeza

Este proyecto forma parte de la práctica II de la asignatura de **Sistemas Inteligentes** de la Universidad de Murcia del curso 24/25. 

## Requisitos

**Compilador C++**: Asegúrate de tener instalado un compilador que soporte C++17 o superior, como:
   - [GCC (GNU Compiler Collection)](https://gcc.gnu.org/)
   - [Clang](https://clang.llvm.org/)
   - [Microsoft Visual C++](https://visualstudio.microsoft.com/)

## Usage/Examples

Para compilar, se recomienda abrir el archivo ```sbr-fc.cbp``` con CodeBlocks (17.12 o superior). Usar la opción de Rebuild. El ejecutable funciona de la siguiente forma:

```bash
> sbr-fc.exe -bc [BASE CONOCIMIENTO] -bh [BASE HECHOS]
```

donde `BASE CONOCIMIENTO` y `BASE HECHOS` son las rutas de los ficheros de prueba. Por comodidad, se incluye una copia de cada uno en el directorio del ejecutable. Para la prueba 3, por ejemplo, ejecutamos:

```bash
> sbr-fc.exe -bc BC-3.txt -bh BH-3-causaAcc.txt

=============================================
          SISTEMA BASADO EN REGLAS       
=============================================

Base de conocimiento:                BC-3.txt
---------------------------------------------
Base de hechos:             BH-3-causaAcc.txt
---------------------------------------------
Meta:                                causaAcc

=============================================

[...]

causaAcc, FC=0.46
```

Para mostrar ayuda, podemos usar la opción `-h`.

## Estructura

```
sbr-fc/
├── bin/            # Ejecutable
├── src/            # Codigo fuente del proyecto
├── include/        # Archivos de cabecera adicionales
├── pruebas/        # Pruebas de la práctica
├── main.cpp        # Archivo principal
└── docs/           # Documentación del proyecto
```

## Documentación

Todos la documentación de la práctica se encuentra en el directorio `docs/`:

   - `informe.pdf`
   - `cuestiones.pdf`
   - `user_manual.pdf`

