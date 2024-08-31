/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/08/2024
 * Version: 1
 *
 * El presente programa posee los metodos de ordenamiento para poder
 * ordenar los productos en base a su precio, venta o disponibilidad.
 * Para ello, este archivo sorts.h posee el metoodo de ordenamiento Merge.
 */

#ifndef SORTS_H_
#define SORTS_H_
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Sorts {
private:
    void swap(vector<T>&, int, int);
    void copyArray(vector<T>&, vector<T>&, int, int);
    void mergeArray(vector<T>&, vector<T>&, int, int, int);
    void mergeSplit(vector<T>&, vector<T>&, int, int);
public:
    vector<T> ordenaMerge(const vector<T>&);
    vector<string> ordenaProductos(vector<T>&, vector<T>&, vector<string>&);
};

/*
* swap(vector<T> &v, int i, int j)
*
* Cambia dos valores dentro de un vector
*
* @param vector<T> &v, int i, int j
* return
*/

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/*
* copyArray(vector<T> &A, vector<T> &B, int low, int high)
*
* Copia el contenido de un array a otro
*
* @param vector<T> &A, vector<T> &B, int low, int high
* return
*/

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

/*
* mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high)
*
* Se encarga de ordenar el vector, basicamente hace el procedimiento
* del metodo Merge
*
* @param vector<T> &A, vector<T> &B, int low, int mid, int high
* return
*/

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (A[i] > A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }
}

/*
* mergeSplit(vector<T> &A, vector<T> &B, int low, int high)
*
* Se encarga de dividir el vector en pequeñas partes, para luego
* hacer el merge, ordenamiento correspondiente
*
* @param vector<T> &A, vector<T> &B, int low, int high
* return
*/

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    int mid;
    if ((high - low) < 1) {
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

/*
* ordenaMerge(const vector<T>& original)
*
* Integra los dos metodos anteriores, a una manera mucho mas
* adecuada para el usuario
*
* @param const vector<T>& original
* return v el vector ya ordenado
*/

template <class T>
vector<T> Sorts<T>::ordenaMerge(const vector<T>& original) {
    vector<T> v(original);
    vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

/*
* ordenaProductos(vector<T> &tipo_ordenado, vector<T> &tipo, vector<string> &producto)
*
* Ordena el vector nombres de los productos en base al vector de precios/ventas/stocks
* previamente ordenado, basicamente, toma el vector ordenado y el original, con el fin
* de poder hallar el indice de ese producto y mediante este valor poder ordenar el vector
* de nombres en base a precio/ventas/stocks
*
* @param vector<T> &tipo_ordenado, vector<T> &tipo, vector<string> &producto
* return vector de nombres ordenado acorde a precio/venta/stock
*/

template <class T>
vector<string> Sorts<T>::ordenaProductos(vector<T> &tipo_ordenado, vector<T> &tipo, vector<string> &producto) {
    vector<string> pro_ordenado(tipo_ordenado.size());
    for (int i = 0; i < tipo_ordenado.size(); i++) {
        for (int j = 0; j < tipo_ordenado.size(); j++) {
            if (tipo_ordenado[i] == tipo[j]) {
                tipo[j] = -1; // Cambia el valor de -1 en caso que existan repetidos
                pro_ordenado[i] = producto[j];
                break;
            }
        }
    }
    return pro_ordenado;
}

#endif /* SORTS_H_ */
