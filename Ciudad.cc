#include "Ciudad.hh"



Ciudad::Ciudad() {
totales = make_pair(0, 0);
}
Ciudad::~Ciudad(){}

int Ciudad::get_peso_total() const {
return totales.first;
}
int Ciudad::get_volumen_total() const {
return totales.second;
}

void Ciudad::modificartotales(int id, int cantidad_tiene, int peso, int volumen) {
        totales.first -= tiene_neces[id].first*peso;
        totales.second -= tiene_neces[id].first*volumen;  
        totales.first += cantidad_tiene*peso; 
        totales.second += cantidad_tiene*volumen;
}
bool Ciudad::producto_existe(int id) const {
        map<int, pair<int, int>>::const_iterator  it = tiene_neces.find(id);
        return it != tiene_neces.end();
    }

void Ciudad::escribirciudad() const {
    for (map<int, pair<int, int>>::const_iterator it = tiene_neces.begin(); it != tiene_neces.end(); ++it) {
            cout << it->first << " " << it->second.first << " " << it->second.second << endl;
        }
}

int Ciudad::getSize() const {
    return tiene_neces.size();
}

bool Ciudad::agregarProducto(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen) {
    if (producto_existe(id)) {
        return false;
    } else {
        tiene_neces[id] = make_pair(cantidad_tiene, cantidad_necesita);
        totales.first += cantidad_tiene*peso; 
        totales.second += cantidad_tiene*volumen;
        return true;
    }
}
void Ciudad::agregarProductoinv(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen) {
        tiene_neces[id] = make_pair(cantidad_tiene, cantidad_necesita);
        totales.first += cantidad_tiene*peso; 
        totales.second += cantidad_tiene*volumen;
}

bool Ciudad::modificarProducto(int id, int cantidad_tiene, int cantidad_necesita, int peso, int volumen) {
    if (producto_existe(id)) {
        totales.first -= tiene_neces[id].first*peso;
        totales.second -= tiene_neces[id].first*volumen;  
        totales.first += cantidad_tiene*peso; 
        totales.second += cantidad_tiene*volumen;
        tiene_neces[id] = make_pair(cantidad_tiene, cantidad_necesita);
        return true;
    } else {
        return false;
    }
}
bool Ciudad::eliminarProducto(int id, int peso, int volumen) {
    if (producto_existe(id)) {
        totales.first -= tiene_neces[id].first*peso;
        totales.second -= tiene_neces[id].first*volumen;
        tiene_neces.erase(id);
        return true;
    } else {
        return false;
    }
 
}
pair<int, int> Ciudad::get_info_prod(int id)  {
    return tiene_neces[id];  
}

int Ciudad::cantidad_tiene(int id) const {
    map<int, pair<int, int>>::const_iterator it = tiene_neces.find(id);
    return it->second.first;
   
}

int Ciudad::cantidad_necesita(int id) const {
    map<int, pair<int, int>>::const_iterator it = tiene_neces.find(id);
    return it->second.second;
}

void Ciudad::limpiarinv() {
    tiene_neces.clear();
    totales = make_pair(0, 0);
}

void Ciudad::comerciarcon(Ciudad& ciudad2, Cjt_Productos& productos) {
    map<int, pair<int, int>>::iterator it = tiene_neces.begin();
    map<int, pair<int, int>>::iterator it2 = ciudad2.tiene_neces.begin();
    
    while (it != tiene_neces.end() and it2 != ciudad2.tiene_neces.end()) {
        int idproducto1 = it->first;
        int idproducto2 = it2->first;
    
        if (idproducto1 < idproducto2) {
            ++it;
        } else if (idproducto1 > idproducto2) {
            ++it2;
        } else { 
            int cant_tiene_ciudad1 = it->second.first;
            int cant_tiene_ciudad2 = it2->second.first;
            
            int sobranteciudad1 = cant_tiene_ciudad1 - it->second.second;
            int sobranteciudad2 = cant_tiene_ciudad2 - it2->second.second;
            int intercambio = 0;
            
            if (sobranteciudad1 > 0 and cant_tiene_ciudad2 < it2->second.second) {
                if (sobranteciudad1 > it2->second.second - cant_tiene_ciudad2) intercambio = it2->second.second - cant_tiene_ciudad2;
                    else intercambio = sobranteciudad1;
                if (intercambio > 0) {
                    modificartotales(idproducto1, cant_tiene_ciudad1 - intercambio, productos.get_producto(idproducto1).getPeso(), productos.get_producto(idproducto1).getVolumen());
                    ciudad2.modificartotales(idproducto1, cant_tiene_ciudad2 + intercambio, productos.get_producto(idproducto1).getPeso(), productos.get_producto(idproducto1).getVolumen());
                    it->second.first -= intercambio;
                    it2->second.first += intercambio;
                }
            }
            
            if (sobranteciudad2 > 0 and cant_tiene_ciudad1 < it->second.second) {
                 if (sobranteciudad2 > it->second.second - cant_tiene_ciudad1) intercambio = it->second.second - cant_tiene_ciudad1;
                    else intercambio = sobranteciudad2;
                if (intercambio > 0) {
                    ciudad2.modificartotales(idproducto1, cant_tiene_ciudad2 - intercambio, productos.get_producto(idproducto1).getPeso(), productos.get_producto(idproducto1).getVolumen());
                    modificartotales(idproducto1, cant_tiene_ciudad1 + intercambio, productos.get_producto(idproducto1).getPeso(), productos.get_producto(idproducto1).getVolumen());
                    it->second.first += intercambio;
                    it2->second.first -= intercambio;
                }
            }
            ++it;   
            ++it2;
        }
    }
}