/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 13/10/2024
 * Version: 2
 *
 * Esta clase definida como Producto contiene los atributos como el nombre
 * precio, venta y stock de cada producto registrado en la tienda. Del mismo
 * modo se tienen algunos getter y constructores para poder inicializar los
 * objetos creados.
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Producto {
    private:
        string nombre;
        int venta;
        int stock;
        float precio;
    public:
        Producto();
        Producto(string, int, int, float);
        /*
        * getnombre()
        * @param
        * return nombre del producto
        */
        string getnombre(){return nombre;};
        /*
        * getventa()
        * @param
        * return ventas del producto
        */
        int getventa(){return venta;};
        /*
        * getstock()
        * @param
        * return unidades disponibles
        */
        int getstock(){return stock;};
        /*
        * getprecio()
        * @param
        * return precio del producto
        */
        float getprecio(){return precio;};
};

Producto::Producto(){ // Constructor por default
}

/*
* Producto(string _nombre, int _venta, int _stock, float _precio)
*
* Constructor que recibe todos los atributos de la clase
*
* param nombre, venta, stock, precio
* @return
*/

Producto::Producto(string _nombre, int _venta, int _stock, float _precio){
    nombre = _nombre;
    venta = _venta;
    stock = _stock;
    precio = _precio;
}
#endif // PRODUCTO_H
