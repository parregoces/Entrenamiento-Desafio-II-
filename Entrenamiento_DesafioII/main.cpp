#include <iostream>
#include "matriz.h"
#include <iostream>

using namespace std;

int main()
{
    Matriz mat;
    mat.construirDesdeArchivo("data2.txt");

    cout << "Matriz original:\n";
    mat.imprimir();
    mat.eliminarFila(1);

    cout << "\nDespues de eliminar fila 1:\n";
    mat.imprimir();

    return 0;

}
