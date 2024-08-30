#ifndef CJT_PRODUCTOS_HH
#define CJT_PRODUCTOS_HH

#include "Producto.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/**
 * @brief Conjunto de productos.
 */
class Cjt_Productos {
private:
    /**
     * @brief Mapa que guarda todos los productos diferentes que existen, con el ID del producto como clave.
     */
    map<int, Producto> productos;

public:
    /**
     * @brief Constructor de la clase Cjt_Productos.
     * 
     * Construye un Cjt_Productos vacío.
     *
     * @pre Cierto.
     * @post Se crea un conjunto de prods vacío.
     */
    Cjt_Productos();

        /**
     * @brief Destructor de la clase Cjt_Productos
     *
     * @pre Cierto.
     * @post Se  destruye el objeto.
     */
    ~Cjt_Productos();
    /**
     * @brief Verifica si el producto con el ID (id) existe.
     * 
     * @param id El ID del producto 
     * 
     * @pre Cierto.
     * @post Devuelve true si el producto con el ID (id) existe, false si no.
     * @return True si el producto existe, false en caso contrario.
     */
    bool producto_existe(int id) const;

    /**
     * @brief Devuelve el producto con el ID (id).
     * 
     * Esta función devuelve el producto con el ID (id).
     *
     * @param id El ID del producto 
     * 
     * @pre El producto con el ID (id) debe existir en el Cjt_Productos.
     * @post Devuelve el producto con el ID (id).
     * @return El product con el ID (id).
     */
    Producto get_producto(int id) const;

    /**
     * @brief Imprime la información del producto con el ID (id) (cantidad tiene y necesita).
     * 
     * @param id El ID del producto
     * 
     * @pre Cierto.
     * @post Si el producto con el ID dado existe, imprime su ID, peso y volumen. 
     *       Si el producto no existe, imprime un mensaje de error.
     */
    void escribir_producto(int id) const;

    /**
     * @brief Imprime el número total de productos diferentes que hay en el Cjt_Productos.
     * 
     * @pre Cierto.
     * @post Imprime la cantidad de productos diferentes que hay en el Cjt_Productos.
     */
    void consultar_num() const;

    /**
     * @brief Agrega una cantidad (cantidad) de nuevos productos al Cjt_Productos.
     * 
     * @param cantidad La cantidad de nuevos productos que se quieren agregar.
     * 
     * @pre La cantidad debe ser mayor que 0.
     * @post Se agregan la cantidad (cantidad) de nuevos productos al Cjt_Productos.
     */
    void agregar_productos(int cantidad);

};

#endif
