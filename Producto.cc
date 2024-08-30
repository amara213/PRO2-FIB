#include "Producto.hh"
using namespace std;

Producto::~Producto(){}

Producto::Producto() {
    peso = 0;
    volumen = 0;
}
int Producto::getPeso() const {
  return peso;
}

void Producto::setPeso(int peso) {
    this->peso = peso;
}

int Producto::getVolumen() const {
  return volumen;
}

void Producto::setVolumen(int volumen) {
    this->volumen = volumen;
}
