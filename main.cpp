/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/08/2024
 * Version: 1
 *
 * El presente programa hace referencia a un algoritmo el cual se encarga de capturar
 * distintos productos y los ordena acorde a su precio, del mas caro al mas barato,
 * segun las unidades que se tienen disponible y segun las ventas que se han generado
 * de cada producto en el mes. Adicional a estas funciones, el proyecto es capaz de
 * añadir productos.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include "sorts.h" // Biblioteca con los metodos de ordenamiento
#include "inventario.h" // Biblioteca con las clases del proyecto

using namespace std;

/*
* mostrarDatos(vector<string> &product, vector<float> &pre, vector<T> &vent, vector<T> &stks)
*
* Se encarga de mostrar de forma estetica los productos que se tienen registrados
*
* param vector<string> &product, vector<float> &pre, vector<T> &vent, vector<T> &stks
* @return string con los productos
*/

template <class T>
string mostrarDatos(vector<string> &product, vector<float> &pre, vector<T> &vent, vector<T> &stks) {
	stringstream aux;
	aux<<setw(20)<<"Producto"<<setw(10)<<"Precio"<<setw(10)<<"Ventas"<<setw(10)<<"Stocks"<<endl;
	for (int i = 0; i < product.size(); i++) {
		aux<<setw(20)<<product[i]<<setw(10)<<pre[i]<<setw(10)<<vent[i]<<setw(10)<<stks[i]<<endl;
	}
	aux<<endl;
	return aux.str();
}

/*
* arrayToString(vector<string> &product, vector<T> &tipo)
*
* Se encarga de mostrar de forma estetica los productos con su precio/venta/stock depende
* de lo que quiera el usuario
*
* param vector<string> &product, vector<T> &tipo
* @return string con los productos y precio/venta/stock
*/

template <class T>
string arrayToString(vector<string> &product, vector<T> &tipo) {
	stringstream aux;
	for (int i = 0; i < tipo.size(); i++) {
		aux<<setw(20)<<product[i]<<setw(10)<<tipo[i]<<endl;
	}
	aux<<endl;
	return aux.str();
}

int main() {
    Inventario inventario;
    inventario.crea_ejemplos();
    vector<int> ventas = inventario.obtener_ventas();
    vector<float> precios = inventario.obtener_precios();
    vector<int> stocks = inventario.obtener_stocks();
    vector<string> productos = inventario.obtener_nombres();
	vector<string> pro_ordenado(productos.size());
	bool continua = true; int opcion;
	while (continua == true) {
        Sorts<int> sorts;
        string nombre; int venta, stock; float precio;
        vector<int> aux_ventas = ventas;
        vector<float> aux_precios = precios;
        vector<int> aux_stocks = stocks;
        cout<<"1. Mostrar datos"<<endl;
        cout<<"2. Agregar producto."<<endl;
        cout<<"3. Mostrar por Precio."<<endl;
        cout<<"4. Mostrar por Venta."<<endl;
        cout<<"5. Mostrar por Stock."<<endl;
        cout<<"6. Salir. "<<endl;
        cout<<"Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        system("cls");
        if (opcion == 1) {
            cout<<mostrarDatos(productos, precios, ventas, stocks);
        }
        else if (opcion == 2){
            cout<<"Ingresa los datos correspondientes"<<endl;
            // Se usa getline porque existen productos como Pan Integral que utilizan espacio
            cout<<"Nombre del producto: "; getline(cin, nombre);
            cout<<"Precio: "; cin>>precio;
            cout<<"Stock: "; cin>>stock;
            cout<<"Venta: "; cin>>venta;
            cin.ignore();
            inventario.agrega_producto(nombre, venta, stock, precio);
            productos = inventario.obtener_nombres();
            ventas = inventario.obtener_ventas();
            stocks = inventario.obtener_stocks();
            precios = inventario.obtener_precios();
        }
        else if (opcion == 3) {
            Sorts<float> sorts;
            cout<<"Productos ordenados acorde al precio de manera descendente"<<endl;
            vector<float> pre_ordenado = sorts.ordenaMerge(precios);
            pro_ordenado = sorts.ordenaProductos(pre_ordenado, precios, productos);
            cout<<arrayToString(pro_ordenado, pre_ordenado);
        }
        else if (opcion == 4) {
            cout<<"Productos ordenados acorde a las ventas de manera descendente"<<endl;
            vector<int> ven_ordenado = sorts.ordenaMerge(ventas);
            pro_ordenado = sorts.ordenaProductos(ven_ordenado, ventas, productos);
            cout<<arrayToString(pro_ordenado, ven_ordenado);
        }
        else if (opcion == 5) {
            cout<<"Productos ordenados acorde al stock de manera descendente"<<endl;
            vector<int> sto_ordenado = sorts.ordenaMerge(stocks);
            pro_ordenado = sorts.ordenaProductos(sto_ordenado, stocks, productos);
            cout<<arrayToString(pro_ordenado, sto_ordenado);
        }
        else if (opcion == 6) {
            cout<<"Muchas Gracias" << endl;
            continua = false;
        }
        else {
            cout<<"Opcion invalida. Elige de nuevo." << endl;
        }
    }
}
