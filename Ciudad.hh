#ifndef CIUDAD_HH
#define CIUDAD_HH

#include "Cjt_Productos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif
using namespace std;

/**
 * @class Ciudad
 * @brief Una ciudad con productos y sus cantidades.
 */
class Ciudad {
private:
    pair<int, int> totales; ///< Par que almacena el peso y el volumen totales de los productos de la ciudad.
    map<int, pair<int, int>> tiene_neces; ///< Mapa que almacena los productos con sus cantidades y las cantidades que necesita.

public:

    /**
     * @brief Constructor de la clase Ciudad.
     * 
     * Inicializa el inventario de la ciudad con peso y volumen total 0.
     * @pre Cierto.
     * @post La ciudad se crea con peso y volumen total igual a 0.
     */
    Ciudad();

        /**
     * @brief Destructor de la clase Ciudad.
     *
     * @pre Cierto.
     * @post Se  destruye el objeto.
     */
    ~Ciudad();

    // Consultoras
    /**
     * @brief Devuelve el peso total de los productos de la ciudad.
     * 
     * @pre Cierto.
     * @post Devuelve el peso total de los productos de la ciudad.
     */
    int get_peso_total() const;

    /**
     * @brief Devuelve el volumen total de los productos de la ciudad.
     * 
     * @pre Cierto.
     * @post Devuelve el volumen total de los productos de la ciudad.
     */
    int get_volumen_total() const;

    /**
     * @brief Verifica si el producto con el ID ID (id) existe en la ciudad.
     * 
     * @param id El ID del producto.
     * 
     * @pre Cierto.
     * @post Devuelve true si el producto con el ID (id) dado existe en la ciudad, false si no.
     */
    bool producto_existe(int id) const;

    /**
     * @brief Imprime la ID y la cantidad que tiene y necesita de todos los productos que tiene la ciudad así como el volumen y el peso total de la ciudad.
     * 
     * @pre Cierto.
     * @post Imprime la ID y la cantidad que tiene y necesita de todos los productos que tiene la ciudad, así como los totales de esta.
     */
    void escribirciudad() const;

    /**
     * @brief Devuelve el número de productos diferentes en la ciudad.
     * 
     * @pre Cierto.
     * @post Devuelve el número de productos diferentes que hay en la ciudad.
     */
    int getSize() const;

    /**
     * @brief Devuelve la información de un producto (cantidad que tiene y necesita de este).
     * 
     * @param id El ID del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos).
     * @post Devuelve la información del producto con (id) (cantidad que tiene y necesita de este).
     * @return Un par con la cantidad que tiene y la cantidad que necesita del producto.
     */
    pair<int, int> get_info_prod(int id);

    /**
     * @brief Devuelve la cantidad que tiene del producto con ID (id).
     * 
     * @param id El ID del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos).
     * @post Devuelve la cantidad que tiene del producto con ID (id).
     */
    int cantidad_tiene(int id) const;

    /**
     * @brief Devuelve la cantidad que necesita del producto con ID (id).
     * 
     * @param id El ID del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos).
     * @post Devuelve la cantidad que necesita del producto con ID (id).
     */
    int cantidad_necesita(int id) const;

    // Modificadoras
    /**
     * @brief Modifica el peso y volumen totales de la ciudad según los productos y sus cantidades.
     * 
     * @param id El ID del producto que se modificó
     * @param cantidad_tiene La cantidad de producto que la ciudad tiene ahora.
     * @param peso El peso del producto.
     * @param volumen El volumen del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos) del conj de productos.
     * @post Modifica el peso y volumen totales de la ciudad según el producto y su nueva cantidad disponible en la ciudad.
     */
    void modificartotales(int id, int cantidad_tiene, int peso, int volumen);

    /**
     * @brief Agrega un producto al inventario de la ciudad, actualizando los totales.
     * 
     * @param id El ID del producto.
     * @param cantidad_tiene La cantidad de producto que la ciudad tiene.
     * @param cantidad_necesita La cantidad de producto que la ciudad necesita.
     * @param peso El peso del producto.
     * @param volumen El volumen del producto.
     * 
     * @pre El producto con ID (id) no debe existir en el mapa (productos).
     * @post Agrega el producto con sus cantidades al mapa (productos), actualizando los totales.
     * @return true si el producto fue agregado, false si no.
     */
    bool agregarProducto(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen);

    /**
     * @brief Agrega un producto al inventario de la ciudad.
     * 
     * @param id El ID del producto.
     * @param cantidad_tiene La cantidad de producto que la ciudad tiene.
     * @param cantidad_necesita La cantidad de producto que la ciudad necesita.
     * @param peso El peso del producto.
     * @param volumen El volumen del producto.
     * 
     * @pre Cierto.
     * @post Agrega el producto con sus cantidades al mapa (productos), actualizando los totales.
     */
    void agregarProductoinv(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen);

    /**
     * @brief Modifica un producto existente en la ciudad.
     * 
     * @param id El ID del producto.
     * @param cantidad_tiene La cantidad de producto que la ciudad tiene.
     * @param cantidad_necesita La cantidad de producto que la ciudad necesita.
     * @param peso El peso del producto.
     * @param volumen El volumen del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos).
     * @post Modifica las cantidades del producto en el mapa (productos), actualizando los totales.
     */
    bool modificarProducto(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen);

    /**
     * @brief Elimina un producto de la ciudad.
     * 
     * @param id El ID del producto.
     * @param peso El peso del producto.
     * @param volumen El volumen del producto.
     * 
     * @pre El producto con ID (id) debe existir en el mapa (productos).
     * @post Elimina el producto con ID (id) del mapa (productos), actualizando los totales.
     */
    bool eliminarProducto(int id, int peso, int volumen);

    /**
     * @brief Limpia el inventario de la ciudad.
     * 
     * @pre Cierto.
     * @post Elimina todos los productos del mapa (productos) y reinicia los totales.
     */
    void limpiarinv();

    /**
     * @brief Función que ayuda a comerciar entre esta ciudad y otra ciudad.
     * 
     * @param ciudad2 La ciudad con la que se va a comerciar.
     * @param productos El conjunto de productos general.
     * 
     * @pre Cierto.
     * @post Actualiza el inventario de las dos ciudades donde una ciudad le dará a la otra todos los productos que le sobren hasta alcanzar si es posible los que la otra necesite, y viceversa.
     */
    void comerciarcon(Ciudad& ciudad2, Cjt_Productos& productos);
};

#endif
