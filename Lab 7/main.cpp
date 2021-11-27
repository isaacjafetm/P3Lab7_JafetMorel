#include <iostream>
#include <string>
#include "Tienda.h"
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int opcion=0;
	Tienda* tiendita = new Tienda();
	while(opcion!=5){
		cout<<"¿Que desea hacer?"<<endl<<"1. Agregar Categorias"<<endl<<"2. Mantenimiento Articulos"<<endl<<"3. Estadisticas Generales"<<endl<<"4. Busquedas por categorias"<<endl<<"5. Salir"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				cout<<"Ingrese la categoria a agregar: ";
				string categoria;
				tiendita->agregarCategoria(new Categoria(categoria));
				break;                                  
			}
			case 2:{
				int opcion2=0;
				cout<<"¿Que desea hacer?"<<endl<<"1. Agregar Articulo"<<"2. Modificar Articulo"<<"3. Eliminar Articulo"<<"4. Listar Articulos"<<endl;
				cin>>opcion2;
				switch(opcion2){
					case 1:{
						string nombre="";
						cout<<"Ingrese nombre del articulo: ";
						cin>>nombre;
						//vector de tallas
						vector<char> tallas;
						char resp=' ';
						cout<<"¿Desea agregar talla S? [s/n] ";
						cin>>resp;
						if(resp=='s'||resp=='S'){
							tallas.push_back('S');
						}
						cout<<"¿Desea agregar talla M? [s/n] ";
						cin>>resp;
						if(resp=='s'||resp=='S'){
							tallas.push_back('M');
						}
						cout<<"¿Desea agregar talla L? [s/n] ";
						cin>>resp;
						if(resp=='s'||resp=='S'){
							tallas.push_back('L');
						}
						int precio=0;
						cout<<"Ingrese precio del articulo: ";
						cin>>precio;
						int cantidad=0;
						cout<<"Ingrese cantidad del articulo: ";
						cin>>cantidad;
						int descuento=0;
						cout<<"Ingrese porcentaje de descuento del articulo: ";
						cin>>descuento;
						int pos=0;
						tiendita->mostrarCats();
						cout<<"Ingrese categoria a la cual desea agregar: ";
						cin>>pos;
						tiendita->agregarArticulo(new Articulo(tallas,precio,cantidad,descuento),pos);
						break;
					}
					case 2:{
						tiendita->mostrarArts();
						int pos=0;
						cout<<"Ingrese posicion a modificar: ";
						cin>>pos;
						int mod=0;
						cout<<"¿Que desea modificar?"<<endl<<"1. Nombre"<<endl<<"2. Precio"<<endl<<"3. Cantidad"<<endl<<"4. Descuento"<<"5. Categoria"<<endl;
						cin>>mod;
						tiendita->modificarArticulo(pos,mod);
						break;
					}
					case 3:{
						tiendita->mostrarArts();
						int pos=0;
						cout<<"Ingrese posicion a eliminar: ";
						cin>>pos;
						tiendita->eliminarArticulo(pos);
						break;
					}
					case 4:{
						tiendita->mostrarArts();
						break;
					}
				
				}
			}
			case 3:{
				cout<<"Listado por categoria: "<<endl;
				tiendita->listaPorCateg();
				cout<"Total de unidades por categoria: "<<endl;
				tiendita->unidadPorCateg();
				cout<<"Precio total por categoria: "<<endl;
				tiendita->precioPorCateg();
				cout<<"Total de productos unicos: ";
				tiendita->productosUnicos();
				cout<<"Precio total de articulos sin descuento: ";
				tiendita->totalSinDescuento();
				cout<<"Total de unidades en la tienda: ";
				tiendita->totalUnidades();
				break;
			}
			case 4:{
				cout<<"¿Ordenar por categoria?[s/n]"<<endl;
				char resp;
				int cat=100;
				char talla='X';
				cin>>resp;
				if(resp=='s'||resp=='S'){
					tiendita->mostrarCats();
					cout<<"Cual categoria?"<<endl;
					cin>>cat;
				}
				cout<<"¿Ordenar por talla?[s/n]"<<endl;
				cin>>resp;
				if(resp=='s'||resp=='S'){
					cout<<"Cual talla?[S/M/L]"<<endl;
					cin>>talla;
				}
				tiendita->ordenar(cat,talla);
				break;
			}
		}
	}
	tiendita->~Tienda();
	return 0;
}