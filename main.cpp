/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/10/2024
 * Version: 3
 *
 * El presente programa hace referencia a un algoritmo el cual se
 * encarga de capturar distintos productos y los ordena acorde a
 * su precio, del mas caro al mas barato, segun las unidades que
 * se tienen disponible y segun las ventas que se han generado de
 * cada producto en el mes. Adicional a estas funciones,
 * el proyecto es capaz de añadir productos, eliminar y cambiar
 * algunos datos de cada producto usando una estrcutura de datos
 * lineal como lo son las listas doblemente enlazadas. Adicional a
 * ello, el programa usa AVL para poder estructurar la informacion
 * de ventas y ganancias por dia. Asi tambien mediante esta estrcutura
 * se puede agregar nuevas fechas y realizar una
 * busqueda de una fecha especifica.
 */

#include <iostream>
#include <string>
#include <sstream>
#include "sorts.h"
#include "inventario.h"
using namespace std;

int main() {
    Inventario inventario;
    inventario.cargarDatos();
    inventario.cargarDatosFecha();
    DList<int> ventas = inventario.obtener_ventas();
    DList<float> precios = inventario.obtener_precios();
    DList<int> stocks = inventario.obtener_stocks();
    DList<string> productos = inventario.obtener_nombres();
    DList<string> pro_ordenado;
    bool continua = true;
    int opcion;
    while (continua) {
        Sorts<int> sorts;
        DList<int> aux_ventas = ventas;
        DList<int> aux_stocks = stocks;
        DList<float> aux_precios = precios;
        cout << "BIENVENIDO A SUPERMARKET" << endl;
        cout << "1. Mostrar datos" << endl;
        cout << "2. Agregar producto." << endl;
        cout << "3. Mostrar por precio." << endl;
        cout << "4. Mostrar por venta." << endl;
        cout << "5. Mostrar por stock." << endl;
        cout << "6. Buscar producto." << endl;
        cout << "7. Eliminar producto." << endl;
        cout << "8. Cambiar datos de un producto. " << endl;
        cout << "9. Resumen de ganancia y ventas." << endl;
        cout << "10. Resumen de ganancia y ventas por dia." << endl;
        cout << "11. Mostrar dia por ganancia." << endl;
        cout << "12. Agregar dia." << endl;
        cout << "13. Buscar por dia" << endl;
        cout << "14. Salir." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        system("cls");
        if (opcion == 1) {
            cout << inventario.mostrarDatos(productos, precios,
            ventas, stocks);
        }
        else if (opcion == 2){
            string nombre; int venta, stock; float precio;
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
        else if (opcion == 3){
            Sorts<float> sorts;
            cout << "Productos ordenados acorde al precio" << endl;
            DList<float> pre_ordenado = sorts.ordenaMerge(precios);
            pro_ordenado = sorts.ordenaProductos(pre_ordenado,
            aux_precios, productos);
            cout << inventario.ToString(pro_ordenado, pre_ordenado);
        }
        else if (opcion == 4){
            cout << "Productos ordenados acorde a las ventas" << endl;
            DList<int> ven_ordenado = sorts.ordenaMerge(ventas);
            pro_ordenado = sorts.ordenaProductos(ven_ordenado,
            aux_ventas, productos);
            cout << inventario.ToString(pro_ordenado, ven_ordenado);
        }
        else if (opcion == 5){
            cout << "Productos ordenados acorde al stock" << endl;
            DList<int> sto_ordenado = sorts.ordenaMerge(stocks);
            pro_ordenado = sorts.ordenaProductos(sto_ordenado,
            aux_stocks, productos);
            cout << inventario.ToString(pro_ordenado, sto_ordenado);
        }
        else if (opcion == 6){
            string n_producto;
            cout << "Ingresa el nombre del producto a buscar" << endl;
            cout << "Nombre del producto: "; getline(cin, n_producto);
            cout << inventario.busqueda(productos, precios, ventas,
            stocks, n_producto);
            cout << endl;
        }
        else if (opcion == 7){
            string e_producto;
            cout << "Ingresa el nombre del producto a eliminar" << endl;
            cout << "Nombre del producto: "; getline(cin, e_producto);
            int n_pro = productos.search(e_producto); int opcion2;
            cout << endl;
            if (n_pro != -1){
                cout << "Se eliminara el producto "
                << productos.get(n_pro) << endl;
                cout << "Ingrese 1 si es correcto: "; cin>>opcion2;
                if (opcion2 == 1){
                    inventario.eliminar_product(productos, precios,
                    ventas, stocks, e_producto);
                    cout << "Producto eliminado. " << endl;
                }
                else {
                    cout << "El producto no se ha eliminado. " << endl;
                }
            }
            else {
                cout << "Producto no encontrado. ";
                cout << "No es posible eliminar un producto inexistente.";
                cout << endl;
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
                    inventario.actualizar_datos(productos, precios,
                    n_pro2, precio2);
                    cout << "Precio actualizado" << endl;
                }
                else if (opcion3 == 2){
                    int stock2;
                    cout << "Ingrese el nuevo stock: "; cin>>stock2;
                    inventario.actualizar_datos(productos, stocks,
                    n_pro2, stock2);
                    cout << "Stock actualizado" << endl;
                }
                else if (opcion3 == 3){
                    int venta2;
                    cout << "Ingrese el nuevo numero de ventas: ";
                    cin>>venta2;
                    inventario.actualizar_datos(productos, ventas,
                    n_pro2, venta2);
                    cout << "Numero de ventas actualizado" << endl;
                }
                else {
                    cout << "No se ha realizado ninguna actualizacion";
                    cout << endl;
                }
            }
            else {
                cout << "Producto no encontrado. ";
                cout << "No es posible actualizar un producto inexistente.";
                cout << endl;
            }
        }
        else if (opcion == 9){
            cout << "Resumen de ganancia y ventas." << endl;
            cout<< inventario.resumen(precios, ventas);
        }
        else if (opcion == 10){
            cout << "Resumen de ganancia y ventas por dia" << endl;
            cout << inventario.mostrarFecha() << endl;
        }
        else if (opcion == 11){
            cout << "Dias ordenados acorde a la ganancia" << endl;
            cout << inventario.mostrarFechaVenta() << endl;
        }
        else if (opcion == 12){
            string fe; int ven; float gan;
            cout << "Ingresa los datos correspondientes" << endl;
            cout << "Fecha (DD-MM-AA): "; cin >> fe;
            cout << "Ventas: "; cin >> ven;
            cout << "Ganancia: "; cin >> gan;
            cin.ignore();
            inventario.agregaFecha(fe, ven, gan);
        }
        else if (opcion == 13) {
            string fech;
            cout << "Ingresa la fecha a buscar" << endl;
            cout << "Fecha (DD-MM-AA): "; cin >> fech;
            cout<< inventario.mostrarPorDia(fech);
            cout << endl;
        }
        else if (opcion == 14) {
            inventario.escribirDatos(productos, precios, ventas, stocks);
            inventario.escribirDatosDia();
            cout << "Muchas Gracias." << endl;
            continua = false;
            productos.clear(); ventas.clear();
            stocks.clear(); precios.clear();
        }
        else {
            cout << "Opcion invalida. Elige de nuevo." << endl;
        }
    }
}
