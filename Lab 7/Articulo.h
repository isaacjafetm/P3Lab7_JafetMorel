#ifndef ARTICULO_H
#define ARTICULO_H
#include <string>
#include "Categoria.h"
#include <vector>
using namespace std;

class Articulo
{
	public:
		Articulo( vector<char>, int, int, int);
		~Articulo();
		string getNombre();
		void setNombre(string);
		Categoria* getCategoria();
		void setCategoria(Categoria*);
		vector<char> getTalla();
		void setTalla(string);
		int getPrecio();
		void setPrecio(int);
		int getCantidad();
		void setCantidad(int);
		int getDescuento();
		void setDescuento(int);
		int getTotal();
		void setTotal(int,int);
		string toString();
		string tallaToString();
	private:
		string nombre;
		Categoria* categoria;
		vector <char> talla;
		int precio;
		int cantidad;
		int descuento;
		int total;
};

#endif