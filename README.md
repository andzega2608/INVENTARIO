# INVENTARIO
El presente proyecto trata sobre un inventario de productos, los cuales, pueden encontrarse en cualquier supermercado. Tal como se sabe, en dichos comercios, cada producto tiene un precio y las unidades disponibles del mismo. Adicionalmente, cada supermercado debe saber el numero de ventas, con el fin de poder establecer que producto es el más vendido y tener mayor stock. Asimismo, de poder saber si los precios que generan son los adecuados para poder tener mayores ventas. Esto con el fin de poder generar estrategias de mercado. De ese modo, el programa principal se encarga de generar una estructura de clases con el fin de poder comparar el precio, el número de ventas y las unidades disponibles de cada producto y ordenarlos de manera descendente de acuerdo a lo que se requiera. Por ejemplo, mediante el programa se puede tener una lista ordenada de productos acorde al precio, del más caro al más barato.   

Adicional a lo mencionado anteriormente, el programa permitirá agregar productos con sus respectivas características. Del mismo modo, el programa será que capaz de mostrar todo el catálogo de productos que posee la tienda. 

## SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
#### Lista de productos registrados
En el archivo “inventario.h” se tiene el vector productos, el cual almacena todos los productos registrados. De ese modo para poder ordenar los productos acordes a los precios, ventas y unidades disponibles es importante crear un vector para cada variable. 

Función de obtener_nombres: Posee una complejidad de O(n) esto ya que se debe recorrer todo el arreglo de productos para poder obtener los nombres de todos los productos registrados.  

Función de obtener_precios: Posee una complejidad de O(n) esto ya que se debe recorrer todo el arreglo de productos para poder obtener los precios de todos los productos registrados.  

Función de obtener_ventas: Posee una complejidad de O(n) esto ya que se debe recorrer todo el arreglo de productos para poder obtener la cantidad de ventas a lo largo del mes de todos los productos registrados.  

Función de obtener_nombres: Posee una complejidad de O(n) esto ya que se debe recorrer todo el arreglo de productos para poder obtener la cantidad de unidades disponibles para la venta de todos los productos registrados.  

#### Ordenamiento de productos: 
En el archivo “sorts.h” se tienen dos métodos de ordenamiento, el primero es el ordenamiento Merge, mientras que el segundo es un método el cual permite ordenar el vector nombres en base al precio, venta o stock. Básicamente, este último método toma los valores del vector ordenado (precio, venta, stock), y los busca en el vector original para obtener el índice, con dicho valor, se dirige al vector original que contiene los nombres de los productos y crea un vector con los nombres ordenados en base al precio, venta o stock. 

Función ordenaMerge: Posee una complejidad de O(n logn), es uno de los algoritmos de ordenamiento más rápidos, ya que en la mayoría de casos presenta dicha complejidad. 

Función ordenaProductos: Posee una complejidad O(n^2), ya que primero deberá recorrer todo el arreglo del vector ordenado y posterior a ello, por cada elemento del vector ordenado, deberá buscar el elemento en todo el arreglo del vector original para poder devolver el índice. 



## SICT0302B: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema
Para este programa se implementó el algoritmo de ordenamiento de tipo “merge sort”. La elección de este algoritmo de ordenamiento fue por dos razones principales. La primera, es que es un algoritmo muy rápido con un nivel de complejidad de O(n logn) es la mayoría de casos. A diferencia de otros métodos como: “bubble sort”, “insertion sort” o “selection sort”, donde su complejidad es mucho mayor en los peores casos. La otra razón fue porque en la mayoría de casos, la lista de productos siempre se encontrará desordenada, esto debido al incremento de productos que pueden ser añadidos a la tienda. Incluso, los precios, ventas y unidades disponibles de cada producto pueden ir variando dependiendo de la oferta o demando del mismo. La implementación del algoritmo de ordenamiento “merge sort”, se encuentra en el archivo shorts.h en las líneas 64 a la 140.   
