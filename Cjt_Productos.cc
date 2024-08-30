#include "Cjt_Productos.hh"

using namespace std;


Cjt_Productos::Cjt_Productos() {}
Cjt_Productos:: ~Cjt_Productos() {

}
bool Cjt_Productos::producto_existe(int id) const {
    map<int, Producto>::const_iterator it = productos.find(id);
    return it != productos.end();
}

Producto Cjt_Productos::get_producto(int id) const {
   map<int, Producto>::const_iterator it = productos.find(id);
        return it->second;
    }


void Cjt_Productos::escribir_producto(int id) const {
     if (producto_existe(id)) {
        cout << id << ' ' << get_producto(id).getPeso() << ' ' << get_producto(id).getVolumen() << endl;
    }
    else {
        cout << "error: no existe el producto" << endl;
    }
}

void Cjt_Productos::consultar_num() const {
        cout << productos.size() << endl;
    }
    
// pre mayor que 0
void Cjt_Productos::agregar_productos(int cantidad) {
        int idInicial;
        if (productos.empty()) {
            idInicial = 1;
        } else {
            idInicial = productos.rbegin()->first + 1;
        }

        for (int i = 0; i < cantidad; ++i) {
            int peso, volumen;
            cin >> peso;
            cin >> volumen;

            Producto nuevoprod;
            nuevoprod.setPeso(peso);
            nuevoprod.setVolumen(volumen);

            productos[idInicial + i] = nuevoprod;
        }  
}



