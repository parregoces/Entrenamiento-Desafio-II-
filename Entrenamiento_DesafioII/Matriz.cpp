#include "matriz.h"
#include <fstream>
#include <sstream>

Matriz::Matriz() {
    filas = nullptr;
    N = 0;
    M = 0;}

void Matriz::construirDesdeArchivo(string nombreArchivo) {
    ifstream file(nombreArchivo);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    string linea;
    N = 0;

    // Primero contamos filas
    while (getline(file, linea)) {
        N++;
    }

    file.clear();
    file.seekg(0);

    filas = new Lista<float>[N];
    int i = 0;

    while (getline(file, linea)) {
        stringstream ss(linea);
        float valor;
        int j = 0;

        while (ss >> valor) {
            filas[i].agregar(valor, j);
            j++;
        }
        if (i == 0){
            M = j;
        }// número de columnas
        i++;
    }

    file.close();
}

void Matriz::imprimir() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << filas[i].consultar(j) << " ";
        }
        cout <<endl;
    }
}

void Matriz::eliminarFila(int filaEliminar) {
    if (filaEliminar < 0 || filaEliminar >= N) {
        throw out_of_range("Fila inválida");
    }

    Lista<float>* nuevasFilas = new Lista<float>[N - 1];

    int k = 0;
    for (int i = 0; i < N; i++) {
        if (i != filaEliminar) {
            nuevasFilas[k] = filas[i];
            k++;
        }
    }

    delete[] filas;
    filas = nuevasFilas;
    N--;
}

Matriz::~Matriz() {
    delete[] filas;
}
