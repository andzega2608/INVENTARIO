/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 01/10/2024
 * Version: 2
 *
 * Esta clase definida como Inventario contiene todas las operaciones
 * para agregar productos, asi tambien sirve para obtener listas doblemente
 * ligadas de nombre, precio, stock y venta de los productos con el fin de
 * poder ordenadorlos, con el metodo de ordenamiento elegido.
 */

#ifndef INVENTARIO_H_
#define INVENTARIO_H_
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "producto.h" // Biblioteca con objetos a usar
#include "dlist.h" // Biblioteca con las funciones de double linked list
using namespace std;

class Inventario {
private:
    DList<Producto> productos; // Lista doblemente ligada de productos
public:
    Inventario() {};  // Constructor vacío
    void cargarDatos();
    void agrega_producto(string, int, int, float);
    DList<string> obtener_nombres();
    DList<int> obtener_ventas();
    DList<int> obtener_stocks();
    DList<float> obtener_precios();
    string mostrarDatos(DList<string> &, DList<float> &, DList<int> &, DList<int> &);
    template <class T>
    string DListToString(DList<string> &product, DList<T> &tipo);
    string busqueda(DList<string> &, DList<float> &, DList<int> &, DList<int> &, string);
    void eliminar_product(DList<string> &, DList<float> &, DList<int> &, DList<int> &, string);
    template <class T>
    void actualizar_datos(DList<string> &, DList<T> &, string, T);
    string resumen(DList<float> &, DList<int> &);
    string escribirDatos(DList<string> &, DList<float> &, DList<int> &, DList<int> &);
    void escribir(DList<string> &, DList<float> &, DList<int> &, DList<int> &);
};

/*
* cargarDatos()
*
* El metodo se encarga de cargar los datos del archivo "Inventario.csv".
* Es importante mencionar que estos datos son inventados, por lo que no
* se debe usar este metodo si se va a usar el programa en produccion.
*
* @param
* @return
*/

void Inventario::cargarDatos() {
    ifstream archivo;
    archivo.open("Inventario.csv", ios::in);
    string linea, producto;
    int stock, venta;
    float precio;
     getline(archivo, linea);
    while (getline(archivo,linea)){
        stringstream ss(linea);
        getline(ss, producto, ',');
        ss >> venta;
        ss.ignore();
        ss >> stock;
        ss.ignore();
        ss >> precio;
        productos.add(Producto(producto, venta, stock, precio));
    }
    archivo.close();
}

/*
* agrega_producto(string nombre, int venta, int stock, float precio)
*
* Este metodo se encarga de crear un producto y añadirlo a la lista
* para ello se necesita el nombre, precio, venta y stock
*
* param nombre, precio, stock y venta
* @return
*/

void Inventario::agrega_producto(string producto, int venta, int stock, float precio) {
    productos.add(Producto(producto, venta, stock, precio));
}

/*
* Inventario::obtener_nombres()
*
* Este metodo se encarga de crear una lista con los nombres de los productos registrados
*
* @return DList<string> de nombres productos registrados
*/

DList<string> Inventario::obtener_nombres() {
    DList<string> nombres;
    DLink<Producto>* p = productos.head;
    while (p != 0) {
        nombres.add(p->value.getnombre());
        p = p->next;
    }
    return nombres;
}

/*
* Inventario::obtener_ventas()
*
* Este metodo se encarga de crear una lista con los numeros de ventas
* de cada producto
*
* @return DList<int> de ventas de cada producto registrado
*/

DList<int> Inventario::obtener_ventas() {
    DList<int> ventas;
    DLink<Producto>* p = productos.head;
    while (p != 0) {
        ventas.add(p->value.getventa());
        p = p->next;
    }
    return ventas;
}

/*
* Inventario::obtener_stocks()
*
* Este metodo se encarga de crear una lista con las unidades disponibles
* de cada producto (stocks)
*
* @return DList<int> del numero de unidades disponibles
*/

DList<int> Inventario::obtener_stocks() {
    DList<int> stocks;
    DLink<Producto>* p = productos.head;
    while (p != 0) {
        stocks.add(p->value.getstock());
        p = p->next;
    }
    return stocks;
}

/*
* Inventario::obtener_precios()
*
* Este metodo se encarga de crear una lista con precios establecidos
* de cada producto (stocks)
*
* @return DList<float> del precio de cada producto
*/

DList<float> Inventario::obtener_precios() {
    DList<float> precios;
    DLink<Producto>* p = productos.head;
    while (p != 0) {
        precios.add(p->value.getprecio());
        p = p->next;
    }
    return precios;
}

/*
* mostrarDatos(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks)
*
* Se encarga de mostrar de forma estética los productos que se tienen registrados
*
* param DList<string> &product, DList<float> &pre, DList<T> &vent, DList<T> &stks
* @return string con los productos y sus datos
*/

string Inventario::mostrarDatos(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks) {
    stringstream aux;
    aux << setw(20) << "Producto" << setw(10) << "Precio" << setw(10) << "Ventas" << setw(10) << "Stocks" << endl;
    for (int i = 0; i < product.getSize(); i++) {
        aux << setw(20) << product.get(i) << setw(10) << pre.get(i) << setw(10) << vent.get(i) << setw(10) << stks.get(i) << endl;
    }
    aux << endl;
    return aux.str();
}

/*
* DListToString(DList<string> &product, DList<T> &tipo)
*
* Se encarga de mostrar de forma estética los productos con su precio/venta/stock depende
* de lo que quiera el usuario
*
* param DList<string> &product, DList<T> &tipo
* @return string con los productos y precio/venta/stock
*/

template <class T>
string Inventario::DListToString(DList<string> &product, DList<T> &tipo) {
    stringstream aux;
    for (int i = 0; i < product.getSize(); i++) {
        aux << setw(20) << product.get(i) << setw(10) << tipo.get(i) << endl;
    }
    aux << endl;
    return aux.str();
}

/*
* busqueda(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto)
*
* Realiza una busqueda con el metodo search del archivo dlist.h
* devolviendo el indice del producto. Si el producto se encuentra
* en la DList, se muestra todos los datos del producto, caso contario
* muestra producto no encontrado.
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto
* @return string con datos del producto
*/

string Inventario::busqueda(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto){
    stringstream aux;
    int i = product.search(n_producto);
    if (i != -1){
        aux << "Producto encontrado: " << endl;
        aux << setw(20) << "Producto" << setw(10) << "Precio" << setw(10) << "Ventas" << setw(10) << "Stocks" << endl;
        aux << setw(20) << product.get(i) << setw(10) << pre.get(i) << setw(10)
        << vent.get(i) << setw(10) << stks.get(i) << endl;
    }
    else {
        aux << "Producto no encontrado";
    }
    aux << endl;
    return aux.str();
}

/*
* eliminar_product(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto)
*
* Realiza una busqueda con el metodo search del archivo dlist.h
* devolviendo el indice del producto. Si el producto se encuentra en la DList,
* elimina todos los datos del producto con el metodo remove del mismo archivo
* dlist.h.
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto
* @return
*/

void Inventario::eliminar_product(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto){
    int index = product.search(n_producto);
    product.remove(index);
    pre.remove(index);
    vent.remove(index);
    stks.remove(index);
}

/*
* actualizar_datos(DList<string> &product, DList<T> &tipo, string n_producto, T val)
*
* Cambia un dato de un producto en especifico (precio/venta/stock),
* para ello utiliza las funciones seach y update del archivo dlist.h.
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks, string n_producto
* @return
*/

template <class T>
void Inventario::actualizar_datos(DList<string> &product, DList<T> &tipo, string n_producto, T val){
    int index = product.search(n_producto);
    tipo.update(index, val);
}

/*
* resumen(DList<float> &pre, DList<int> &vent)
*
* Calcula el total de ventas realizadas y con la ganacia hasta
* el momento registrada.
*
* param DList<float> &pre, DList<int> &vent
* @return string con la informacion de ventas y ganancia
*/

string Inventario::resumen(DList<float> &pre, DList<int> &vent){
    stringstream aux;
    int n_ventas = 0; float total = 0.0;
    for (int i = 0; i < pre.getSize(); i++){
        n_ventas = n_ventas + vent.get(i);
        total = total + pre.get(i) * vent.get(i);
    }
    aux << fixed << setprecision(2);
    aux << "Cantidad de productos vendidos: " << n_ventas << endl;
    aux << "Total: " << total << "MXN" << endl;
    return aux.str();
}

/*
* escribirDatos(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks)
*
* Obtiene los datos de cada producto siguiendo el esquema
* Producto, Venta, Stock, Precio. Este metodo sirve para escribir
* las actualizaciones en el archivo "Inventario.csv".
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks
* @return string con los datos de cada producto
*/

string Inventario::escribirDatos(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks) {
    stringstream aux;
    aux<<"Productos, Ventas, Stocks, Precios"<<endl;
    for (int i = 0; i < product.getSize(); i++) {
        aux << product.get(i) << ", " << vent.get(i) << ", " << stks.get(i) << ", " << pre.get(i) << endl;
    }
    return aux.str();
}

/*
* escribir(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks)
*
* Escribe los datos actuaizados en el archivo "Temp.csv". Posterior a ello,
* elimina el archivo "Inventario.csv" y "Temp.csv" lo renombra de la misma
* manera, es decir, con el nombre de "Inventario.csv".
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks
* @return
*/


void Inventario::escribir(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks){
    ofstream archivo;
    archivo.open("Temp.csv", ios::out);
    string aux = escribirDatos(product, pre, vent, stks);
    archivo << aux;
    archivo.close();
    remove("Inventario.csv");
    rename("Temp.csv", "Inventario.csv");
}

#endif /* INVENTARIO_H_ */
