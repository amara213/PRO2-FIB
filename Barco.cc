#include "Barco.hh"

Barco::Barco(int idComprar, int cantidadComprar, int idVender, int cantidadVender) {
    vender = make_pair(idVender, cantidadVender);
    comprar = make_pair(idComprar, cantidadComprar);
}

Barco::~Barco(){}
// pre no negativas
bool Barco::modificar_barco(int idComprar, int cantidadComprar, int idVender, int cantidadVender, Cjt_Productos& productos) { 
    if (!productos.producto_existe(idComprar)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }

    if (!productos.producto_existe(idVender)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }
    if (idComprar == idVender) {
        cout << "error: no se puede comprar y vender el mismo producto" << endl;
        return false;
    }

    comprar = make_pair(idComprar, cantidadComprar);
    vender = make_pair(idVender, cantidadVender);
    return true;
    }


int Barco::get_id_vender() const {
    return vender.first;
}

int Barco::get_cantidad_vender() const {
    return vender.second;
}

int Barco::get_id_comprar() const {
    return comprar.first;
}

int Barco::get_cantidad_comprar() const {
    return comprar.second;
}

void Barco::escribir_barco() const {
    cout << comprar.first << ' ' << comprar.second << ' ' << vender.first << ' ' << vender.second << endl;  
    for (int i = 0; i < visitadas.size(); i++)  {
        cout << visitadas[i] << endl;
    }
  }

void Barco::reiniciar_barco() {
    visitadas.clear();
}

void Barco::ciudad_visitada(string ciudad) {
        visitadas.push_back(ciudad);
    }
