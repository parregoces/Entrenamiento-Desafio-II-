#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>

using namespace std;

template <typename T>
class Lista {
public:
    Nodo<T>* head;  // primer nodo
    int size;       // tamaño

public:
    Lista() {
        head = nullptr;
        size = 0;
    }
    ~Lista() {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            Nodo<T>* temp = actual;
            actual = actual->ptrNext;
            delete temp;
        }
    }
    bool esVacia() {return head == nullptr;}
    int tamano(){return size;}
    T primero(){
        if (esVacia()){
            throw runtime_error("Lista vacía");
        }
        return head->data;
    }
    T ultimo() {
        if (esVacia()){
            throw runtime_error("Lista vacía");
        }
        Nodo<T>* actual = head;
        while (actual->ptrNext != nullptr) {
            actual = actual->ptrNext;
        }
        return actual->data;
    }
    void agregar(T e, int i) {
        if (i < 0 || i > size) {
            throw out_of_range("Posición inválida");
        }
        Nodo<T>* nuevo = new Nodo<T>(e);

        if (i == 0) {
            nuevo->ptrNext = head;
            head = nuevo;
        } else {
            Nodo<T>* actual = head;
            for (int j = 0; j < i - 1; j++) {
                actual = actual->ptrNext;
            }
            nuevo->ptrNext = actual->ptrNext;
            actual->ptrNext = nuevo;
        }
        size++;
    }
    T consultar(int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Posición inválida");
        }
        Nodo<T>* actual = head;
        for (int j = 0; j < i; j++) {
            actual = actual->ptrNext;
        }
        return actual->data;
    }
    void reemplazar(T e, int i) {
        if (i < 0 || i >= size){
            throw std::out_of_range("Posición inválida");
        }
        Nodo<T>* actual = head;
        for (int j = 0; j < i; j++) {
            actual = actual->ptrNext;
        }
        actual->data = e;
    }
    void eliminar(T e) {
        if (esVacia()) return;

        if (head->data == e) {
            Nodo<T>* temp = head;
            head = head->ptrNext;
            delete temp;
            size--;
            return;
        }

        Nodo<T>* actual = head;
        while (actual->ptrNext != nullptr && actual->ptrNext->data != e) {
            actual = actual->ptrNext;
        }

        if (actual->ptrNext != nullptr) {
            Nodo<T>* temp = actual->ptrNext;
            actual->ptrNext = temp->ptrNext;
            delete temp;
            size--;
        }
    }

    static int memoryUsage() {
        return sizeof(Lista<T>);
    }

    void concatenar(Lista<T>& B) {
        if (B.esVacia()) return;
        if (esVacia()) {
            head = B.head;
        } else {
            Nodo<T>* actual = head;
            while (actual->ptrNext != nullptr) {
                actual = actual->ptrNext;
            }
            actual->ptrNext = B.head;
        }

        size += B.size;
    }
};


#endif // LISTA_H
