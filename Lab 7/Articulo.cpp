#include "Articulo.h"
using namespace std;

Articulo::Articulo(vector<char> size, int price, int quantity, int discount)
{
	this->talla=size;
	this->precio=price;
	this->cantidad=quantity;
	this->descuento=discount;
	setTotal(price, discount);
}

string Articulo::toString(){
	string salida="Nombre: "+nombre+", talla: "+tallaToString()+", precio: "+to_string(precio)+", cantidad: "+to_string(cantidad)+", descuento: "+to_string(descuento)+", categoria: "+categoria->toString();
	return salida;
}

string Articulo::tallaToString(){
	string salida="";
	for(int i =0; i<talla.size(); i++){
		char s=talla[i];
		salida=s+" ";
	}
	return salida;
}

int Articulo::getTotal(){
	return total;
}

void Articulo::setTotal(int price, int discount){
	this->total= price - (price*(discount/100));
}

void Articulo::setCategoria(Categoria* categ){
	this->categoria=categ;
}

Categoria* Articulo::getCategoria(){
	return categoria;
}

string Articulo::getNombre(){
	return nombre;
}

void Articulo::setNombre(string name){
	nombre=name;
}

int Articulo::getPrecio(){
	return precio;
}

void Articulo::setPrecio(int price){
	price=price;
}

int Articulo::getCantidad(){
	return cantidad;
}

void Articulo::setCantidad(int quantity){
	cantidad=quantity;
}

int Articulo::getDescuento(){
	return descuento;
}

void Articulo::setDescuento(int discount){
	descuento=discount;
}

vector<char> Articulo::getTalla(){
	return this->talla;
}

Articulo::~Articulo()
{
}