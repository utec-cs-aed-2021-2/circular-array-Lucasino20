//
// Created by Lucasino20 on 13/09/2021.
//

#ifndef CIRCULAR_ARRAY_LUCASINO20_HEAPSORT_H
#define CIRCULAR_ARRAY_LUCASINO20_HEAPSORT_H

#include <iostream>

using namespace std;

void heapify(int* arr, int size, int i){
    int valor_max = i; // Toma al nodo raiz como valor_max
    int hijo_izq = 2 * i + 1; // left = 2 * i + 1
    int hijo_der = 2 * i + 2; // right = 2 * i + 2

    //Verifica si el hijo izq es mayor al valor_max
    if (hijo_izq < size && arr[hijo_izq] > arr[valor_max])
        valor_max = hijo_izq; //Si lo es, valor max toma el indice del hijo

    //Lo mismo para el hijo derecho
    if (hijo_der < size && arr[hijo_der] > arr[valor_max])
        valor_max = hijo_der;

    //Si es que el valor maximo no terminó siendo el que se ingresó, intercambian lugares en el array
    if (valor_max != i) {
        swap(arr[i], arr[valor_max]);

        //Se aplica heapify recursivamente en el arbol, ahora a partir del nuevo subarbol
        heapify(arr, size, valor_max);
    }
}


void heap_sort(int* arr, int size)
{
    //Aplica heapify en cada nodo padre del heap
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(arr, size, i);

    //Se va reduciendo size del heap
    for (int i = size - 1; i > 0; i--) {
        //Intercambia el nodo raíz (mayor valor) con el ultimo
        swap(arr[0], arr[i]);

        //aplica heapify al heap reducido, desde su nodo raiz
        heapify(arr, i, 0);
    }
}


#endif //CIRCULAR_ARRAY_LUCASINO20_HEAPSORT_H
