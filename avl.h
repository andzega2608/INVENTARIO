/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/10/2024
 * Version: 3
 *
 * El presente programa posee los metodos para poder trabajar con
 * estructura de datos no lineal como lo son los AVL. De esa forma,
 * este archivo avl.h posee todos los metodos necesarios. Mencionar
 * que se crearan dos AVL, el primero para ordenar los nodos en base
 * a la fecha y el segundo para ordenar los nodos en base a la
 * ganancia del dia
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template <class T> class AVL;

template <class T>
class Node {
private:
    string dia;
    int nro_ventas;
    float ganancia;
    Node *left, *right;
    int level, balance;
    Node<T>* predecesor();
public:
    Node(string, int, float);
    Node(string, int, float, Node<T>* le, Node<T>* ri, int lev, int bal);
    void addVentas(string, int, float);
    void addFecha(string, int, float);
    bool find(float);
    bool findFecha(string);
    void removeChilds();
    void inorder(std::stringstream &aux) const;
    void escribirFecha(std::stringstream &aux) const;
    void buscarFecha(std::stringstream &aux, string) const;
    int max_depth();
    Node<T>* check_tree(T *check_val, Node<T> *parent, bool *checked);
    Node<T>* check_treeFecha(T *check_val, Node<T> *parent, bool *checked);
    Node<T>* balance_tree();
    Node<T>* balance_treeFecha();
    Node<T>* rot_left(Node<T>* a);
    Node<T>* rot_right(Node<T>* a);
    Node<T>* rot_left_right(Node<T>* a);
    Node<T>* rot_right_left(Node<T>* a);
    friend class AVL<T>;
    friend class Inventario;
};

// Constructor por parametros
template <class T>
Node<T>::Node(string di, int ven, float ga)
    : dia(di), nro_ventas(ven), ganancia(ga), left(nullptr),
    right(nullptr), level(0), balance(0) {}

// Constructor por parametros
template <class T>
Node<T>::Node(string di, int ven, float ga, Node<T>* le,
              Node<T>* ri, int lev, int bal)
    : dia(di), nro_ventas(ven), ganancia(ga), left(le),
    right(ri), level(lev), balance(bal) {}

/*
* addVentas(string di, int ven, float ga)
*
* Crea una nuevo nodo y lo agrega al arbol que ordena
* los nodos acorde a la variable de ganancia
*
* param string di, int ven, float ga
* @return
*/

template <class T>
void Node<T>::addVentas(string di, int ven, float ga) {
    if (ga < ganancia) {
        if (left != nullptr) {
            left->addVentas(di, ven, ga);
        } else {
            left = new Node<T>(di, ven, ga);
        }
    } else {
        if (right != nullptr) {
            right->addVentas(di, ven, ga);
        } else {
            right = new Node<T>(di, ven, ga);
        }
    }
}

/*
* addFecha(string di, int ven, float ga)
*
* Crea una nuevo nodo y lo agrega al arbol que ordena
* los nodos acorde a la variable de dia
*
* param string di, int ven, float ga
* @return
*/

template <class T>
void Node<T>::addFecha(string di, int ven, float ga) {
    if (di < dia) {
        if (left != nullptr) {
            left->addFecha(di, ven, ga);
        } else {
            left = new Node<T>(di, ven, ga);
        }
    } else {
        if (right != nullptr) {
            right->addFecha(di, ven, ga);
        } else {
            right = new Node<T>(di, ven, ga);
        }
    }
}

/*
* find(float ga)
*
* Busca dentro del arbol de gananacia y revisa la ubicacion
* donde está ese nodo o deberia estar recordando que en AVL
* no se puede tener valores repetidos
*
* param float ga
* return true o false
*/

template <class T>
bool Node<T>::find(float ga) {
    if (ga == ganancia) {
        return true;
    } else if (ga < ganancia) {
        return (left != nullptr && left->find(ga));
    } else {
        return (right != nullptr && right->find(ga));
    }
}

/*
* findFecha(string di)
*
* Busca dentro del arbol de fecha y revisa la ubicacion
* donde está ese nodo o deberia estar recordando que en AVL
* no se puede tener valores repetidos
*
* param string di
* return true o false
*/

template <class T>
bool Node<T>::findFecha(string di) {
    if (di == dia) {
        return true;
    } else if (di < dia) {
        return (left != nullptr && left->findFecha(di));
    } else {
        return (right != nullptr && right->findFecha(di));
    }
}

/*
* predecesor()
*
* Encuentra el predecesor de un nodo con el fin de mantener
* la estructura del AVL al momento de realizar las rotaciones
*
* @param
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::predecesor() {
	Node<T> *le, *ri;
	le = left;
	ri = right;
	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}
	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}
	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

/*
* removeChilds()
*
* Vacia el arbol eliminando los respectivos nodos
*
* @param
* @return
*/

template <class T>
void Node<T>::removeChilds() {
    if (left != nullptr) {
        left->removeChilds();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->removeChilds();
        delete right;
        right = nullptr;
    }
}

/*
* inorder(std::stringstream &aux) const
*
* Concatena los valores de cada arbol en orden de manera ascendente
* en una variable aux de tipo stringstream
*
* param std::stringstream &aux
* @return
*/

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
    if (left != nullptr) {
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
        aux << " ";
    }
    aux << setw(20) << dia << setw(15) << nro_ventas << setw(20)
    << ganancia << endl;
    if (right != nullptr) {
        right->inorder(aux);
    }
}

/*
* escribirFecha(std::stringstream &aux) const
*
* Concatena los valores de cada arbol en orden de manera ascendente
* en una variable aux de tipo stringstream pero en formato
* para escribir en el archivo Fechas.csv
*
* param std::stringstream &aux
* @return
*/

template <class T>
void Node<T>::escribirFecha(std::stringstream &aux) const {
    if (left != nullptr) {
        left->escribirFecha(aux);
    }
    aux << dia << ", " << nro_ventas << ", " << ganancia << "\n";
    if (right != nullptr) {
        right->escribirFecha(aux);
    }
}

/*
* buscarFecha(std::stringstream &aux, string di) const
*
* Busca un dia en el AVL de fechas y en caso que exista, concatena
* los valores de fecha, ventas y ganancia de ese día
*
* param std::stringstream &aux, string di
* @return
*/

template <class T>
void Node<T>::buscarFecha(std::stringstream &aux, std::string di) const {
    if (di == dia) {
        aux << setw(20) << dia << setw(20) << nro_ventas << setw(20)
        << ganancia << endl;
    } else if (di < dia) {
        if (left != nullptr) {
            left->buscarFecha(aux, di);
        }
    } else {
        if (right != nullptr) {
            right->buscarFecha(aux, di);
        }
    }
}

/*
* max_depth
*
* Calcula la maxima profundidad de cada nodo, para poder revisar
* si el arbol se esta degenerando
*
* @param
* return maximo nivel del AVL
*/

template <class T>
int Node<T>::max_depth() {
    int le = 0, ri = 0;
    if (left != nullptr)
        le = left->max_depth() + 1;
    if (right != nullptr)
        ri = right->max_depth() + 1;
    if (le > ri)
        level = le;
    else
        level = ri;
    balance = le - ri;
    return level;
}

/*
* check_tree(T *check_val, Node<T> *parent, bool *checked)
*
* Revisa si el arbol de ganancia no se encuentra denegenerado,
* si se encuentra, realiza las rotaciones pertienentes para
* que se encuentre balanceado
*
* param T *check_val, Node<T> *parent, bool *checked
* return Node<T>*
*/
template <class T>
Node<T>* Node<T>::check_tree(T *check_val, Node<T> *parent, bool *checked) {
    int leftDepth;
    if (this->left != nullptr) {
        leftDepth = this->left->max_depth();
    } else {
        leftDepth = 0;
    }
    int rightDepth;
    if (this->right != nullptr) {
        rightDepth = this->right->max_depth();
    } else {
        rightDepth = 0;
    }
    this->balance = leftDepth - rightDepth;
    if (this->balance > 1 || this->balance < -1) {
        *check_val = this->ganancia;
        *checked = true;
        Node<T>* newRoot = this->balance_tree();
        if (parent != nullptr) {
            if (parent->left == this) {
                parent->left = newRoot;
            } else {
                parent->right = newRoot;
            }
        }
        return newRoot;
    }
    if (this->left != nullptr) {
        this->left->check_tree(check_val, this, checked);
    }
    if (this->right != nullptr) {
        this->right->check_tree(check_val, this, checked);
    }
    return this;
}

/*
* check_treeFecha(T *check_val, Node<T> *parent, bool *checked)
*
* Revisa si el arbol de fechas no se encuentra denegenerado,
* si se encuentra, realiza las rotaciones pertienentes para
* que se encuentre balanceado
*
* param T *check_val, Node<T> *parent, bool *checked
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::check_treeFecha(T *check_val,
                                  Node<T> *parent, bool *checked) {
    int leftDepth;
    if (this->left != nullptr) {
        leftDepth = this->left->max_depth();
    } else {
        leftDepth = 0;
    }
    int rightDepth;
    if (this->right != nullptr) {
        rightDepth = this->right->max_depth();
    } else {
        rightDepth = 0;
    }
    this->balance = leftDepth - rightDepth;
    if (this->balance > 1 || this->balance < -1) {
        *check_val = this->dia;
        *checked = true;
        Node<T>* newRoot = this->balance_treeFecha();
        if (parent != nullptr) {
            if (parent->left == this) {
                parent->left = newRoot;
            } else {
                parent->right = newRoot;
            }
        }
        return newRoot;
    }
    if (this->left != nullptr) {
        this->left->check_treeFecha(check_val, this, checked);
    }
    if (this->right != nullptr) {
        this->right->check_treeFecha(check_val, this, checked);
    }
    return this;
}


/*
* balance_tree()
*
* Cuando el arbol de ganancia se encuentre degenerado, realiza
* las rotaciones dependiendo si el balance es positivo o
* negativo, si es positivo, hace una rotación a la derecha,
* caso contrario a la izquierda
*
* @param
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::balance_tree() {
    Node<T> *a = this, *le =left, *ri =right;
	float old_value = ganancia;
	if (balance > 0) {
		if (le->balance > 0){
			a = rot_right(a);
		}
		else{
			a = rot_left_right(a);
		}
	}
	else{
		if (ri->balance < 0){
			a = rot_left(a);
		}
		else{
			a = rot_right_left(a);
		}
	}
	return a;
}

/*
* balance_tree()
*
* Cuando el arbol de fechas se encuentre degenerado, realiza las
* rotaciones dependiendo si el balance es positivo o negativo,
* si es positivo, hace una rotación a la derecha, caso contrario
* a la izquierda
*
* @param
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::balance_treeFecha() {
    Node<T> *a = this, *le =left, *ri =right;
	string old_value = dia;
	if (balance > 0) {
		if (le->balance > 0){
			a = rot_right(a);
		}
		else{
			a = rot_left_right(a);
		}
	}
	else{
		if (ri->balance < 0){
			a = rot_left(a);
		}
		else{
			a = rot_right_left(a);
		}
	}
	return a;
}

/*
* rot_left(Node<T>* a)
*
* Realiza la rotacion a la izquierda
*
* param Node<T>* a
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* a) {
    Node<T> *b, *aux;
    if (a->right != nullptr) {
        b = a->right;
        if (b->left != nullptr) {
            aux = b->left;
            a->right = aux;
        } else {
            a->right = nullptr;
        }
        b->left = a;
    }
    return b;
}

/*
* rot_right(Node<T>* a)
*
* Realiza la rotacion a la derecha
*
* param Node<T>* a
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* a) {
    Node<T> *b, *aux;
    if (a->left != nullptr) {
        b = a->left;
        if (b->right != nullptr) {
            aux = b->right;
            a->left = aux;
        } else {
            a->left = nullptr;
        }
        b->right = a;
    }
    return b;
}

/*
* rot_left_right(Node<T>* a)
*
* Realiza una doble rotacion a la izquierda y luego a la derecha
*
* param Node<T>* a
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::rot_left_right(Node<T>* a) {
    a->left = rot_left(a->left);
    return rot_right(a);
}

/*
* rot_right_left(Node<T>* a)
*
* Realiza una doble rotacion a la derecha y luego a la izquierda
*
* param Node<T>* a
* return Node<T>*
*/

template <class T>
Node<T>* Node<T>::rot_right_left(Node<T>* a) {
    a->right = rot_right(a->right);
    return rot_left(a);
}

template <class T>
class AVL {
private:
    Node<T> *root;

public:
    AVL();
    ~AVL();
    bool empty() const;
    void addVentas(string, int, float);
    void addFecha(string, int, float);
    bool find(float) const;
    bool findFecha(string) const;
    void removeAll();
    std::string inorder() const;
    std::string escribirFecha() const;
    std::string buscarFecha(string) const;
    friend class Inventario;
};

// Constructor por default
template <class T>
AVL<T>::AVL() : root(nullptr) {}

// Destructor
template <class T>
AVL<T>::~AVL() {
    removeAll();
}

/*
* empty() const
*
* Revisa si el arbol esta vacio
*
* @param
* return true o false
*/

template <class T>
bool AVL<T>::empty() const {
    return (root == nullptr);
}

/*
* addVentas(string di, int ven, float ga)
*
* Revisa si ya existe un nodo con una ganancia igual, ya que como no
* puede existir valores repetidos, primero busca si el valor es permitido
* luego lo añade dentro del arbol y hace las rotaciones correspondientes
* en caso de necesitar
*
* param string di, int ven, float ga
* @return
*/

template <class T>
void AVL<T>::addVentas(string di, int ven, float ga) {
    if (root != nullptr) {
        if (!root->find(ga)) {
            Node<T> *temp;
            T check_val = false;
            bool aux = false;
            root->addVentas(di, ven, ga);
            root->max_depth();
            temp = root->check_tree(&check_val, nullptr, &aux);
            if (check_val == root->ganancia) {
                root = temp;
            }
        }
    } else {
        root = new Node<T>(di, ven, ga);
    }
}

/*
* addVentas(string di, int ven, float ga)
*
* Revisa si ya existe un nodo con una fecha igual, ya que como no
* puede existir valores repetidos, primero busca si el valor es permitido
* luego lo añade dentro del arbol y hace las rotaciones correspondientes
* en caso de necesitar
*
* param string di, int ven, float ga
* @return
*/

template <class T>
void AVL<T>::addFecha(string di, int ven, float ga) {
    if (root != nullptr) {
        if (!root->findFecha(di)) {
            Node<T> *temp;
            T check_val = T();
            bool aux = false;
            root->addFecha(di, ven, ga);
            root->max_depth();
            temp = root->check_treeFecha(&check_val, nullptr, &aux);
            if (check_val == root->dia) {
                root = temp;
            }
        }
    } else {
        root = new Node<T>(di, ven, ga);
    }
}

/*
* removeAll()
*
* Vacia todo el AVL eliminando todos los nodos
*
* @param
* @return
*/

template <class T>
void AVL<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = nullptr;
}

/*
* find(float gan) const
*
* Revisa si existe un nodo con una ganancia especifica
*
* param float gan
* return true o false
*/

template <class T>
bool AVL<T>::find(float gan) const {
    if (root != nullptr) {
        return root->find(gan);
    }
    return false;
}

/*
* find(string di) const
*
* Revisa si existe un nodo con una fecha especifica
*
* param string di
* return true o false
*/

template <class T>
bool AVL<T>::findFecha(string di) const {
    if (root != nullptr) {
        return root->findFecha(di);
    }
    return false;
}

/*
* inorder() const
*
* Concatena todos los datos de cada nodo
*
* @param
* return estring con los datos ordenados de manera ascendente
*/

template <class T>
std::string AVL<T>::inorder() const {
    std::stringstream aux;
    if (root != nullptr) {
        root->inorder(aux);
    }
    return aux.str();
}

/*
* escribirFecha() const
*
* Concatena todos los datos de cada nodo para escribir en el
* archivo Fechas.csv
*
* @param
* return estring con los datos ordenados de manera ascendente con formato
*/

template <class T>
std::string AVL<T>::escribirFecha() const {
    std::stringstream aux;
    if (root != nullptr) {
        root->escribirFecha(aux);
    }
    return aux.str();
}

/*
* buscarFecha(string di) const
*
* Busca una fecha específica, una vez que la encuentra concatena sus datos
* en un string. Si no escuentra manda un mensaje de no encontrado
*
* param string di
* return estring con los datos de la fecha encontrada
*/

template <class T>
std::string AVL<T>::buscarFecha(string di) const {
    std::stringstream aux;
    if ((root != nullptr) && (root->findFecha(di))) {
        aux << "Fecha encontrada" << endl;
        aux << setw(20) << "Fecha" << setw(20) << "Ventas" << setw(20)
        << "Ganancia" << endl;
        root->buscarFecha(aux, di);
    } else {
        aux << "Fecha no encontrada" << endl;
    }
    return aux.str();
}

#endif // AVL_H_
