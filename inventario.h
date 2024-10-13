/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 13/10/2024
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
#include "producto.h"
#include "dlist.h"
#include "avl.h"
using namespace std;

class Inventario {
    private:
        DList<Producto> productos;
        AVL<float> fechas_ventas;
        AVL<string> fechas;
    public:
        Inventario() {}; // Constructor vacío
        // Metodos para el archivo Inventario.csv
        void cargarDatos();
        void agrega_producto(string, int, int, float);
        DList<string> obtener_nombres();
        DList<int> obtener_ventas();
        DList<int> obtener_stocks();
        DList<float> obtener_precios();
        string mostrarDatos(DList<string> &, DList<float> &, DList<int> &, DList<int> &);
        template <class T>
        string ToString(DList<string> &product, DList<T> &tipo);
        string busqueda(DList<string> &, DList<float> &, DList<int> &, DList<int> &, string);
        void eliminar_product(DList<string> &, DList<float> &, DList<int> &, DList<int> &, string);
        template <class T>
        void actualizar_datos(DList<string> &, DList<T> &, string, T);
        string resumen(DList<float> &, DList<int> &);
        void escribirDatos(DList<string> &, DList<float> &, DList<int> &, DList<int> &);
        // Metodos para el archivo Fechas.csv
        void cargarDatosFecha();
        void agregaFecha(string, int, float);
        string mostrarFecha();
        string mostrarFechaVenta();
        void escribirDatos();
        string mostrarPorDia(string);
        void escribirDatosDia();
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
* obtener_nombres()
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
* obtener_ventas()
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
* obtener_stocks()
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
* obtener_precios()
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
    aux << setw(20) << "Producto" << setw(10) << "Precio" << setw(10) << "Ventas"
    << setw(10) << "Stocks" << endl;
    for (int i = 0; i < product.getSize(); i++) {
        aux << setw(20) << product.get(i) << setw(10) << pre.get(i) << setw(10)
        << vent.get(i) << setw(10) <<
        stks.get(i) << endl;
    }
    aux << endl;
    return aux.str();
}

/*
* ToString(DList<string> &product, DList<T> &tipo)
*
* Se encarga de mostrar de forma estética los productos con su precio/venta/stock depende
* de lo que quiera el usuario
*
* param DList<string> &product, DList<T> &tipo
* @return string con los productos y precio/venta/stock
*/

template <class T>
string Inventario::ToString(DList<string> &product, DList<T> &tipo) {
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
        aux << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
        << "Ventas" << setw(10) << "Stocks" << endl;
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
* escribir(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks)
*
* Escribe los datos actualizados en el archivo "Temp.csv". Posterior a ello,
* elimina el archivo "Inventario.csv" y "Temp.csv" lo renombra de la misma
* manera, es decir, con el nombre de "Inventario.csv".
*
* param DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks
* @return
*/

void Inventario::escribirDatos(DList<string> &product, DList<float> &pre, DList<int> &vent, DList<int> &stks){
    stringstream aux;
    aux<<"Productos, Ventas, Stocks, Precios"<<endl;
    for (int i = 0; i < product.getSize(); i++) {
        aux << product.get(i) << ", " << vent.get(i) << ", " << stks.get(i) << ", " << pre.get(i) << endl;
    }
    ofstream archivo;
    archivo.open("Temp.csv", ios::out);
    archivo << aux.str();
    archivo.close();
    remove("Inventario.csv");
    rename("Temp.csv", "Inventario.csv");
}

/*
* cargarDatosFecha()
*
* El metodo se encarga de cargar los datos del archivo "Fechas.csv".
* Es importante mencionar que estos datos son inventados, por lo que no
* se debe usar este metodo si se va a usar el programa en produccion.
*
* @param
* @return
*/

void Inventario::cargarDatosFecha() {
    ifstream archivo;
    archivo.open("Fechas.csv", ios::in);
    string linea, fecha;
    int venta;
    float ganancia;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, fecha, ',');
        ss >> venta;
        ss.ignore();
        ss >> ganancia;
        fechas_ventas.addVentas(fecha, venta, ganancia);
        fechas.addFecha(fecha, venta, ganancia);
    }
    archivo.close();
}

/*
* agregaFecha(string fecha, int nro_venta, float ganancia)
*
* Este metodo se encarga de crear una fecha y añadirlo a dos AVL, el primero
* ordena por fecha y el segundo ordena por ganancia para ello se necesita el
* fehca (DD-MM-AA), nro_ventas y ganancia
*
* param fehca (DD-MM-AA), nro_ventas y ganancia
* @return
*/

void Inventario::agregaFecha(string fecha, int nro_venta, float ganancia) {
    fechas_ventas.addVentas(fecha, nro_venta, ganancia);
    fechas.addFecha(fecha, nro_venta, ganancia);
}

/*
* mostrarFecha()
*
* Se encarga de mostrar los datos ordenados por fecha
*
* param
* @return string con los datos de ventas y ganancia ordenados por dia
*/

string Inventario::mostrarFecha() {
    stringstream aux;
    aux << setw(20) << "Fecha" << setw(20) << "Nro. Ventas" << setw(20) << "Ganancia MXN" << endl;
    aux << fechas.inorder();
    aux << endl;
    return aux.str();
}

/*
* mostrarFechaVenta()
*
* Se encarga de mostrar los datos ordenados por ganancia de manera ascendente
*
* param
* @return string con los datos ordenados acorde a ganancia por dia
*/

string Inventario::mostrarFechaVenta() {
    stringstream aux;
    aux << setw(20) << "Fecha" << setw(20) << "Nro. Ventas" << setw(20) << "Ganancia MXN" << endl;
    aux << fechas_ventas.inorder();
    aux << endl;
    return aux.str();
}

/*
* mostrarPorDia(string di)
*
* Realiza una busqueda con el metodo buscarFecha del archivo avl.h
* devolviendo los datos correspondientes. Si el producto no se encuentra
* muestra fecha no encontrada.
*
* param string di
* @return datos de la fecha a buscar
*/

string Inventario::mostrarPorDia(string di){
    stringstream aux;
    aux << fechas.buscarFecha(di) << endl;
    return aux.str();
}

/*
* escribirDatosDia()
*
* Escribe los datos actualizados en el archivo "Temp2.csv". Posterior a ello,
* elimina el archivo "Fechas.csv" y "Temp2.csv" lo renombra de la misma
* manera, es decir, con el nombre de "Fecha.csv".
*
* param
* @return
*/

void Inventario::escribirDatosDia() {
    stringstream aux;
    aux << "Fechas, Nro Ventas, Ganancia" << endl;
    aux << fechas.escribirFecha();
    ofstream archivo;
    archivo.open("Temp2.csv", ios::out);
    archivo << aux.str();
    archivo.close();
    remove("Fechas.csv");
    rename("Temp2.csv", "Fechas.csv");
}

#endif /* INVENTARIO_H_ */
