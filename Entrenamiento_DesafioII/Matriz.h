#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include "lista.h"

using namespace std;

class Matriz{
public:
    Lista<float>* filas;  // arreglo dinámico de listas
    int N; // número de filas
    int M; // número de columnas
public:
    Matriz();
    void construirDesdeArchivo(string nombreArchivo);
    void imprimir();
    void eliminarFila(int filaEliminar);
    ~Matriz();
};

#endif // MATRIZ_H
