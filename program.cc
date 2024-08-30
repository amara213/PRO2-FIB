/**
* @mainpage Comercio fluvial
En este proyecto, se simula comercio fluvial entre las ciudades que forman la cuenca  y un barco que también comercia.
*/
#include "Barco.hh"
#include "Cuenca.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#endif
using namespace std;

int main() {
    
    int numproductos;
    cin >> numproductos;

    Cjt_Productos productos;
    productos.agregar_productos(numproductos);

    Cuenca cuenca;
    cuenca.leer_rio();

    int idComprar, cantidadComprar, idVender, cantidadVender;
    cin >> idComprar >> cantidadComprar >> idVender >> cantidadVender;
    Barco barco(idComprar, cantidadComprar, idVender, cantidadVender);

    string comando;

    while (cin >> comando and comando != "fin") {
        if (comando == "//") {
            string c;
            getline(cin, c);
            }     
        else if (comando == "leer_rio" or comando == "lr") {
            barco.reiniciar_barco();
            cout << "#" << comando << endl;
            cuenca.leer_rio();
        }
        else if (comando == "leer_inventario" or comando == "li") {
            string ciudad;
            cin >> ciudad;
            cout << "#" << comando << " " << ciudad << endl;
            cuenca.leer_inventario(ciudad, productos);
        } else if (comando == "leer_inventarios" or comando == "ls") {
            cout << "#" << comando << endl;
            cuenca.leer_inventarios(productos);
        } else if (comando == "modificar_barco" or comando == "mb") {
            cin >> idComprar >> cantidadComprar >> idVender >> cantidadVender;
            cout << "#" << comando << endl;
            barco.modificar_barco(idComprar, cantidadComprar, idVender, cantidadVender, productos);
        } else if (comando == "escribir_barco" or comando == "eb") {
            cout << "#" << comando << endl;
            barco.escribir_barco();
        } else if (comando == "consultar_num" or comando == "cn") {
            cout << "#" << comando << endl;
            productos.consultar_num();
        } else if (comando == "agregar_productos" or comando == "ap") {
            int numproductos;
            cin >> numproductos;
            cout << "#" << comando << ' ' << numproductos << endl;
            productos.agregar_productos(numproductos);
        } else if (comando == "escribir_producto" or comando == "ep") {
            int idProducto;
            cin >> idProducto;
            cout << "#" << comando << ' ' << idProducto << endl;
            productos.escribir_producto(idProducto);
        } else if (comando == "escribir_ciudad" or comando == "ec") {
            string ciudad;
            cin >> ciudad;
            cout << "#" << comando << ' ' << ciudad << endl;
            cuenca.escribir_ciudad(ciudad);
        } else if (comando == "poner_prod" or comando == "pp") {
            string ciudad;
            cin >> ciudad;
            int idProducto, cantidadTiene, cantidadNecesita;
            cin >> idProducto >> cantidadTiene >> cantidadNecesita;
            cout << "#" << comando << ' ' << ciudad << ' ' << idProducto << endl;
            cuenca.poner_prod(ciudad, idProducto, cantidadTiene, cantidadNecesita, productos);
        } else if (comando == "modificar_prod" or comando == "mp") {
            string ciudad;
            cin >> ciudad;
            int idProducto, cantidadTiene, cantidadNecesita;
            cin >> idProducto >> cantidadTiene >> cantidadNecesita;
            cout << "#" << comando << ' ' << ciudad << ' ' << idProducto << endl;
            cuenca.modificar_prod(ciudad, idProducto, cantidadTiene, cantidadNecesita, productos);
        } else if (comando == "quitar_prod" or comando == "qp") {
            string ciudad;
            cin >> ciudad;
            int idProducto;
            cin >> idProducto;
            cout << "#" << comando << ' ' << ciudad << ' ' << idProducto << endl;
            cuenca.quitar_prod(ciudad, idProducto, productos);
        } else if (comando == "consultar_prod" or comando == "cp") {
            string ciudad;
            cin >> ciudad;
            int idProducto;
            cin >> idProducto;
            cout << "#" << comando << ' ' << ciudad << ' ' << idProducto << endl;
            cuenca.consultar_prod(ciudad, idProducto, productos);
        } else if (comando == "comerciar" or comando == "co") {
            string ciudad1, ciudad2;
            cin >> ciudad1 >> ciudad2;
            cout << "#" << comando << ' ' << ciudad1 << ' ' << ciudad2 << endl;
            cuenca.comerciar(ciudad1, ciudad2, productos);
        } else if (comando == "redistribuir" or comando == "re") {
            cout << "#" << comando << endl;
            cuenca.redistribuir(productos);
        } else if (comando == "hacer_viaje" or comando == "hv") {
            cout << "#" << comando << endl;
            //cuenca.hacer_viaje(cuenca.getDesembocadura(), barco, productos);
            cuenca.hacer_viaje(barco, productos);
        }
    }

}
