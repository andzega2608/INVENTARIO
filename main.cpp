/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 01/10/2024
 * Version: 2
 *
 * El presente programa hace referencia a un algoritmo el cual se encarga de capturar
 * distintos productos y los ordena acorde a su precio, del mas caro al mas barato,
 * segun las unidades que se tienen disponible y segun las ventas que se han generado
 * de cada producto en el mes. Adicional a estas funciones, el proyecto es capaz de
 * añadir productos, eliminar y cambiar algunos datos de cada producto usando una
 * estrcutura de datos lineal como lo son las listas doblemente enlazadas.
 */

#include <iostream>
#include <string>
#include <sstream>
#include "sorts.h" // Biblioteca con los métodos de ordenamiento
#include "inventario.h" // Biblioteca con las clases del proyecto

using namespace std;

int main() {
    Inventario inventario;
    inventario.cargarDatos();
    DList<int> ventas = inventario.obtener_ventas();
    DList<float> precios = inventario.obtener_precios();
    DList<int> stocks = inventario.obtener_stocks();
    DList<string> productos = inventario.obtener_nombres();
    DList<string> pro_ordenado;
    bool continua = true;
    int opcion;
    while (continua) {
        Sorts<int> sorts;
        string nombre;
        int venta, stock;
        float precio;
        DList<int> aux_ventas = ventas;
        DList<int> aux_stocks = stocks;
        DList<float> aux_precios = precios;
        cout << "\n1. Mostrar datos" << endl;
        cout << "2. Agregar producto." << endl;
        cout << "3. Mostrar por Precio." << endl;
        cout << "4. Mostrar por Venta." << endl;
        cout << "5. Mostrar por Stock." << endl;
        cout << "6. Buscar producto." << endl;
        cout << "7. Eliminar producto." << endl;
        cout << "8. Cambiar datos de un producto: " << endl;
        cout << "9. Resumen de ganancia y ventas." << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        system("cls");
        if (opcion == 1) {
            cout << inventario.mostrarDatos(productos, precios, ventas, stocks);
        }
        else if (opcion == 2) {
            cout << "Ingresa los datos correspondientes" << endl;
            cout << "Nombre del producto: "; getline(cin, nombre);
            cout << "Precio: "; cin >> precio;
            cout << "Stock: "; cin >> stock;
            cout << "Venta: "; cin >> venta;
            cin.ignore();
            inventario.agrega_producto(nombre, venta, stock, precio);
            productos.add(nombre);
            ventas.add(venta);
            stocks.add(stock);
            precios.add(precio);
        }
        else if (opcion == 3) {
            Sorts<float> sorts;
            cout << "Productos ordenados acorde al precio de manera descendente" << endl;
            DList<float> pre_ordenado = sorts.ordenaMerge(precios);
            pro_ordenado = sorts.ordenaProductos(pre_ordenado, aux_precios, productos);
            cout << inventario.DListToString(pro_ordenado, pre_ordenado);
        }
        else if (opcion == 4) {
            cout << "Productos ordenados acorde a las ventas de manera descendente" << endl;
            DList<int> ven_ordenado = sorts.ordenaMerge(ventas);
            pro_ordenado = sorts.ordenaProductos(ven_ordenado, aux_ventas, productos);
            cout << inventario.DListToString(pro_ordenado, ven_ordenado);
        }
        else if (opcion == 5) {
            cout << "Productos ordenados acorde al stock de manera descendente" << endl;
            DList<int> sto_ordenado = sorts.ordenaMerge(stocks);
            pro_ordenado = sorts.ordenaProductos(sto_ordenado, aux_stocks, productos);
            cout << inventario.DListToString(pro_ordenado, sto_ordenado);
        }
        else if (opcion == 6){
            string n_producto;
            cout << "Ingresa el nombre del producto a buscar" << endl;
            cout << "Nombre del producto: "; getline(cin, n_producto);
            cout << inventario.busqueda(productos, precios, ventas, stocks, n_producto);
            cout << endl;
        }
        else if (opcion == 7){
            string e_producto;
            cout << "Ingresa el nombre del producto a eliminar" << endl;
            cout << "Nombre del producto: "; getline(cin, e_producto);
            int n_pro = productos.search(e_producto); int opcion2;
            cout << endl;
            if (n_pro != -1){
                cout << "Se eliminara el producto " << productos.get(n_pro) << endl;
                cout << "Ingrese 1 si es correcto: "; cin>>opcion2;
                if (opcion2 == 1){
                    inventario.eliminar_product(productos, precios, ventas, stocks, e_producto);
                    cout << "Producto eliminado. " << endl;
                }
                else {
                    cout << "El producto no se ha eliminado. " << endl;
                }
            }
            else {
                cout << "Producto no encontrado. No es posible eliminar un producto inexistente." << endl;
            }
        }
        else if (opcion == 8){
            int opcion3;
            string n_pro2;
            cout << "Ingrese el nombre del producto: "; getline(cin, n_pro2);
            if (productos.search(n_pro2) != -1){
                cout << endl;
                cout << "1. Actualizar precio" << endl;
                cout << "2. Actualizar stock." << endl;
                cout << "3. Actualizar venta." << endl;
                cout << "4. Salir." << endl;
                cout << "Ingrese una opcion: "; cin>>opcion3;
                if (opcion3 == 1){
                    float precio2;
                    cout << "Ingrese el nuevo precio: "; cin>>precio2;
                    inventario.actualizar_datos(productos, precios, n_pro2, precio2);
                    cout << "Precio actualizado" << endl;
                }
                else if (opcion3 == 2){
                    int stock2;
                    cout << "Ingrese el nuevo stock: "; cin>>stock2;
                    inventario.actualizar_datos(productos, stocks, n_pro2, stock2);
                    cout << "Stock actualizado" << endl;
                }
                else if (opcion3 == 3){
                    int venta2;
                    cout << "Ingrese el nuevo numero de ventas: "; cin>>venta2;
                    inventario.actualizar_datos(productos, ventas, n_pro2, venta2);
                    cout << "Numero de ventas actualizado" << endl;
                }
                else {
                    cout << "No se ha realizado ninguna actualizacion" << endl;
                }
            }
            else {
                cout << "Producto no encontrado. No es posible actualizar un producto inexistente." << endl;
            }
        }
        else if (opcion == 9){
            cout << "Resumen de ganancia y ventas." << endl;
            cout<< inventario.resumen(precios, ventas);
        }
        else if (opcion == 10) {
            inventario.escribir(productos, precios, ventas, stocks);
            cout << "Muchas Gracias." << endl;
            continua = false;
        }
        else {
            cout << "Opcion invalida. Elige de nuevo." << endl;
        }
    }
}
