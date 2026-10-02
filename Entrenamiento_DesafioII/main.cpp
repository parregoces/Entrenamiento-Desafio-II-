#include <iostream>
#include "matriz.h"
#include <iostream>

using namespace std;

int main()
{
    Matriz mat;
    mat.construirDesdeArchivo("../data2.txt");

    cout << "Matriz original:\n";
    mat.imprimir();
    mat.eliminarFila(2);

    cout << "\nDespues de eliminar fila 1:\n";
    mat.imprimir();

    cout << "\nMe fallo la prueba\n";


    return 0;

}
