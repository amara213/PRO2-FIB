#ifndef BARCO_HH
#define BARCO_HH

#include "Cjt_Productos.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#endif
using namespace std;

/**
 * @brief Un barco que quiere comprar y vender productos.
 */
class Barco {
private:
    pair<int, int> vender; ///< Par con el ID y la cantidad que el producto quiere vender.
    pair<int, int> comprar; ///< Par con el ID y la cantidad que el producto quiere comprar.
    vector<string> visitadas; ///< Vector que guarda la última ciudad visitada de cada viaje

public:
    /**
     * @brief Constructor de la clase Barco.
     * 
     * Inicializa un barco con un prod que el barco quiere comprar y otro que el barco quiere vender, con la cantidad q quiere de cada uno.
     *
     * @param idComprar El ID del producto q quiere ccomprar.
     * @param cantidadComprar La cantidad del producto q quiere comprar.
     * @param idVender El ID del producto q quiere vender.
     * @param cantidadVender La cantidad del producto q quiere vender.
     *
     * @pre Las cantidades deben ser no negativas.
     * @post Se crea un barco con las especificaciones dadas.
     */
    Barco(int idComprar, int cantidadComprar, int idVender, int cantidadVender);

        /**
     * @brief Destructor de la clase Barco.
     *
     * @pre Cierto.
     * @post Se  destruye el objeto.
     */
    ~Barco();
    // Consultoras
    /**
     * @brief Obtiene el ID del producto que el barco quiere vender.
     * 
     * @pre Cierto.
     * @post Devuelve el ID del producto que el barco quiere vender.
     */
    int get_id_vender() const;

    /**
     * @brief Obtiene la cantidad del producto que el barco quiere vender.
     * 
     * @pre Cierto.
     * @post Devuelve la cantidad del producto que el barco quiere vender.
     */
    int get_cantidad_vender() const;

    /**
     * @brief Obtiene el ID del producto que el barco quiere comprar.
     * 
     * @pre Cierto.
     * @post Devuelve el ID del producto que el barco quiere comprar.
     */
    int get_id_comprar() const;

    /**
     * @brief Obtiene la cantidad del producto que el barco quiere comprar.
     * 
     * @pre Cierto.
     * @post Devuelve la cantidad del producto que el barco quiere comprar.
     */
    int get_cantidad_comprar() const;

    /**
     * @brief Escribe la información del barco.
     * 
     * @pre Cierto.
     * @post Imprime el ID y la cantidad de los productos que el barco quiere comprar y vender, y la última ciudad visitada en cada viaje que hizo en esa cuenca, l, en orden cronológico
     */
    void escribir_barco() const;

    // Modificadoras
    /**
     * @brief Modifica los productos que el barco compra y vende.
     * 
     * @param idComprar El ID del producto q quiere ccomprar.
     * @param cantidadComprar La cantidad del producto q quiere comprar.
     * @param idVender El ID del producto q quiere vender.
     * @param cantidadVender La cantidad del producto q quiere vender.
     * @param productos El conjunto de productos general.
     *
     * @pre Se garantiza que ambas cantidades serán no negativas y al menos una de ellas será estrictamente positiva.
     * @post Si los productos existen y no son el mismo, se actualizan los productos que el barco quiere comprar y vender.
     *       Si los productos no existen o son el mismo, se imprime un error.
     */
    bool modificar_barco(int idComprar, int cantidadComprar, int idVender, int cantidadVender, Cjt_Productos& productos);

    /**
     * @brief Reinicia las ciudades visitadas por el barco.
     * 
     * @pre Cierto.
     * @post La lista de ciudades visitadas por el barco se vacía.
     */
    void reiniciar_barco();

    /**
     * @brief Añade una ciudad a la lista de ciudades visitadas por el barco.
     * 
     * @param ciudad El nombre de la ciudad q se quiere añadir.
     *
     * @pre Cierto.
     * @post La ciudad se añade a la lista de ciudades visitadas por el barco.
     */
    void ciudad_visitada(string ciudad);
};

#endif
