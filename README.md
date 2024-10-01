# INVENTARIO
El presente proyecto trata sobre un inventario de productos, los cuales, pueden encontrarse en cualquier supermercado. Tal como se sabe, en dichos comercios, cada producto tiene un precio y las unidades disponibles del mismo. Adicionalmente, cada supermercado debe saber el número de ventas, con el fin de poder establecer que producto es el más vendido y tener mayor stock. Asimismo, de poder saber si los precios que generan son los adecuados para poder tener mayores ventas. Esto con el fin de poder generar estrategias de mercado. De ese modo, el programa principal se encarga de generar una estructura de clases con el fin de poder comparar el precio, el número de ventas y las unidades disponibles de cada producto y ordenarlos de manera descendente de acuerdo a lo que se requiera. Por ejemplo, mediante el programa se puede tener una lista ordenada de productos acorde al precio, del más caro al más barato.   

Adicional a lo mencionado anteriormente, el programa permitirá agregar productos con sus respectivas características. Así también como eliminar algún producto como tal. Del mismo modo, el programa será capaz actualizar algunos datos del producto así también como realizar una búsqueda para encontrar un producto en específico.  

## SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa
#### Ordenamiento de productos: 
En el archivo “sorts.h” se tienen dos métodos de ordenamiento, el primero es el ordenamiento Merge, mientras que el segundo es un método el cual permite ordenar la lista de nombres de productos en base al precio, venta o stock. Básicamente, este último método toma los valores de la lista ordenada (precio, venta, stock), y los busca en la lista original para obtener el índice, con dicho valor, se dirige a la lista original que contiene los nombres de los productos y crea una nueva con los nombres ordenados en base al precio, venta o stock. 

Función ordenaMerge: Posee una complejidad de O(n logn), es uno de los algoritmos de ordenamiento más rápidos, ya que en la mayoría de casos presenta dicha complejidad. 

Función ordenaProductos: Posee una complejidad O(n^2), ya que primero deberá recorrer toda la lista ordenada y posterior a ello, por cada elemento de dicha lista, deberá buscar el elemento en toda la lista original original para poder devolver el índice. 

### Hace un análisis de complejidad correcto y completo para todas las estructuras de datos y cada uno de sus usos en el programa
#### Listas doblemente enlazadas
El archivo "dlist.h" contiene todos los métodos de listas doblemente enlazadas para poder implementar dicha estrcutura de datos en el programa. Desde como añadir un elemento en la propia lista, obtener el tamaño, el valor en una determinada posición dentro la lista y hasta eliminar un valor.  

Función add: Posee una complejidad de O(1), ya que siempre se va añadir un nuevo elemento al final de la lista.

Función search: Posee una complejidad de O(n/2), ya que como se tiene dos apuntadores (head y tail), cada uno de ellos buscará el dato desde el inicio hasta la mitad de la lista en el caso de head y desde el último elemento hasta propia mitad de la lista en el caso del tail.

Función update: Posee una complejidad de O(n/2), ya que al introducir en la función el índice del elemento a que se quiere cambiar su valor, si el índice se encuentra en la primera mitad se usará el apuntador head, caso contrario se usa el apuntador tail.

Función remove: Posee una complejidad de O(n/2), ya que al introducir en la función el índice del elemento a que se quiere eliminar, si el índice se encuentra en la primera mitad se usará el apuntador head, caso contrario se usa el apuntador tail.

Función get: Posee una complejidad O(n/2), ya que al introducir en la función el índice del elemento al cual se quiere obtener su valor, si el índice se encuentra en la primera mitad se usará el apuntador head, caso contrario se usa el apuntador tail. 

#### Listas de productos
En el archivo “inventario.h” se tiene la lista productos, la cual almacena todos los productos registrados. De ese modo para poder ordenar los productos acordes a los precios, ventas y unidades disponibles es importante crear una nueva lista para cada variable. 

Función agrega_producto: Posee una complejidad de O(1) ya que todo producto nuevo se añade al final de la lista. 

Función obtener_nombres: Posee una complejidad de O(n) esto ya que se debe recorrer toda la lista de productos para poder obtener los nombres de todos los productos registrados.  

Función obtener_precios: Posee una complejidad de O(n) esto ya que se debe recorrer todo la lista de productos para poder obtener los precios de todos los productos registrados.  

Función obtener_ventas: Posee una complejidad de O(n) esto ya que se debe recorrer todo la lista de productos para poder obtener la cantidad de ventas a lo largo del mes de todos los productos registrados.  

Función obtener_nombres: Posee una complejidad de O(n) esto ya que se debe recorrer todo la lista de productos para poder obtener la cantidad de unidades disponibles para la venta de todos los productos registrados.  

Función busqueda: Posee una complejidad O(n/2) porque se realiza la búsqueda a partir de los apuntadores head y tail. 

Función eliminar_product: Posee una complejidad O(n/2+b) esto ya que primero se debe buscar el producto a eliminar, posterior a ello se debe realizar una cantidad de b pasos para poder eliminar dicho producto. 

Función actualizar_datos: Posee una complejidad O(n/2+b) esto ya que primero se debe buscar el producto el cual se quiere cambiar su dato, posterior a ello se debe realizar una cantidad de pasos para poder modificar el valor de dicho producto. 

## SICT0302B: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema
Para este programa se implementó el algoritmo de ordenamiento de tipo “merge sort”. La elección de este algoritmo de ordenamiento fue por dos razones principales. La primera, es que es un algoritmo muy rápido con un nivel de complejidad de O(n logn) es la mayoría de casos. A diferencia de otros métodos como: “bubble sort”, “insertion sort” o “selection sort”, donde su complejidad es mucho mayor en los peores casos. La otra razón fue porque en la mayoría de casos, la lista de productos siempre se encontrará desordenada, esto debido al incremento de productos que pueden ser añadidos a la tienda. Incluso, los precios, ventas y unidades disponibles de cada producto pueden ir variando dependiendo de la oferta o demando del mismo. La implementación del algoritmo de ordenamiento “merge sort”, se encuentra en el archivo shorts.h en las líneas 64 a la 140.   

### Selecciona una estructura lineal adecuada para el problema
Para este programa se decidió implementar el manejo de listas doblemente enlazadas. Esto con el fin de poder añadir nuevos productos al final sin preocuparnos por el espacio como en el caso de un array, siendo esta estructura mucho más versátil. Asimismo, se implementó esta estructura con el fin de poder acceder a los productos y poder realizar una búsqueda mucho más eficiente acorde a su ubicación dentro de la lista. Todos los métodos de las listas doblemente enlazadas se encuentran en el el archivo "dlist.h". Asímismo, para añadir un producto al final de la lista, actualizar un dato y realizar la búsqueda de uno en específico, se encuentran en el archivo "inventario.h" en las líneas 208 a 253.

## SICT0303B: Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa
El programa permite al usuario realizar distintas consultas de información e incluso modificar algún dato en específico del producto. Por ejemplo, en caso de necesitar ver los productos ordenados acorde a precio/venta/stock se encuentran las opciones 3, 4 y 5. Si se desea buscar algún producto en específico se encuentra la opción 6, en caso de eliminar algún dato esta la opción 7 y si se quiere modificar algún dato de un producto en específico, está la opción 8. Finalmente, la opción 9 muestra un resumen de las ventas totales realizadas y la ganancia del supermercado.  

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa
Todos los productos se encuentran registrados en un archivo denominado "Inventario.csv". Mediante dicho archivo el programa es capaz de obtener la información correspondiente y poder realizar las acciones que desea el usuario. El método donde se hace la lectura de datos se llama cargarDatos() y se encuentra en el archivo "inventario.h" en las líneas 59 a 77.   

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa 
Una vez ejecutado el programa, el archivo denominado "Inventario.csv" se reescribe nuevamente con todas las actualizaciones que se realizaron dentro del programa. Por ejemplo, en caso que se haya eliminado o añadido algún producto. Incluso, se haya modificado el precio de un producto en particular. Todos esos cambios se verán en el nuevo archivo "Inventario.csv". El método donde se hace la escritura de datos se llama escribir() y se encuentra en el archivo "Inventario.h" en las líneas 326 a 336. 
