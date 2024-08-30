#ifndef PRODUCTO_HH
#define PRODUCTO_HH

/**
 * @class Producto
 * @brief Un producto, con peso y volumen.
 */
class Producto {
private:
    int peso;    ///< Peso del producto
    int volumen; ///< Volumen del producto

public:
    // CONSTRUCTORAS

    /**
     * @brief Constructor de la clase Producto.
     * 
     * Construye un producto con peso y volumen igual a 0.
     * 
     * @pre Cierto.
     * @post El producto se construye con peso y volumen igual a 0.
     */
    Producto();
        /**
     * @brief Destructor de la clase Producto.
     *
     * @pre Cierto.
     * @post Se  destruye el objeto.
     */
    ~Producto();
    //CONSULTORAS
    /**
     * @brief Devuelve el peso del producto.
     * 
     * @pre Cierto.
     * @post Devuelve el peso del producto.
     * @return El peso del producto.
     */
    int getPeso() const;

    /**
     * @brief Devuelve el volumen del producto.
     * 
     * @pre Cierto.
     * @post Devuelve el volumen del producto.
     * @return El volumen del producto.
     */
    int getVolumen() const;

    // MODIFICADORAS
    /**
     * @brief Establece el peso del producto.
     * 
     * @pre Cierto.
     * @post Asigna el valor de (peso) al atributo peso del producto.
     * @param peso El nuevo peso del producto.
     */
    void setPeso(int peso);

    /**
     * @brief Establece el volumen del producto.
     * 
     * @pre Cierto.
     * @post Asigna el valor de (volumen) al atributo volumen del producto.
     * @param volumen El nuevo volumen del producto.
     */
    void setVolumen(int volumen);
};

#endif 
