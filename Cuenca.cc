#include "Cuenca.hh"
using namespace std;

Cuenca::Cuenca() {}

Cuenca::~Cuenca(){}

void Cuenca::leer_rio() {
    inventarios.clear();
    ciudades = BinTree<string>();
    leer_rio_recurs(ciudades); 
}

void Cuenca::leer_rio_recurs(BinTree<string>& a) {
    string ciudad;
    cin >> ciudad;

    if (ciudad != "#") {
        inventarios[ciudad] = Ciudad();
        BinTree<string> bl, br;    
        leer_rio_recurs(bl);
        leer_rio_recurs(br);
        a = BinTree<string>(ciudad, bl, br);
    }
}

void Cuenca::redistribuir(Cjt_Productos& productos) {
    redistribuirRecursi(ciudades, productos);
}

void Cuenca::redistribuirRecursi(const BinTree<string>& ciudades, Cjt_Productos& productos) {
    if (!ciudades.empty()) {
    string ciudadnombre = ciudades.value();
        if (!ciudades.left().empty()) {
                comerciar(ciudadnombre, ciudades.left().value(), productos);
        }
        if (!ciudades.right().empty()) {
                comerciar(ciudadnombre, ciudades.right().value(), productos);
        }
    
    redistribuirRecursi(ciudades.left(), productos);
    redistribuirRecursi(ciudades.right(), productos);
    }
}

bool Cuenca::ciudad_existe(string ciudad) const {
    return inventarios.find(ciudad) != inventarios.end();
}

bool Cuenca::producto_existe(string ciudad, int id) const {
    if (ciudad_existe(ciudad) and inventarios.at(ciudad).producto_existe(id)) {
        return true;
    }
    return false;
}

bool Cuenca::poner_prod(string ciudad, int idProducto, int cantidad_tiene, int cantidad_necesita, Cjt_Productos& productos) {
    if (!productos.producto_existe(idProducto)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
        return false;
    }
    if (inventarios[ciudad].agregarProducto(idProducto, cantidad_tiene, cantidad_necesita, productos.get_producto(idProducto).getPeso(), productos.get_producto(idProducto).getVolumen())) {
        cout << inventarios[ciudad].get_peso_total() << " " << inventarios[ciudad].get_volumen_total() << endl;
        return true;
    }
    cout << "error: la ciudad ya tiene el producto" << endl;
    return false;
}

bool Cuenca::modificar_prod(string ciudad, int idProducto, int cantidad_tiene, int cantidad_necesita, Cjt_Productos& productos) {
    if (!productos.producto_existe(idProducto)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
        return false;
    }

    if (inventarios[ciudad].modificarProducto(idProducto, cantidad_tiene, cantidad_necesita, productos.get_producto(idProducto).getPeso(), productos.get_producto(idProducto).getVolumen())) {
        cout << inventarios[ciudad].get_peso_total() << " " << inventarios[ciudad].get_volumen_total() << endl;
        return true;
    }
    cout << "error: la ciudad no tiene el producto" << endl;
    return false;
}

bool Cuenca::consultar_prod(string ciudad, int idProducto, const Cjt_Productos& productos) {
    if (!productos.producto_existe(idProducto)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
        return false;
    }

    if (inventarios[ciudad].producto_existe(idProducto)) {
        cout << inventarios[ciudad].get_info_prod(idProducto).first << ' ' << inventarios[ciudad].get_info_prod(idProducto).second << endl;
        return true;
    }
    cout << "error: la ciudad no tiene el producto" << endl;
    return false;
}

void Cuenca::escribir_ciudad(string ciudad) {
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
    } else { 
    if (inventarios[ciudad].getSize() == 0) {
        cout << "0 0" << endl; 
    } 
    else {
        inventarios[ciudad].escribirciudad();   
        cout << inventarios[ciudad].get_peso_total() << " " << inventarios[ciudad].get_volumen_total() << endl;
    }
}
}
bool Cuenca::quitar_prod(string ciudad, int idProducto, Cjt_Productos& productos) {
    if (!productos.producto_existe(idProducto)) {
        cout << "error: no existe el producto" << endl;
        return false;
    }
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
        return false;
    }
    if (inventarios[ciudad].eliminarProducto(idProducto, productos.get_producto(idProducto).getPeso(), productos.get_producto(idProducto).getVolumen())) {
        cout << inventarios[ciudad].get_peso_total() << ' ' << inventarios[ciudad].get_volumen_total() << endl;
        return true;
    }
    cout << "error: la ciudad no tiene el producto" << endl;
    return false;
}

void Cuenca::leer_inventario(string ciudad, Cjt_Productos& productos) {
    if (!ciudad_existe(ciudad)) {
        cout << "error: no existe la ciudad" << endl;
    } 
    else inventarios[ciudad].limpiarinv();
    
    int elementos;
    cin >> elementos;
    for (int i = 0; i < elementos; ++i) {
        int idproducto, cantidad_tiene, cantidad_necesita;
        cin >> idproducto >> cantidad_tiene >> cantidad_necesita;
        if (ciudad_existe(ciudad)) {
        inventarios[ciudad].agregarProductoinv(idproducto, cantidad_tiene, cantidad_necesita, productos.get_producto(idproducto).getPeso(), productos.get_producto(idproducto).getVolumen());
 }
    }
}

void Cuenca::leer_inventarios(Cjt_Productos& productos) {
    string ciudad;
    while (cin >> ciudad and ciudad != "#") {
        leer_inventario(ciudad, productos);
    }
}

bool Cuenca::comerciar(string ciudad1, string ciudad2, Cjt_Productos& productos) {
    if (!ciudad_existe(ciudad1) or !ciudad_existe(ciudad2)) {
        cout << "error: no existe la ciudad" << endl;
        return false;
    }
    if (ciudad1 == ciudad2) {
        cout << "error: ciudad repetida" << endl;
        return false;
    }
     inventarios[ciudad1].comerciarcon(inventarios[ciudad2], productos);
    return true;
}


void Cuenca::best_ruta(const BinTree<string>& a, int comprar, int idcomprar, int vender, int idvender, vector<string>& ruta_actual, int acumulado, int longfinal, vector<string>& mejorRuta, int& bestcantidadprods, int& mejor_long) {
    if (!a.empty()) {
        int totalCompradas = 0;
        int totalVendidas = 0;

        if (inventarios[a.value()].producto_existe(idcomprar)) {
            int sobrante = inventarios[a.value()].cantidad_tiene(idcomprar) - inventarios[a.value()].cantidad_necesita(idcomprar);
            if (sobrante > 0) {
                int cantidad_comprar = min(comprar, sobrante);
                comprar -= cantidad_comprar;
                totalCompradas += cantidad_comprar;
            }
        }

        if (inventarios[a.value()].producto_existe(idvender)) {
            int sobrante = inventarios[a.value()].cantidad_necesita(idvender) - inventarios[a.value()].cantidad_tiene(idvender);
            if (sobrante > 0) {
                int cantidadVender = min(vender, sobrante);
                vender -= cantidadVender;
                totalVendidas += cantidadVender;
            }
        }

        int cantidad = totalCompradas + totalVendidas;
        ruta_actual.push_back(a.value());

        if (acumulado + cantidad > bestcantidadprods) {
            mejorRuta = ruta_actual;
            bestcantidadprods = acumulado + cantidad;
            mejor_long = longfinal;
        } else if (acumulado + cantidad == bestcantidadprods) {
            if (longfinal < mejor_long) {
                mejorRuta = ruta_actual;
                mejor_long = longfinal;
                bestcantidadprods = acumulado + cantidad;       
            }
        }

        best_ruta(a.left(), comprar, idcomprar, vender, idvender, ruta_actual, acumulado + cantidad, longfinal + 1, mejorRuta, bestcantidadprods, mejor_long);
        best_ruta(a.right(), comprar, idcomprar, vender, idvender, ruta_actual, acumulado + cantidad, longfinal + 1, mejorRuta, bestcantidadprods, mejor_long);

        ruta_actual.pop_back();
    }
}

void Cuenca::hacer_viaje(Barco& barco, Cjt_Productos& productos) {
    int idcomprar = barco.get_id_comprar();
    int idvender = barco.get_id_vender();
    int comprar = barco.get_cantidad_comprar();
    int vender = barco.get_cantidad_vender();
    vector<string> mejorRuta;
    int bestcantidadprods = 0;
    int mejor_long = -1;
    
    vector<string> ruta_actual;

    best_ruta(ciudades, comprar, idcomprar, vender, idvender, ruta_actual, 0, 0, mejorRuta, bestcantidadprods, mejor_long);

    if (!mejorRuta.empty()) {
        barco.ciudad_visitada(mejorRuta.back());
    }

    for (int i = 0; i < mejorRuta.size(); ++i) {
        comerciar_barco(inventarios[mejorRuta[i]], productos, idcomprar, comprar, idvender, vender);
    }

    cout << bestcantidadprods << endl;
}

void Cuenca::comerciar_barco(Ciudad& ciudad, Cjt_Productos& productos, int idcomprar, int& comprar, int idvender, int& vender) {
    if (ciudad.producto_existe(idcomprar)) {
        int sobrante = ciudad.cantidad_tiene(idcomprar) - ciudad.cantidad_necesita(idcomprar);
        if (sobrante > 0) {
            int cantidad_comprar;
            if (comprar < sobrante) cantidad_comprar = comprar;
            else cantidad_comprar =  sobrante;

            comprar -= cantidad_comprar;
            ciudad.modificarProducto(idcomprar, ciudad.cantidad_tiene(idcomprar) - cantidad_comprar, ciudad.cantidad_necesita(idcomprar), productos.get_producto(idcomprar).getPeso(), productos.get_producto(idcomprar).getVolumen());
        }
    }

    if (ciudad.producto_existe(idvender)) {
        int cantidad_vender;
        if (vender < ciudad.cantidad_necesita(idvender) - ciudad.cantidad_tiene(idvender)) cantidad_vender = vender;
        else cantidad_vender =  ciudad.cantidad_necesita(idvender) - ciudad.cantidad_tiene(idvender);
        if (cantidad_vender > 0) {
           vender -= cantidad_vender;
            ciudad.modificarProducto(idvender, ciudad.cantidad_tiene(idvender) + cantidad_vender, ciudad.cantidad_necesita(idvender), productos.get_producto(idvender).getPeso(), productos.get_producto(idvender).getVolumen());
        }
    }
}
