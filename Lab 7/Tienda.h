#ifndef TIENDA_H
#define TIENDA_H
#include "Categoria.h"
#include "Articulo.h"
#include <iostream>
class Tienda
{
	public:
		Tienda();
		~Tienda();
		void agregarArticulo(Articulo*, int);
		void agregarCategoria(Categoria*);
		void eliminarArticulo(int);
		void modificarArticulo(int, int);
		void mostrarCats();
		void mostrarArts();
		void listaPorCateg();
		void unidadPorCateg();
		void precioPorCateg();
		void productosUnicos();
		void totalSinDescuento();
		void totalUnidades();
		void ordenar(int,char);
	private:
		vector <Categoria*> listaCats;
		vector <Articulo*> listaArts;
};

#endif