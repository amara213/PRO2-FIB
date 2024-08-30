#ifndef CUENCA_HH
#define CUENCA_HH

#include "Ciudad.hh"
#include "Cjt_Productos.hh"
#include "Barco.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#endif

using namespace std;

/**
 * @brief Una cuenca formada por un conjunto de ciudades estructuradas en un bintree y sus inventarios.
 */
class Cuenca {
private:
    map<string, Ciudad> inventarios; ///< Mapa que almacena los inventarios diferentes de las ciudades de la Cuenca.
    BinTree<string> ciudades; ///< Árbol que almacena la estructura que forman las ciudades de la cuenca.

    /**
     * @brief Función recursiva para leer las ciudades y construir el bintree.
     * 
     * Esta función lee las ciudades de forma recursiva y construye un bintree en preorden. 
     * También crea una clave que será el inventario en el mapa de inventarios para cada ciudad.
     *
     * @param a El bintree donde se guarda.
     * 
     * @pre El bintree está vacío.
     * @post A medida que se leen las ciudades en preorden se construye el bintree con las ciudades 
     *       y se crea una clave en el mapa de inventarios para cada una.
     */
    void leer_rio_recurs(BinTree<string>& a);

    /**
     * @brief Función recursiva para redistribuir productos entre las ciudades.
     * 
     * Primero comerciará la ciudad de la desembocadura con la ciudad río arriba a mano derecha y 
     * luego con la ciudad río arriba a mano izquierda, y así sucesivamente, hasta llegar a las ciudades de los nacimientos.
     *
     * @param ciudades El bintree que contiene las ciudades.
     * @param productos El conjunto de productos general.
     * 
     * @pre El bintree 'ciudades' contiene las ciudades.
     * @post Los productos se redistribuyen entre las ciudades actualizándose el inventario de cada una si han comerciado. 
     */
    void redistribuirRecursi(const BinTree<string>& ciudades, Cjt_Productos& productos);

    /**
     * @brief Función recursiva para encontrar la mejor ruta para el barco.
     * 
     * Esta función encuentra la mejor ruta para el barco considerando la ruta que le permita comprar y vender el mayor número posible de productos. 
     * En caso que haya más de una ruta que lo cumpla, se queda con la más corta, y en caso de que tengan la misma longitud, se queda con la que viene río arriba a mano derecha.
     *
     * @param a El bintree que contiene las ciudades.
     * @param idcomprar El ID del producto q quiere comprar el barco.
     * @param comprar La cantidad de productos q quiere comprar el barco.
     * @param idvender El ID del producto q quiere vender el barco.
     * @param vender La cantidad de productos q quiere vender el barco.
     * @param ruta_atual El vector que almacena la ruta actual.
     * @param acumulado El acumulado de productos.
     * @param longfinal La longitud final de la ruta.
     * @param mejorRuta El vector que almacena la mejor ruta encontrada.
     * @param bestcantidadprods La mejor cantidad de productos encontrados.
     * @param mejor_long La mejor longitud de ruta encontrada.
     * 
     * @pre El bintree contiene las ciudades a considerar.
     * @post Se determina la mejor ruta para el barco y se guarda en un vector (mejorRuta).
     */
    void best_ruta(const BinTree<string>& a, int comprar, int idcomprar, int vender, int idvender, vector<string>& ruta_actual, int acumulado, int longfinal, vector<string>& mejorRuta, int& bestcantidadprods, int& mejor_long);
    /**
     * @brief Realiza el comercio en una ciudad durante el viaje del barco.
     * 
     * Esta función modifica la cantidad de productos en la ciudad después del comercio durante el recorrido del barco, la ciudad solo le puede dar al barco la cantidad que le sobra, y él puede venderle hasta que esta tenga la cantidad que necesita.
     *
     * @param ciudad La ciudad donde se comercia.
     * @param productos El conjunto de productos general.
     * @param idcomprar El ID del producto q quiere comprar el barco.
     * @param comprar La cantidad de productos q quiere comprar el barco.
     * @param idvender El ID del producto q quiere vender el barco.
     * @param vender La cantidad de productos q quiere vender el barco.
     * 
     * @pre Cierto
     * @post La cantidad de productos en la ciudad se actualiza según si el barco le pudo comprar o vender a la ciudad.
     */
    void comerciar_barco(Ciudad& ciudad, Cjt_Productos& productos, int idcomprar, int& comprar, int idvender, int& vender);

public:
    /**
     * @brief Constructor de la clase Cuenca.
     * 
     * Construye una cuenca vacía.
     *
     * @pre Cierto.
     * @post Se crea una Cuenca vacía.
     */
    Cuenca();

    /**
     * @brief Destructor de la clase Cuenca.
     *
     * @pre Cierto.
     * @post Se  destruye el objeto.
     */
    ~Cuenca();
    /**
     * @brief Lee el río y construye el inventario de ciudades.
     * 
     * Esta función lee las ciudades de forma recursiva y construye un bintree en preorden. 
     * También crea una clave que será el inventario en el mapa de inventarios para cada ciudad.
     *
     * @pre Cierto.
     * @post Se construye la estructura de las ciudades en preorden y se crea una clave en el mapa inventarios para cada una.
     */
    void leer_rio();

    /**
     * @brief Lee los inventarios de diferentes ciudades.
     *        Esta función lee los inventarios de varias ciudades y los actualiza.
     *
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post Los inventarios de las ciudades se actualizan con los nuevos productos.
     */
    void leer_inventarios(Cjt_Productos& productos);

    /**
     * @brief Lee el inventario de una ciudad.
     * 
     * Esta función lee el inventario de una ciudad y actualiza la clave de esta en el mapa.
     *
     * @param ciudad El nombre de la ciudad.
     * @param productos El conjunto de productos general.
     * 
     * @pre La ciudad debe existir en el árbol, El número de unidades necesitadas siempre ha de ser mayor que 0
     * @post El inventario de la ciudad se actualiza con los nuevos productos y sus cantidades.
     *       Si la ciudad no existe, se imprime un error.
     */
    void leer_inventario(string ciudad, Cjt_Productos& productos);

    // Funciones consultoras
    /**
     * @brief Verifica si una ciudad existe.
     *
     * @param ciudad El nombre de la ciudad
     * 
     * @pre Cierto.
     * @post Devuelve true si la ciudad existe, false si no.
     * @return True si la ciudad existe, false si no.
     */
    bool ciudad_existe(string ciudad) const;

    /**
     * @brief Verifica si un producto existe en el inventario de una ciudad.
     *
     * @param ciudad El nombre de la ciudad.
     * @param id El ID del producto a verificar.
     * 
     * @pre Cierto.
     * @post True si el producto existe en la ciudad, false si no.
     * @return True si el producto existe en la ciudad, false si no.
     */
    bool producto_existe(string ciudad, int id) const;

    /**
     * @brief Consulta un producto en la ciudad.
     * 
     * Esta función imprime la cantidad que tiene y necesita la ciudad de un producto.
     *
     * @param ciudad El nombre de la ciudad.
     * @param id_producto El ID del producto a consultar.
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post Se imprime la cantidad que tiene y necesita del producto en la ciudad.
     *       Si el producto no existe, se imprime un error. Si la ciudad no existe, se imprime un error.
     *       Si la ciudad no tiene el producto, se imprime un error.
     * @return True si el producto se consultó correctamente, false si no.
     */
    bool consultar_prod(string ciudad, int id_producto, const Cjt_Productos& productos);
    
     /**
     * @brief Esta función agrega un producto a la ciudad y actualiza el inventario.
     *
     * @param ciudad El nombre de la ciudad.
     * @param id_producto El ID del producto
     * @param cantidad_tiene La cantidad de producto que tiene la ciudad.
     * @param cantidad_necesita La cantidad de producto que necesita la ciudad.
     * @param productos El conjunto de productos general.
     * 
     * @pre El producto y la ciudad deben existir, lEl número de unidades necesitadas siempre ha de ser mayor que 0.
     * @post El producto se agrega a la ciudad y se actualiza el inventario, se imrpimen los totales actualizados. 
     *       Si el producto no existe, se imprime un error. 
     *       Si la ciudad no existe, se imprime un error. 
     *       Si la ciudad ya tiene el producto, se imprime un error.
     * @return True si el producto se agregó correctamente, false si no.
     */
    bool poner_prod(string ciudad, int id_producto, int cantidad_tiene, int cantidad_necesita, Cjt_Productos& productos);

    /**
     * @brief Modifica un producto en la ciudad.
     * 
     * Esta función modifica las cantidades de un producto en la ciudad.
     *
     * @param ciudad El nombre de la ciudad.
     * @param id_producto El ID del producto
     * @param cantidad_tiene La cantidad de producto que tiene la ciudad.
     * @param cantidad_necesita La cantidad de producto que necesita la ciudad.
     * @param productos El conjunto de productos general.
     * 
     * @pre  La cantidad que necesita siempre es mayor que 0.
     * @post La cantidad del producto en la ciudad se actualiza con las nuevas cantidades, y se imrpimen los totales actualizados. 
     *       Si el producto no existe, se imprime un error. 
     *       Si la ciudad no existe, se imprime un error. 
     *       Si la ciudad no tiene el producto, se imprime un error.
     * @return True si el producto se modificó correctamente, false si no.
     */
    bool modificar_prod(string ciudad, int id_producto, int cantidad_tiene, int cantidad_necesita, Cjt_Productos& productos);

    /**
     * @brief Escribe la información de una ciudad.
     * 
     * Esta función imprime los totales y las cantidades de cada producto junto a su ID, de una ciudad si existe.
     *
     * @param ciudad El nombre de la ciudad.
     * 
     * @pre Cierto.
     * @post Se imprime la información de la ciudad, si existe. Si la ciudad no existe, se imprime un error.
     */
    void escribir_ciudad(string ciudad);

    // Funciones modificadoras
    /**
     * @brief Redistribuye los productos entre las ciudades.
     * 
     * La ciudad de la desembocadura comercia con su ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente.
     * 
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post Los productos se redistribuyen entre las ciudades y se actualizan los inventarios.
     */
    void redistribuir(Cjt_Productos& productos);

    /**
     * @brief Quita un producto de la ciudad.
     * 
     * Esta función elimina un producto de la ciudad y actualiza el inventario.
     *
     * @param ciudad El nombre de la ciudad.
     * @param id_producto El ID del producto
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post El producto se elimina de la ciudad y se actualiza el inventario, se imprimen los totales actualizados. 
     *       Si el producto no existe, se imprime un error. 
     *       Si la ciudad no existe, se imprime un error. 
     *       Si la ciudad no tiene el producto, se imprime un error.
     * @return True si el producto se quitó correctamente, false si no.
     */
    bool quitar_prod(string ciudad, int id_producto, Cjt_Productos& productos);

    /**
     * @brief Esta función realiza el comercio entre dos ciudades y actualiza sus inventarios.
     * 
     * Una ciudad le dará a la otra todos los productos que le sobren hasta alcanzar si es posible los que la otra necesite, y viceversa.
     *
     * @param ciudad1 El nombre de la primera ciudad.
     * @param ciudad2 El nombre de la segunda ciudad.
     * @param productos El conjunto de productos general.
     * 
     * @pre Las ciudades deben existir y ser diferentes.
     * @post Los inventarios de las ciudades se actualizan según el comercio realizado. 
     *       Si una de las ciudades no existe, se imprime un error. 
     *       Si las ciudades son iguales, se imprime un error.
     * @return True si el comercio se realizó correctamente, false si no.
     */
    bool comerciar(string ciudad1, string ciudad2, Cjt_Productos& productos);

    /**
     * @brief Hace el viaje del barco.
     * 
     * Esta función hace el viaje del barco una vez escogida la ruta, procediendo a hacer el viaje donde el barco compra y vende
     * en las ciudades del recorrido, modificándose los productos en las ciudades en los que se realicen compras o ventas.
     *
     * @param barco El barco que realiza el viaje.
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post Se actualizan los inventarios según si cada ciudad de la ruta tenía el producto o no.
     */
    void hacer_viaje(Barco& barco, Cjt_Productos& productos);
};

#endif
