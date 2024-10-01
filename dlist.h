/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 01/10/2024
 * Version: 2
 *
 * El presente programa posee los metodos para poder trabajar con estructura de
 * datos lineal como lo son las listas doblementes enlazadas. De esa forma, este
 * archivo dlist.h posee todos los metodos necesarios.
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

class Inventario; // Se declara la clase Inventario
template <class T> class DList;
template <class T> class Sorts;

template <class T>
class DLink {
private:
    DLink(T);
    DLink(T, DLink<T>*, DLink<T>*);
    DLink(const DLink<T>&);
    T value;
    DLink<T> *previous;
    DLink<T> *next;
    /*Se declaran clases amigas para que se puedan acceder a los atributos
    y metodos privados de la clase DLink*/
    friend class DList<T>;
    friend class Inventario;
};

// Constructor por default
template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

// Constructor por parametros
template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

// Constructor por copia
template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
private:
    DLink<T> *head;
    DLink<T> *tail;
    int size;
public:
    DList();
    DList(const DList<T>&);
    DList<T>& operator=(const DList<T>&);
    /*
        * getSize()
        * @param
        * return tamano de la lista
    */
    int getSize() { return size; }
    void add(T);
    int search(T);
    void update(int, T);
    void remove(int);
    T get(int);
    friend class Sorts<T>;
    friend class Inventario;
};

// Constructor por default
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

// Constructor por copia
template <class T>
DList<T>::DList(const DList<T>& original) : head(0), tail(0), size(0) {
    DLink<T>* current = original.head;
    while (current != 0) {
        this->add(current->value);
        current = current->next;
    }
}

/*
* operator=(const DList<T>& original)
*
* Permite poder realizar la asignacion de DList A = DList B
*
* param Lista doblemente enlazada original
* @return copia de la lista original
*/

template <class T>
DList<T>& DList<T>::operator=(const DList<T>& original) {
    if (this != &original) {
        this->~DList();
        head = tail = 0;
        size = 0;
        DLink<T>* current = original.head;
        while (current != 0) {
            this->add(current->value);
            current = current->next;
        }
    }
    return *this;
}

/*
* void add(T val)
*
* Inserta el valor al final de la lista doblemente enlazada
*
* param T val
* @return
*/

template <class T>
void DList<T>::add(T val) {
    DLink<T> *p = new DLink<T>(val);
    if (head == 0 && tail == 0) {
        head = p;
        tail = p;
    } else {
        p->previous = tail;
        tail->next = p;
        tail = p;
    }
    size++;
}

/*
* int search(T val)
*
* Retorna el valor del indice del valor dentro de la
* lista, si no se encuentra el valor, retorna -1
*
* param T val
* @return indice del valor dentro de la lista
*/

template <class T>
int DList<T>::search(T val){
    int c1 = 0;
    int c2 = size - 1;
    DLink<T> *p = head;
    DLink<T> *q = tail;
    while (p != q){
        if (p->value == val){
            return c1;
        }
        p = p->next;
        c1 = c1 + 1;
        if (q->value == val){
            return c2;
        }
        q = q->previous;
        c2 = c2 - 1;
    }
    return -1;
}

/*
* void update(int index, T val)
*
* Cambia el valor de un dato dentro de la lista acorde a su indice
*
* param indice del elemento dentro de la lista y su valor a cambiar
* @return
*/

template <class T>
void DList<T>::update(int index, T val) {
    DLink<T> *p;
    int c;
    int aux = size / 2;
    if (index <= aux) {
        p = head;
        c = 0;
        while (c != index) {
            p = p->next;
            c = c + 1;
        }
    } else {
        p = tail;
        c = size - 1;
        while (c != index) {
            p = p->previous;
            c = c - 1;
        }
    }
    p->value = val;
}

/*
* void remove(int index)
*
* Elima el valor dentro de la lista acorde a su indice
*
* param indice del elemento a eliminar
* @return
*/

template <class T>
void DList<T>::remove(int index) {
    DLink<T> *p;
    if (head == tail) {
        delete head;
        head = 0;
        tail = 0;
    } else {
        if (index == 0) {
            p = head;
            head = head->next;
            head->previous = 0;
            delete p;
        } else if (index == (size - 1)) {
            p = tail;
            tail = tail->previous;
            tail->next = 0;
            delete p;
        } else {
            int c;
            int aux = size / 2;
            if (index <= aux) {
                p = head;
                c = 0;
                while (c != index) {
                    p = p->next;
                    c = c + 1;
                }
                p->previous->next = p->next;
                p->next->previous = p->previous;
            } else {
                p = tail;
                c = size - 1;
                while (c != index) {
                    p = p->previous;
                    c = c - 1;
                }
                p->next->previous = p->previous;
                p->previous->next = p->next;
            }
            delete p;
        }
    }
    size--;
}

/*
* T get(int index)
*
* Retorna el valor en la posicion del indice en la lista
*
* param indice
* @return valor que se encuentra en ese indice
*/

template <class T>
T DList<T>::get(int index) {
    DLink<T> *p;
    int c;
    int aux = size / 2;
    if (index <= aux) {
        p = head;
        c = 0;
        while (c != index) {
            p = p->next;
            c = c + 1;
        }
    } else {
        p = tail;
        c = size - 1;
        while (c != index) {
            p = p->previous;
            c = c + 1;
        }
    }
    return p->value;
}

#endif /* DLIST_H_ */
