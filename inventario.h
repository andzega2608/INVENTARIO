/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/08/2024
 * Version: 1
 *
 * Esta clase definida como Inventario contiene todas las operaciones
 * para agregar productos, asi tambien sirve para obtener vectores de nombre,
 * precio, stock y venta de los productos con el fin de poder ordenadorlos,
 * con el metodo de ordenamiento elegido.
 */

#ifndef INVENTARIO_H_
#define INVENTARIO_H_
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Producto.h" // Biblioteca con objetos a usar
using namespace std;

const int MAX = 200; // Constante de tamaño de arreglos

class Inventario {
private:
    Producto productos[MAX];
    int pos;
public:
    Inventario() : pos(0) {}; // Se declara constructor por default
    void crea_ejemplos();
    void agrega_producto(string, int, int, float);
    vector<string> obtener_nombres();
    vector<int> obtener_ventas();
    vector<int> obtener_stocks();
    vector<float> obtener_precios();
};

/*
* crea_ejemplos()
*
* El metodo se encarga de crear objetos en el vector proctos[] con el fin de poder hacer
* pruebas y que el programa posea algunos ejemplos y que no este vacio. Es importante
* mencionar que estos ejemplos son datos inventados, por lo que no se debe usar este
* metodo si se va a usar el programa en produccion.
*
* @param
* @return
*/

void Inventario::crea_ejemplos() {
    productos[pos] = Producto("Pan", 50, 100, 1.56);
    pos++;
    productos[pos] = Producto("Leche", 30, 80, 0.99);
    pos++;
    productos[pos] = Producto("Huevos", 20, 60, 2.97);
    pos++;
    productos[pos] = Producto("Arroz", 15, 40, 0.86);
    pos++;
    productos[pos] = Producto("Pasta", 25, 70, 1.24);
    pos++;
    productos[pos] = Producto("Azucar", 10, 50, 1.11);
    pos++;
    productos[pos] = Producto("Aceite", 8, 30, 4.58);
    pos++;
    productos[pos] = Producto("Cafe", 12, 40, 3.75);
    pos++;
    productos[pos] = Producto("Te", 18, 55, 2.58);
    pos++;
    productos[pos] = Producto("Cereal", 22, 90, 3.35);
    pos++;
    productos[pos] = Producto("Mantequilla", 9, 25, 2.79);
    pos++;
    productos[pos] = Producto("Queso", 14, 35, 4.28);
    pos++;
    productos[pos] = Producto("Yogurt", 28, 60, 1.14);
    pos++;
    productos[pos] = Producto("Carne Pollo", 6, 20, 6.63);
    pos++;
    productos[pos] = Producto("Carne Res", 5, 15, 8.45);
    pos++;
    productos[pos] = Producto("Manzanas", 40, 100, 1.41);
    pos++;
    productos[pos] = Producto("Banana", 35, 90, 0.63);
    pos++;
    productos[pos] = Producto("Zanahoria", 27, 70, 1.98);
    pos++;
    productos[pos] = Producto("Cebolla", 23, 80, 1.59);
    pos++;
    productos[pos] = Producto("Tomate", 19, 60, 2.49);
    pos++;
}

/*
* agrega_producto(string nombre, int venta, int stock, float precio)
*
* Este metodo se encarga de crear un producto, para ello se necesita el nombre,
* precio, venta y stock
*
* param nombre, precio, stock y venta
* @return
*/

void Inventario::agrega_producto(string nombre, int venta, int stock, float precio) {
    productos[pos] = Producto(nombre, venta, stock, precio);
    pos++;
}

/*
* Inventario::obtener_nombres()
*
* Este metodo se encarga de crear un vector con los nombres de los productos registrados
*
* @return vector<string> de nombres productos registrados
*/

vector<string> Inventario::obtener_nombres() {
    vector<string> v_nombres;
    for (int i = 0; i < pos; i++) {
        v_nombres.push_back(productos[i].getnombre());
    }
    return v_nombres;
}

/*
* Inventario::obtener_ventas()
*
* Este metodo se encarga de crear un vector con los numeros de ventas
* de cada producto
*
* @return vector<int> de ventas de cada producto registrado
*/

vector<int> Inventario::obtener_ventas() {
    vector<int> v_ventas;
    for (int i = 0; i < pos; i++) {
        v_ventas.push_back(productos[i].getventa());
    }
    return v_ventas;
}

/*
* Inventario::obtener_stocks()
*
* Este metodo se encarga de crear un vector con las unidades disponibles
* de cada producto (stocks)
*
* @return vector<int> del numero de unidades disponibles
*/

vector<int> Inventario::obtener_stocks() {
    vector<int> v_stocks;
    for (int i = 0; i < pos; i++) {
        v_stocks.push_back(productos[i].getstock());
    }
    return v_stocks;
}

/*
* Inventario::obtener_precios()
*
* Este metodo se encarga de crear un vector con precios establecidos
* de cada producto (stocks)
*
* @return vector<float> del precio de cada producto
*/

vector<float> Inventario::obtener_precios() {
    vector<float> v_precios;
    for (int i = 0; i < pos; i++) {
        v_precios.push_back(productos[i].getprecio());
    }
    return v_precios;
}

#endif /* INVENTARIO_H_ */
