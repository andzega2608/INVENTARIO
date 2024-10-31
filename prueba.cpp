/*
 * Proyecto Inventario de Productos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 31/10/2024
 * Version: 3
 *
 * El presente trabajo posee todos los casos de prueba del correcto
 * funcionamiento del programa. A continuación, se muestran todos los
 * los casos de prueba
 */


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "sorts.h"
#include "inventario.h"
using namespace std;

int main(int argc, char* argv[]) {
    Inventario inventario;
    inventario.cargarDatos();
    inventario.cargarDatosFecha();
    DList<int> ventas = inventario.obtener_ventas();
    DList<float> precios = inventario.obtener_precios();
    DList<int> stocks = inventario.obtener_stocks();
    DList<string> productos = inventario.obtener_nombres();

    // Caso 1. Mostrar Datos
    stringstream aux1;
    aux1 << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
    << "Ventas" << setw(10) << "Stocks" << endl;
    aux1 << setw(20) << "Manzanas" << setw(10) << 49.99 << setw(10)
    << 150 << setw(10) << 50 << endl;
    aux1 << setw(20) << "Naranjas" << setw(10) << 59.75 << setw(10)
    << 200 << setw(10) << 75 << endl;
    aux1 << setw(20) << "Bananas" << setw(10) << 29.30 << setw(10)
    << 300 << setw(10) << 100 << endl;
    aux1 << setw(20) << "Leche" << setw(10) << 24.15 << setw(10)
    << 120 << setw(10) << 30 << endl;
    aux1 << setw(20) << "Pan" << setw(10) << 19.45 << setw(10)
    << 180 << setw(10) << 25 << endl;
    aux1 << setw(20) << "Huevos" << setw(10) << 39.60 << setw(10)
    << 90  << setw(10) << 60 << endl;
    aux1 << setw(20) << "Arroz" << setw(10) << 34.80 << setw(10)
    << 60  << setw(10) << 20 << endl;
    aux1 << setw(20) << "Pasta" << setw(10) << 29.95 << setw(10)
    << 250 << setw(10) << 140 << endl;
    aux1 << setw(20) << "Tomates" << setw(10) << 44.25 << setw(10)
    << 110 << setw(10) << 80 << endl;
    aux1 << setw(20) << "Pollo" << setw(10) << 119.80 << setw(10)
    << 75 << setw(10) << 15 << endl;
    aux1 << setw(20) << "Pescado" << setw(10) << 179.20 << setw(10)
    << 50  << setw(10) << 10 << endl;
    aux1 << setw(20) << "Carne de res" << setw(10) << 149.15 << setw(10)
    << 40 << setw(10) << 12 << endl;
    aux1 << setw(20) << "Zanahorias" << setw(10) << 14.85 << setw(10)
    << 130 << setw(10) << 45 << endl;
    aux1 << setw(20) << "Cebollas" << setw(10) << 9.95  << setw(10)
    << 160 << setw(10) << 55 << endl;
    aux1 << setw(20) << "Patatas" << setw(10) << 24.10 << setw(10)
    << 210 << setw(10) << 90 << endl;
    aux1 << setw(20) << "Aceite de oliva" << setw(10) << 99.65 << setw(10)
    << 80  << setw(10) << 20 << endl;
    aux1 << setw(20) << "Azucar" << setw(10) << 14.55 << setw(10)
    << 220 << setw(10) << 100 << endl;
    aux1 << setw(20) << "Cafe" << setw(10) << 79.25 << setw(10)
    << 95  << setw(10) << 35 << endl;
    aux1 << setw(20) << "Te" << setw(10) << 58.85 << setw(10)
    << 120 << setw(10) << 40 << endl;
    aux1 << setw(20) << "Galletas" << setw(10) << 39.70 << setw(10)
    << 190 << setw(10) << 70 << endl;
    aux1 << setw(20) << "Jugo de naranja" << setw(10) << 49.45 << setw(10)
    << 130 << setw(10) << 30 << endl;
    aux1 << setw(20) << "Yogur" << setw(10) << 24.90 << setw(10)
    << 140 << setw(10) << 60 << endl;
    aux1 << setw(20) << "Frutos secos" << setw(10) << 199.55 << setw(10)
    << 80 << setw(10) << 25 << endl;
    aux1 << setw(20) << "Cereal" << setw(10) << 69.15 << setw(10) << 210
    << setw(10) << 55 << endl;
    aux1 << setw(20) << "Chocolate" << setw(10) << 34.90 << setw(10) << 170
    << setw(10) << 45 << endl;
    aux1 << setw(20) << "Oreo" << setw(10) << 12.23 << setw(10) << 96
    << setw(10) << 78 << endl;
    aux1 << setw(20) << "Nutella" << setw(10) << 45.69 << setw(10) << 36
    << setw(10) << 78 << endl;
    aux1 << setw(20) << "Aguacate" << setw(10) << 65.78 << setw(10) << 33
    << setw(10) << 133 << endl;
    aux1 << endl;

    // Caso 1. Mostrar datos
    string aux2 = aux1.str();
    cout << "Caso 1: " << ((aux2 == inventario.mostrarDatos(productos,
    precios, ventas, stocks)) ? "success\n" : "fail\n");

    // Caso 2. Ingresar un nuevo producto
    inventario.agrega_producto("Sabritas", 120, 80, 45.66);
    productos.add("Sabritas");
    ventas.add(120);
    stocks.add(80);
    precios.add(45.66);
    stringstream aux3;
    aux3 << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
    << "Ventas" << setw(10) << "Stocks" << endl;
    aux3 << setw(20) << "Manzanas" << setw(10) << 49.99 << setw(10)
    << 150 << setw(10) << 50 << endl;
    aux3 << setw(20) << "Naranjas" << setw(10) << 59.75 << setw(10)
    << 200 << setw(10) << 75 << endl;
    aux3 << setw(20) << "Bananas" << setw(10) << 29.30 << setw(10)
    << 300 << setw(10) << 100 << endl;
    aux3 << setw(20) << "Leche" << setw(10) << 24.15 << setw(10)
    << 120 << setw(10) << 30 << endl;
    aux3 << setw(20) << "Pan" << setw(10) << 19.45 << setw(10)
    << 180 << setw(10) << 25 << endl;
    aux3 << setw(20) << "Huevos" << setw(10) << 39.60 << setw(10)
    << 90  << setw(10) << 60 << endl;
    aux3 << setw(20) << "Arroz" << setw(10) << 34.80 << setw(10)
    << 60  << setw(10) << 20 << endl;
    aux3 << setw(20) << "Pasta" << setw(10) << 29.95 << setw(10)
    << 250 << setw(10) << 140 << endl;
    aux3 << setw(20) << "Tomates" << setw(10) << 44.25 << setw(10)
    << 110 << setw(10) << 80 << endl;
    aux3 << setw(20) << "Pollo" << setw(10) << 119.80 << setw(10)
    << 75 << setw(10) << 15 << endl;
    aux3 << setw(20) << "Pescado" << setw(10) << 179.20 << setw(10)
    << 50  << setw(10) << 10 << endl;
    aux3 << setw(20) << "Carne de res" << setw(10) << 149.15 << setw(10)
    << 40 << setw(10) << 12 << endl;
    aux3 << setw(20) << "Zanahorias" << setw(10) << 14.85 << setw(10)
    << 130 << setw(10) << 45 << endl;
    aux3 << setw(20) << "Cebollas" << setw(10) << 9.95  << setw(10)
    << 160 << setw(10) << 55 << endl;
    aux3 << setw(20) << "Patatas" << setw(10) << 24.10 << setw(10)
    << 210 << setw(10) << 90 << endl;
    aux3 << setw(20) << "Aceite de oliva" << setw(10) << 99.65 << setw(10)
    << 80  << setw(10) << 20 << endl;
    aux3 << setw(20) << "Azucar" << setw(10) << 14.55 << setw(10)
    << 220 << setw(10) << 100 << endl;
    aux3 << setw(20) << "Cafe" << setw(10) << 79.25 << setw(10)
    << 95  << setw(10) << 35 << endl;
    aux3 << setw(20) << "Te" << setw(10) << 58.85 << setw(10)
    << 120 << setw(10) << 40 << endl;
    aux3 << setw(20) << "Galletas" << setw(10) << 39.70 << setw(10)
    << 190 << setw(10) << 70 << endl;
    aux3 << setw(20) << "Jugo de naranja" << setw(10) << 49.45 << setw(10)
    << 130 << setw(10) << 30 << endl;
    aux3 << setw(20) << "Yogur" << setw(10) << 24.90 << setw(10)
    << 140 << setw(10) << 60 << endl;
    aux3 << setw(20) << "Frutos secos" << setw(10) << 199.55 << setw(10)
    << 80 << setw(10) << 25 << endl;
    aux3 << setw(20) << "Cereal" << setw(10) << 69.15 << setw(10)
    << 210 << setw(10) << 55 << endl;
    aux3 << setw(20) << "Chocolate" << setw(10) << 34.90 << setw(10)
    << 170 << setw(10) << 45 << endl;
    aux3 << setw(20) << "Oreo" << setw(10) << 12.23 << setw(10)
    << 96  << setw(10) << 78 << endl;
    aux3 << setw(20) << "Nutella" << setw(10) << 45.69 << setw(10)
    << 36  << setw(10) << 78 << endl;
    aux3 << setw(20) << "Aguacate" << setw(10) << 65.78 << setw(10)
    << 33  << setw(10) << 133 << endl;
    aux3 << setw(20) << "Sabritas" << setw(10) << 45.66 << setw(10)
    << 120  << setw(10) << 80 << endl;
    aux3 << endl;
    string aux4 = aux3.str();
    cout << "Caso 2: " << ((aux4 == inventario.mostrarDatos(productos,
    precios, ventas, stocks)) ? "success\n" : "fail\n");

    // Caso 3 Ordenar por precio
    DList<string> pro_ordenado;
    DList<int> aux_ventas = ventas;
    DList<int> aux_stocks = stocks;
    DList<float> aux_precios = precios;
    stringstream aux5;
    aux5 << setw(20) << "Frutos secos" << setw(10) << 199.55 << endl;
    aux5 << setw(20) << "Pescado" << setw(10) << 179.20 << endl;
    aux5 << setw(20) << "Carne de res" << setw(10) << 149.15 << endl;
    aux5 << setw(20) << "Pollo" << setw(10) << 119.80 << endl;
    aux5 << setw(20) << "Aceite de oliva" << setw(10) << 99.65 << endl;
    aux5 << setw(20) << "Cafe" << setw(10) << 79.25 << endl;
    aux5 << setw(20) << "Cereal" << setw(10) << 69.15 << endl;
    aux5 << setw(20) << "Aguacate" << setw(10) << 65.78 << endl;
    aux5 << setw(20) << "Naranjas" << setw(10) << 59.75 << endl;
    aux5 << setw(20) << "Te" << setw(10) << 58.85 << endl;
    aux5 << setw(20) << "Manzanas" << setw(10) << 49.99 << endl;
    aux5 << setw(20) << "Jugo de naranja" << setw(10) << 49.45 << endl;
    aux5 << setw(20) << "Nutella" << setw(10) << 45.69 << endl;
    aux5 << setw(20) << "Sabritas" << setw(10) << 45.66 << endl;
    aux5 << setw(20) << "Tomates" << setw(10) << 44.25 << endl;
    aux5 << setw(20) << "Galletas" << setw(10) << 39.70 << endl;
    aux5 << setw(20) << "Huevos" << setw(10) << 39.60 << endl;
    aux5 << setw(20) << "Chocolate" << setw(10) << 34.90 << endl;
    aux5 << setw(20) << "Arroz" << setw(10) << 34.80 << endl;
    aux5 << setw(20) << "Pasta" << setw(10) << 29.95 << endl;
    aux5 << setw(20) << "Bananas" << setw(10) << 29.30 << endl;
    aux5 << setw(20) << "Yogur" << setw(10) << 24.90 << endl;
    aux5 << setw(20) << "Leche" << setw(10) << 24.15 << endl;
    aux5 << setw(20) << "Patatas" << setw(10) << 24.10 << endl;
    aux5 << setw(20) << "Pan" << setw(10) << 19.45 << endl;
    aux5 << setw(20) << "Zanahorias" << setw(10) << 14.85 << endl;
    aux5 << setw(20) << "Azucar" << setw(10) << 14.55 << endl;
    aux5 << setw(20) << "Oreo" << setw(10) << 12.23 << endl;
    aux5 << setw(20) << "Cebollas" << setw(10) << 9.95 << endl;
    aux5 << endl;
    string aux6 = aux5.str();
    Sorts<float> sorts2;
    DList<float> pre_ordenado = sorts2.ordenaMerge(precios);
    pro_ordenado = sorts2.ordenaProductos(pre_ordenado,
    aux_precios, productos);
    cout << "Caso 3: " << ((aux6 == inventario.ToString(pro_ordenado,
    pre_ordenado)) ? "success\n" : "fail\n");

    // Caso 4 Ordenar por venta
    stringstream aux7;
    aux7 << setw(20) << "Bananas" << setw(10) << 300 << endl;
    aux7 << setw(20) << "Pasta" << setw(10) << 250 << endl;
    aux7 << setw(20) << "Azucar" << setw(10) << 220 << endl;
    aux7 << setw(20) << "Patatas" << setw(10) << 210 << endl;
    aux7 << setw(20) << "Cereal" << setw(10) << 210 << endl;
    aux7 << setw(20) << "Naranjas" << setw(10) << 200 << endl;
    aux7 << setw(20) << "Galletas" << setw(10) << 190 << endl;
    aux7 << setw(20) << "Pan" << setw(10) << 180 << endl;
    aux7 << setw(20) << "Chocolate" << setw(10) << 170 << endl;
    aux7 << setw(20) << "Cebollas" << setw(10) << 160 << endl;
    aux7 << setw(20) << "Manzanas" << setw(10) << 150 << endl;
    aux7 << setw(20) << "Yogur" << setw(10) << 140 << endl;
    aux7 << setw(20) << "Zanahorias" << setw(10) << 130 << endl;
    aux7 << setw(20) << "Jugo de naranja" << setw(10) << 130 << endl;
    aux7 << setw(20) << "Leche" << setw(10) << 120 << endl;
    aux7 << setw(20) << "Te" << setw(10) << 120 << endl;
    aux7 << setw(20) << "Sabritas" << setw(10) << 120 << endl;
    aux7 << setw(20) << "Tomates" << setw(10) << 110 << endl;
    aux7 << setw(20) << "Oreo" << setw(10) << 96 << endl;
    aux7 << setw(20) << "Cafe" << setw(10) << 95 << endl;
    aux7 << setw(20) << "Huevos" << setw(10) << 90 << endl;
    aux7 << setw(20) << "Aceite de oliva" << setw(10) << 80 << endl;
    aux7 << setw(20) << "Frutos secos" << setw(10) << 80 << endl;
    aux7 << setw(20) << "Pollo" << setw(10) << 75 << endl;
    aux7 << setw(20) << "Arroz" << setw(10) << 60 << endl;
    aux7 << setw(20) << "Pescado" << setw(10) << 50 << endl;
    aux7 << setw(20) << "Carne de res" << setw(10) << 40 << endl;
    aux7 << setw(20) << "Nutella" << setw(10) << 36 << endl;
    aux7 << setw(20) << "Aguacate" << setw(10) << 33 << endl;
    aux7 << endl;
    string aux8 = aux7.str();
    Sorts<int> sorts;
    DList<int> ven_ordenado = sorts.ordenaMerge(ventas);
    pro_ordenado = sorts.ordenaProductos(ven_ordenado, aux_ventas,
    productos);
    cout << "Caso 4: " << ((aux8 == inventario.ToString(pro_ordenado,
    ven_ordenado)) ? "success\n" : "fail\n");

    // Caso 5 Ordenar por stock
    stringstream aux9;
    aux9 << setw(20) << "Pasta" << setw(10) << 140 << endl;
    aux9 << setw(20) << "Aguacate" << setw(10) << 133 << endl;
    aux9 << setw(20) << "Bananas" << setw(10) << 100 << endl;
    aux9 << setw(20) << "Azucar" << setw(10) << 100 << endl;
    aux9 << setw(20) << "Patatas" << setw(10) << 90 << endl;
    aux9 << setw(20) << "Tomates" << setw(10) << 80 << endl;
    aux9 << setw(20) << "Sabritas" << setw(10) << 80 << endl;
    aux9 << setw(20) << "Oreo" << setw(10) << 78 << endl;
    aux9 << setw(20) << "Nutella" << setw(10) << 78 << endl;
    aux9 << setw(20) << "Naranjas" << setw(10) << 75 << endl;
    aux9 << setw(20) << "Galletas" << setw(10) << 70 << endl;
    aux9 << setw(20) << "Huevos" << setw(10) << 60 << endl;
    aux9 << setw(20) << "Yogur" << setw(10) << 60 << endl;
    aux9 << setw(20) << "Cebollas" << setw(10) << 55 << endl;
    aux9 << setw(20) << "Cereal" << setw(10) << 55 << endl;
    aux9 << setw(20) << "Manzanas" << setw(10) << 50 << endl;
    aux9 << setw(20) << "Zanahorias" << setw(10) << 45 << endl;
    aux9 << setw(20) << "Chocolate" << setw(10) << 45 << endl;
    aux9 << setw(20) << "Te" << setw(10) << 40 << endl;
    aux9 << setw(20) << "Cafe" << setw(10) << 35 << endl;
    aux9 << setw(20) << "Leche" << setw(10) << 30 << endl;
    aux9 << setw(20) << "Jugo de naranja" << setw(10) << 30 << endl;
    aux9 << setw(20) << "Pan" << setw(10) << 25 << endl;
    aux9 << setw(20) << "Frutos secos" << setw(10) << 25 << endl;
    aux9 << setw(20) << "Arroz" << setw(10) << 20 << endl;
    aux9 << setw(20) << "Aceite de oliva" << setw(10) << 20 << endl;
    aux9 << setw(20) << "Pollo" << setw(10) << 15 << endl;
    aux9 << setw(20) << "Carne de res" << setw(10) << 12 << endl;
    aux9 << setw(20) << "Pescado" << setw(10) << 10 << endl;
    aux9 << endl;
    string aux10 = aux9.str();
    DList<int> sto_ordenado = sorts.ordenaMerge(stocks);
    pro_ordenado = sorts.ordenaProductos(sto_ordenado, aux_stocks,
    productos);
    cout << "Caso 5: " << ((aux10 == inventario.ToString(pro_ordenado,
    sto_ordenado)) ? "success\n" : "fail\n");

    // Caso 6. Busqueda de un producto
    stringstream aux11;
    aux11 << "Producto encontrado: " << endl;
    aux11 << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
    << "Ventas" << setw(10) << "Stocks" << endl;
    aux11 << setw(20) << "Chocolate" << setw(10) << 34.90 << setw(10)
    << 170 << setw(10) << 45 << endl;
    aux11 << endl;
    string aux12 = aux11.str();
    cout << "Caso 6: " << ((aux12 == inventario.busqueda(productos,
    precios, ventas, stocks, "Chocolate")) ? "success\n" : "fail\n");

    // Caso 7. Busqueda de un producto no existente
    stringstream aux13;
    aux13 << "Producto no encontrado" << endl;
    string aux14 = aux13.str();
    cout << "Caso 7: " << ((aux14 == inventario.busqueda(productos,
    precios, ventas, stocks, "Sandias")) ? "success\n" : "fail\n");

    // Caso 8 Eliminacion de un producto
    inventario.eliminar_product(productos, precios, ventas,
    stocks, "Zanahorias");
    stringstream aux15;
    aux15 << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
    << "Ventas" << setw(10) << "Stocks" << endl;
    aux15 << setw(20) << "Manzanas" << setw(10) << 49.99 << setw(10)
    << 150 << setw(10) << 50 << endl;
    aux15 << setw(20) << "Naranjas" << setw(10) << 59.75 << setw(10)
    << 200 << setw(10) << 75 << endl;
    aux15 << setw(20) << "Bananas" << setw(10) << 29.30 << setw(10)
    << 300 << setw(10) << 100 << endl;
    aux15 << setw(20) << "Leche" << setw(10) << 24.15 << setw(10)
    << 120 << setw(10) << 30 << endl;
    aux15 << setw(20) << "Pan" << setw(10) << 19.45 << setw(10)
    << 180 << setw(10) << 25 << endl;
    aux15 << setw(20) << "Huevos" << setw(10) << 39.60 << setw(10)
    << 90  << setw(10) << 60 << endl;
    aux15 << setw(20) << "Arroz" << setw(10) << 34.80 << setw(10)
    << 60  << setw(10) << 20 << endl;
    aux15 << setw(20) << "Pasta" << setw(10) << 29.95 << setw(10)
    << 250 << setw(10) << 140 << endl;
    aux15 << setw(20) << "Tomates" << setw(10) << 44.25 << setw(10)
    << 110 << setw(10) << 80 << endl;
    aux15 << setw(20) << "Pollo" << setw(10) << 119.80 << setw(10)
    << 75 << setw(10) << 15 << endl;
    aux15 << setw(20) << "Pescado" << setw(10) << 179.20 << setw(10)
    << 50  << setw(10) << 10 << endl;
    aux15 << setw(20) << "Carne de res" << setw(10) << 149.15 << setw(10)
    << 40 << setw(10) << 12 << endl;
    aux15 << setw(20) << "Cebollas" << setw(10) << 9.95  << setw(10)
    << 160 << setw(10) << 55 << endl;
    aux15 << setw(20) << "Patatas" << setw(10) << 24.10 << setw(10)
    << 210 << setw(10) << 90 << endl;
    aux15 << setw(20) << "Aceite de oliva" << setw(10) << 99.65 << setw(10)
    << 80  << setw(10) << 20 << endl;
    aux15 << setw(20) << "Azucar" << setw(10) << 14.55 << setw(10)
    << 220 << setw(10) << 100 << endl;
    aux15 << setw(20) << "Cafe" << setw(10) << 79.25 << setw(10)
    << 95  << setw(10) << 35 << endl;
    aux15 << setw(20) << "Te" << setw(10) << 58.85 << setw(10)
    << 120 << setw(10) << 40 << endl;
    aux15 << setw(20) << "Galletas" << setw(10) << 39.70 << setw(10)
    << 190 << setw(10) << 70 << endl;
    aux15 << setw(20) << "Jugo de naranja" << setw(10) << 49.45 << setw(10)
    << 130 << setw(10) << 30 << endl;
    aux15 << setw(20) << "Yogur" << setw(10) << 24.90 << setw(10)
    << 140 << setw(10) << 60 << endl;
    aux15 << setw(20) << "Frutos secos" << setw(10) << 199.55 << setw(10)
    << 80 << setw(10) << 25 << endl;
    aux15 << setw(20) << "Cereal" << setw(10) << 69.15 << setw(10)
    << 210 << setw(10) << 55 << endl;
    aux15 << setw(20) << "Chocolate" << setw(10) << 34.90 << setw(10)
    << 170 << setw(10) << 45 << endl;
    aux15 << setw(20) << "Oreo" << setw(10) << 12.23 << setw(10)
    << 96  << setw(10) << 78 << endl;
    aux15 << setw(20) << "Nutella" << setw(10) << 45.69 << setw(10)
    << 36  << setw(10) << 78 << endl;
    aux15 << setw(20) << "Aguacate" << setw(10) << 65.78 << setw(10)
    << 33  << setw(10) << 133 << endl;
    aux15 << setw(20) << "Sabritas" << setw(10) << 45.66 << setw(10)
    << 120  << setw(10) << 80 << endl;
    aux15 << endl;
    string aux16 = aux15.str();
    cout << "Caso 8: " << ((aux16 == inventario.mostrarDatos(productos,
    precios, ventas, stocks)) ? "success\n" : "fail\n");

    // Caso 9 Modificacion de un producto
    inventario.actualizar_datos(productos, ventas, "Leche", 135);
    stringstream aux17;
    aux17 << setw(20) << "Producto" << setw(10) << "Precio" << setw(10)
    << "Ventas" << setw(10) << "Stocks" << endl;
    aux17 << setw(20) << "Manzanas" << setw(10) << 49.99 << setw(10)
    << 150 << setw(10) << 50 << endl;
    aux17 << setw(20) << "Naranjas" << setw(10) << 59.75 << setw(10)
    << 200 << setw(10) << 75 << endl;
    aux17 << setw(20) << "Bananas" << setw(10) << 29.30 << setw(10)
    << 300 << setw(10) << 100 << endl;
    aux17 << setw(20) << "Leche" << setw(10) << 24.15 << setw(10)
    << 135 << setw(10) << 30 << endl;
    aux17 << setw(20) << "Pan" << setw(10) << 19.45 << setw(10)
    << 180 << setw(10) << 25 << endl;
    aux17 << setw(20) << "Huevos" << setw(10) << 39.60 << setw(10)
    << 90  << setw(10) << 60 << endl;
    aux17 << setw(20) << "Arroz" << setw(10) << 34.80 << setw(10)
    << 60  << setw(10) << 20 << endl;
    aux17 << setw(20) << "Pasta" << setw(10) << 29.95 << setw(10)
    << 250 << setw(10) << 140 << endl;
    aux17 << setw(20) << "Tomates" << setw(10) << 44.25 << setw(10)
    << 110 << setw(10) << 80 << endl;
    aux17 << setw(20) << "Pollo" << setw(10) << 119.80 << setw(10)
    << 75 << setw(10) << 15 << endl;
    aux17 << setw(20) << "Pescado" << setw(10) << 179.20 << setw(10)
    << 50  << setw(10) << 10 << endl;
    aux17 << setw(20) << "Carne de res" << setw(10) << 149.15 << setw(10)
    << 40 << setw(10) << 12 << endl;
    aux17 << setw(20) << "Cebollas" << setw(10) << 9.95  << setw(10)
    << 160 << setw(10) << 55 << endl;
    aux17 << setw(20) << "Patatas" << setw(10) << 24.10 << setw(10)
    << 210 << setw(10) << 90 << endl;
    aux17 << setw(20) << "Aceite de oliva" << setw(10) << 99.65 << setw(10)
    << 80  << setw(10) << 20 << endl;
    aux17 << setw(20) << "Azucar" << setw(10) << 14.55 << setw(10)
    << 220 << setw(10) << 100 << endl;
    aux17 << setw(20) << "Cafe" << setw(10) << 79.25 << setw(10)
    << 95  << setw(10) << 35 << endl;
    aux17 << setw(20) << "Te" << setw(10) << 58.85 << setw(10)
    << 120 << setw(10) << 40 << endl;
    aux17 << setw(20) << "Galletas" << setw(10) << 39.70 << setw(10)
    << 190 << setw(10) << 70 << endl;
    aux17 << setw(20) << "Jugo de naranja" << setw(10) << 49.45 << setw(10)
    << 130 << setw(10) << 30 << endl;
    aux17 << setw(20) << "Yogur" << setw(10) << 24.90 << setw(10)
    << 140 << setw(10) << 60 << endl;
    aux17 << setw(20) << "Frutos secos" << setw(10) << 199.55 << setw(10)
    << 80 << setw(10) << 25 << endl;
    aux17 << setw(20) << "Cereal" << setw(10) << 69.15 << setw(10)
    << 210 << setw(10) << 55 << endl;
    aux17 << setw(20) << "Chocolate" << setw(10) << 34.90 << setw(10)
    << 170 << setw(10) << 45 << endl;
    aux17 << setw(20) << "Oreo" << setw(10) << 12.23 << setw(10)
    << 96  << setw(10) << 78 << endl;
    aux17 << setw(20) << "Nutella" << setw(10) << 45.69 << setw(10)
    << 36  << setw(10) << 78 << endl;
    aux17 << setw(20) << "Aguacate" << setw(10) << 65.78 << setw(10)
    << 33  << setw(10) << 133 << endl;
    aux17 << setw(20) << "Sabritas" << setw(10) << 45.66 << setw(10)
    << 120  << setw(10) << 80 << endl;
    aux17 << endl;
    string aux18 = aux17.str();
    cout << "Caso 9: " << ((aux18 == inventario.mostrarDatos(productos,
    precios, ventas, stocks)) ? "success\n" : "fail\n");

    // Caso 10 Resumen de ganancia y ventas
    stringstream aux19;
    aux19 << "Cantidad de productos vendidos: " << 3730 << endl;
    aux19 << "Total: 173679.36MXN" << endl;
    string aux20 = aux19.str();
    cout << "Caso 10: " << ((aux20 == inventario.resumen(precios,
    ventas)) ? "success\n" : "fail\n");

    //Caso 11 Resumen de ganancia y ventas por dia
    stringstream aux21;
    aux21 << "               Fecha" << setw(20) << "Nro. Ventas"
    << setw(20) << "Ganancia MXN" << endl;
    aux21 << "           01-10-2024" << setw(15) << 478
    << setw(20) << 312.54 << endl;
    aux21 << "           02-10-2024" << setw(15) << 501
    << setw(20) << 98.79 << endl;
    aux21 << "           03-10-2024" << setw(15) << 902
    << setw(20) << 389.23 << endl;
    aux21 << "           04-10-2024" << setw(15) << 303
    << setw(20) << 55.67 << endl;
    aux21 << "           05-10-2024" << setw(15) << 207
    << setw(20) << 562.81 << endl;
    aux21 << "           06-10-2024" << setw(15) << 211
    << setw(20) << 548.95 << endl;
    aux21 << "           07-10-2024" << setw(15) << 789
    << setw(20) << 474.12 << endl;
    aux21 << "           08-10-2024" << setw(15) << 602
    << setw(20) << 1001.03 << endl;
    aux21 << "           09-10-2024" << setw(15) << 401
    << setw(20) << 629.84 << endl;
    aux21 << "           10-10-2024" << setw(15) << 533
    << setw(20) << 645.39 << endl;
    aux21 << "           11-10-2024" << setw(15) << 578
    << setw(20) << 661.22 << endl;
    aux21 << "           12-10-2024" << setw(15) << 991
    << setw(20) << 350.14 << endl;
    aux21 << "           13-10-2024" << setw(15) << 632
    << setw(20) << 691.47 << endl;
    aux21 << "           14-10-2024" << setw(15) << 213
    << setw(20) << 745.23 << endl;
    aux21 << "           15-10-2024" << setw(15) << 183
    << setw(20) << 525.56 << endl;
    aux21 << "           16-10-2024" << setw(15) << 252
    << setw(20) << 622.56 << endl;
    aux21 << "           17-10-2024" << setw(15) << 351
    << setw(20) << 900.75 << endl;
    aux21 << "           18-10-2024" << setw(15) << 155
    << setw(20) << 410.42 << endl;
    aux21 << "           19-10-2024" << setw(15) << 149
    << setw(20) << 849.26 << endl;
    aux21 << "           20-10-2024" << setw(15) << 457
    << setw(20) << 1263.76 << endl;
    aux21 << "           21-10-2024" << setw(15) << 489
    << setw(20) << 784.33 << endl;
    aux21 << "           22-10-2024" << setw(15) << 123
    << setw(20) << 231.47 << endl;
    aux21 << "           23-10-2024" << setw(15) << 433
    << setw(20) << 433.33 << endl;
    aux21 << "           24-10-2024" << setw(15) << 51
    << setw(20) << 120.41 << endl;
    aux21 << endl;
    string aux22 = aux21.str();
    cout << "Caso 11: " << ((aux22 == inventario.mostrarFecha())
    ? "success\n" : "fail\n");

    //Caso 12 Resumen de ganancia y ventas por dia
    stringstream aux23;
    aux23 << "               Fecha" << setw(20) << "Nro. Ventas"
    << setw(20) << "Ganancia MXN" << endl;
    aux23 << "           04-10-2024" << setw(15) << 303
    << setw(20) << 55.67 << endl;
    aux23 << "           02-10-2024" << setw(15) << 501
    << setw(20) << 98.79 << endl;
    aux23 << "           24-10-2024" << setw(15) << 51
    << setw(20) << 120.41 << endl;
    aux23 << "           22-10-2024" << setw(15) << 123
    << setw(20) << 231.47 << endl;
    aux23 << "           01-10-2024" << setw(15) << 478
    << setw(20) << 312.54 << endl;
    aux23 << "           12-10-2024" << setw(15) << 991
    << setw(20) << 350.14 << endl;
    aux23 << "           03-10-2024" << setw(15) << 902
    << setw(20) << 389.23 << endl;
    aux23 << "           18-10-2024" << setw(15) << 155
    << setw(20) << 410.42 << endl;
    aux23 << "           23-10-2024" << setw(15) << 433
    << setw(20) << 433.33 << endl;
    aux23 << "           07-10-2024" << setw(15) << 789
    << setw(20) << 474.12 << endl;
    aux23 << "           15-10-2024" << setw(15) << 183
    << setw(20) << 525.56 << endl;
    aux23 << "           06-10-2024" << setw(15) << 211
    << setw(20) << 548.95 << endl;
    aux23 << "           05-10-2024" << setw(15) << 207
    << setw(20) << 562.81 << endl;
    aux23 << "           16-10-2024" << setw(15) << 252
    << setw(20) << 622.56 << endl;
    aux23 << "           09-10-2024" << setw(15) << 401
    << setw(20) << 629.84 << endl;
    aux23 << "           10-10-2024" << setw(15) << 533
    << setw(20) << 645.39 << endl;
    aux23 << "           11-10-2024" << setw(15) << 578
    << setw(20) << 661.22 << endl;
    aux23 << "           13-10-2024" << setw(15) << 632
    << setw(20) << 691.47 << endl;
    aux23 << "           14-10-2024" << setw(15) << 213
    << setw(20) << 745.23 << endl;
    aux23 << "           21-10-2024" << setw(15) << 489
    << setw(20) << 784.33 << endl;
    aux23 << "           19-10-2024" << setw(15) << 149
    << setw(20) << 849.26 << endl;
    aux23 << "           17-10-2024" << setw(15) << 351
    << setw(20) << 900.75 << endl;
    aux23 << "           08-10-2024" << setw(15) << 602
    << setw(20) << 1001.03 << endl;
    aux23 << "           20-10-2024" << setw(15) << 457
    << setw(20) << 1263.76 << endl;
    aux23 << endl;
    string aux24 = aux23.str();
    cout << "Caso 12: " << ((aux24 == inventario.mostrarFechaVenta())
    ? "success\n" : "fail\n");

    // Caso 13 Ingresar una nueva fecha
    inventario.agregaFecha("25-10-2024", 356, 720.69);
    stringstream aux25;
    aux25 << "               Fecha" << setw(20) << "Nro. Ventas"
    << setw(20) << "Ganancia MXN" << endl;
    aux25 << "           01-10-2024" << setw(15) << 478
    << setw(20) << 312.54 << endl;
    aux25 << "           02-10-2024" << setw(15) << 501
    << setw(20) << 98.79 << endl;
    aux25 << "           03-10-2024" << setw(15) << 902
    << setw(20) << 389.23 << endl;
    aux25 << "           04-10-2024" << setw(15) << 303
    << setw(20) << 55.67 << endl;
    aux25 << "           05-10-2024" << setw(15) << 207
    << setw(20) << 562.81 << endl;
    aux25 << "           06-10-2024" << setw(15) << 211
    << setw(20) << 548.95 << endl;
    aux25 << "           07-10-2024" << setw(15) << 789
    << setw(20) << 474.12 << endl;
    aux25 << "           08-10-2024" << setw(15) << 602
    << setw(20) << 1001.03 << endl;
    aux25 << "           09-10-2024" << setw(15) << 401
    << setw(20) << 629.84 << endl;
    aux25 << "           10-10-2024" << setw(15) << 533
    << setw(20) << 645.39 << endl;
    aux25 << "           11-10-2024" << setw(15) << 578
    << setw(20) << 661.22 << endl;
    aux25 << "           12-10-2024" << setw(15) << 991
    << setw(20) << 350.14 << endl;
    aux25 << "           13-10-2024" << setw(15) << 632
    << setw(20) << 691.47 << endl;
    aux25 << "           14-10-2024" << setw(15) << 213
    << setw(20) << 745.23 << endl;
    aux25 << "           15-10-2024" << setw(15) << 183
    << setw(20) << 525.56 << endl;
    aux25 << "           16-10-2024" << setw(15) << 252
    << setw(20) << 622.56 << endl;
    aux25 << "           17-10-2024" << setw(15) << 351
    << setw(20) << 900.75 << endl;
    aux25 << "           18-10-2024" << setw(15) << 155
    << setw(20) << 410.42 << endl;
    aux25 << "           19-10-2024" << setw(15) << 149
    << setw(20) << 849.26 << endl;
    aux25 << "           20-10-2024" << setw(15) << 457
    << setw(20) << 1263.76 << endl;
    aux25 << "           21-10-2024" << setw(15) << 489
    << setw(20) << 784.33 << endl;
    aux25 << "           22-10-2024" << setw(15) << 123
    << setw(20) << 231.47 << endl;
    aux25 << "           23-10-2024" << setw(15) << 433
    << setw(20) << 433.33 << endl;
    aux25 << "           24-10-2024" << setw(15) << 51
    << setw(20) << 120.41 << endl;
    aux25 << "           25-10-2024" << setw(15) << 356
    << setw(20) << 720.69 << endl;
    aux25 << endl;
    string aux26 = aux25.str();
    cout << "Caso 13: " << ((aux26 == inventario.mostrarFecha())
    ? "success\n" : "fail\n");

    // Caso 14 Ordenar con la fecha ingresada
    stringstream aux27;
    aux27 << "               Fecha" << setw(20) << "Nro. Ventas"
    << setw(20) << "Ganancia MXN" << endl;
    aux27 << "           04-10-2024" << setw(15) << 303
    << setw(20) << 55.67 << endl;
    aux27 << "           02-10-2024" << setw(15) << 501
    << setw(20) << 98.79 << endl;
    aux27 << "           24-10-2024" << setw(15) << 51
    << setw(20) << 120.41 << endl;
    aux27 << "           22-10-2024" << setw(15) << 123
    << setw(20) << 231.47 << endl;
    aux27 << "           01-10-2024" << setw(15) << 478
    << setw(20) << 312.54 << endl;
    aux27 << "           12-10-2024" << setw(15) << 991
    << setw(20) << 350.14 << endl;
    aux27 << "           03-10-2024" << setw(15) << 902
    << setw(20) << 389.23 << endl;
    aux27 << "           18-10-2024" << setw(15) << 155
    << setw(20) << 410.42 << endl;
    aux27 << "           23-10-2024" << setw(15) << 433
    << setw(20) << 433.33 << endl;
    aux27 << "           07-10-2024" << setw(15) << 789
    << setw(20) << 474.12 << endl;
    aux27 << "           15-10-2024" << setw(15) << 183
    << setw(20) << 525.56 << endl;
    aux27 << "           06-10-2024" << setw(15) << 211
    << setw(20) << 548.95 << endl;
    aux27 << "           05-10-2024" << setw(15) << 207
    << setw(20) << 562.81 << endl;
    aux27 << "           16-10-2024" << setw(15) << 252
    << setw(20) << 622.56 << endl;
    aux27 << "           09-10-2024" << setw(15) << 401
    << setw(20) << 629.84 << endl;
    aux27 << "           10-10-2024" << setw(15) << 533
    << setw(20) << 645.39 << endl;
    aux27 << "           11-10-2024" << setw(15) << 578
    << setw(20) << 661.22 << endl;
    aux27 << "           13-10-2024" << setw(15) << 632
    << setw(20) << 691.47 << endl;
    aux27 << "           25-10-2024" << setw(15) << 356
    << setw(20) << 720.69 << endl;
    aux27 << "           14-10-2024" << setw(15) << 213
    << setw(20) << 745.23 << endl;
    aux27 << "           21-10-2024" << setw(15) << 489
    << setw(20) << 784.33 << endl;
    aux27 << "           19-10-2024" << setw(15) << 149
    << setw(20) << 849.26 << endl;
    aux27 << "           17-10-2024" << setw(15) << 351
    << setw(20) << 900.75 << endl;
    aux27 << "           08-10-2024" << setw(15) << 602
    << setw(20) << 1001.03 << endl;
    aux27 << "           20-10-2024" << setw(15) << 457
    << setw(20) << 1263.76 << endl;
    aux27 << endl;
    string aux28 = aux27.str();
    cout << "Caso 14: " << ((aux28 == inventario.mostrarFechaVenta())
    ? "success\n" : "fail\n");

    // Caso 15 Busqueda de una fecha
    stringstream aux29;
    aux29 << "Fecha encontrada" << endl;
    aux29 << setw(20) << "Fecha" << setw(20) << "Ventas"
    << setw(20) << "Ganancia" << endl;
    aux29 << setw(20) << "25-10-2024" << setw(20) << "356"
    << setw(20) << "720.69" << endl;
    aux29 << endl;
    string aux30 = aux29.str();
    cout << "Caso 15: " << ((aux30 == inventario.mostrarPorDia("25-10-2024"))
    ? "success\n" : "fail\n");

    // Caso 16 Busqueda de una fecha
    stringstream aux31;
    aux31 << "Fecha encontrada" << endl;
    aux31 << setw(20) << "Fecha" << setw(20) << "Ventas"
    << setw(20) << "Ganancia" << endl;
    aux31 << setw(20) << "06-10-2024" << setw(20) << "211"
    << setw(20) << "548.95" << endl;
    aux31 << endl;
    string aux32 = aux31.str();
    cout << "Caso 16: " << ((aux32 == inventario.mostrarPorDia("06-10-2024"))
    ? "success\n" : "fail\n");
    return 0;
}
