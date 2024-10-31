/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/10/2024
 * Version: 3
 *
 * El presente programa posee los metodos de ordenamiento para poder
 * ordenar los productos en base a su precio, venta o disponibilidad.
 * Para ello, este archivo sorts.h posee el metodo de ordenamiento Merge.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <string>
#include <sstream>
#include <vector>
#include "dlist.h"
using namespace std;

template <class T>
class Sorts {
    private:
        void swap(DList<T>&, int, int);
        void copyDList(DList<T>&, DList<T>&, int, int);
        void mergeDList(DList<T>&, DList<T>&, int, int, int);
        void mergeSplit(DList<T>&, DList<T>&, int, int);
    public:
        DList<T> ordenaMerge(const DList<T>&);
        DList<string> ordenaProductos(DList<T>&, DList<T>&, DList<string>&);
};

/*
* swap(DList<T> &A, int i, int j)
*
* Cambia dos valores dentro de un lista doblemente enlazada
*
* @param DList<T> &A, int i, int j
* return
*/

template <class T>
void Sorts<T>::swap(DList<T> &A, int i, int j) {
    T aux = A.get(i);
    A.update(i, A.get(j));
    A.update(j, aux);
}

/*
* copyDList(DList<T> &A, DList<T> &B, int low, int high)
*
* Copia el contenido de una lista a otra
*
* @param DList<T> &A, DList<T> &B, int low, int high
* return
*/

template <class T>
void Sorts<T>::copyDList(DList<T> &A, DList<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A.update(i, B.get(i));
    }
}

/*
* mergeDList(DList<T> &A, DList<T> &B, int low, int mid, int high)
*
* Se encarga de ordenar la lista doblemente enlazada, basicamente hace el
* procedimiento del metodo Merge
*
* @param DList<T> &A, DList<T> &B, int low, int mid, int high
* return
*/

template <class T>
void Sorts<T>::mergeDList(DList<T> &A, DList<T> &B, int low,
int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (A.get(i) > A.get(j)) {
            B.update(k++, A.get(i++));
        } else {
            B.update(k++, A.get(j++));
        }
    }
    while (i <= mid) {
        B.update(k++, A.get(i++));
    }
    while (j <= high) {
        B.update(k++, A.get(j++));
    }
}

/*
* mergeSplit(DList<T> &A, DList<T> &B, int low, int high)
*
* Se encarga de dividir la lista en pequeñas partes, para luego
* hacer el merge, ordenamiento correspondiente
*
* @param DList<T> &A, DList<T> &B, int low, int high
* return
*/

template <class T>
void Sorts<T>::mergeSplit(DList<T> &A, DList<T> &B, int low, int high) {
    if (high - low < 1) {
        return;
    }
    int mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeDList(A, B, low, mid, high);
    copyDList(A, B, low, high);
}

/*
* ordenaMerge(const DList<T>& original)
*
* Integra los dos metodos anteriores, a una manera mucho mas
* adecuada para el usuario
*
* @param const DList<T>& original
* return DList ya ordenada
*/

template <class T>
DList<T> Sorts<T>::ordenaMerge(const DList<T>& original) {
    DList<T> v(original);
    DList<T> tmp;
    for (int i = 0; i < v.size; i++) {
        tmp.add(T());
    }
    mergeSplit(v, tmp, 0, v.size - 1);
    return v;
}

/*
* ordenaProductos(DList<T> &tipo_ordenado, DList<T> &tipo,
* DList<string> &producto)
*
* Ordena la DList de los nombres de los productos en base al DList de
* precios/ventas/stocks previamente ordenado, basicamente, toma la DList
* ordenado y el original, con el fin de poder hallar el indice de ese
* producto y mediante este valor poder ordenar el DList de nombres en
* base a precio/ventas/stocks
*
* @param DList<T> &tipo_ordenado, DList<T> &tipo, DList<string> &producto
* return DList de nombres ordenado acorde a precio/venta/stock
*/

template <class T>
DList<string> Sorts<T>::ordenaProductos(DList<T> &tipo_ordenado,
DList<T> &tipo, DList<string> &producto) {
    DList<string> pro_ordenado;
    for (int i = 0; i < tipo_ordenado.getSize(); i++) {
        for (int j = 0; j < tipo_ordenado.getSize(); j++) {
            if (tipo_ordenado.get(i) == tipo.get(j)) {
                tipo.update(j, -1);
                pro_ordenado.add(producto.get(j));
                break;
            }
        }
    }
    return pro_ordenado;
}

#endif /* SORTS_H_ */
