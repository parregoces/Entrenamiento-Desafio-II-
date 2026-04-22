#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T data;
    Nodo<T>* ptrNext;

    Nodo(T value) {
        data = value;
        ptrNext = nullptr;
    }
};

#endif // NODO_H
