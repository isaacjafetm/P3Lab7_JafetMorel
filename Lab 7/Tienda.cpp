#include "Tienda.h"
using namespace std;

Tienda::Tienda()
{
	
}

void Tienda::agregarArticulo(Articulo* articulo, int pos){
	articulo->setCategoria(this->listaCats[pos]);
	this->listaArts.push_back(articulo);
}

void Tienda::agregarCategoria(Categoria* categoria){
	this->listaCats.push_back(categoria);
}

void Tienda::mostrarArts(){
	for(int i=0; i<this->listaArts.size();i++){
		cout<<i<<"- "<<listaArts[i]<<endl;
	}
}

void Tienda::mostrarCats(){
	for(int i=0; i<this->listaCats.size();i++){
		cout<<i<<"- "<<listaCats[i]<<endl;
	}
}

void Tienda::eliminarArticulo(int pos){
	this->listaArts.erase(listaArts.begin()+pos);	
}

void Tienda::modificarArticulo(int pos, int mod){
	switch(mod){
		case 1:{
			string nombre="";
			cout<<"Ingrese nuevo nombre: ";
			cin>>nombre;
			listaArts[pos]->setNombre(nombre);
			break;
		}
		case 2:{
			int precio=0;
			cout<<"Ingrese nuevo precio: ";
			cin>>precio;
			listaArts[pos]->setPrecio(precio);
			break;
		}
		case 3:{
			int cantidad=0;
			cout<<"Ingrese nueva cantidad: ";
			cin>>cantidad;
			listaArts[pos]->setCantidad(cantidad);
			break;
		}
		case 4:{
			int descuento=0;
			cout<<"Ingrese nuevo descuento: ";
			cin>>descuento;
			listaArts[pos]->setDescuento(descuento);
			break;
		}
		case 5:{
			Categoria* categoria;
			int cat=0;
			mostrarCats();
			cout<<"Ingrese posicion de nueva categoria: ";
			cin>>cat;
			listaArts[pos]->setCategoria(this->listaCats[cat]);
			break;
		}
	}
}
void Tienda::listaPorCateg(){
	for(int i=0;i<listaCats.size();i++){
		cout<<listaCats[i]->toString();
		for(int j=0;j<listaArts.size();j++){
			if(listaCats[i]==listaArts[j]->getCategoria()){
				cout<<listaArts[j]->toString();
			}
		}
		cout<<endl;
	}
}

void Tienda::unidadPorCateg(){
	for(int i=0;i<listaCats.size();i++){
		cout<<listaCats[i]->toString();
		int cantidad=0;
		for(int j=0;j<listaArts.size();j++){
			if(listaCats[i]==listaArts[j]->getCategoria()){
				cantidad+=listaArts[j]->getCantidad();
			}
		}
		string total = ""+cantidad;
		cout<<total<<endl;
	}	
}

void Tienda::precioPorCateg(){
	for(int i=0;i<listaCats.size();i++){
		cout<<listaCats[i]->toString();
		int precio=0;
		for(int j=0;j<listaArts.size();j++){
			if(listaCats[i]==listaArts[j]->getCategoria()){
				precio+=listaArts[j]->getPrecio();
			}
		}
		string total = ""+precio;
		cout<<total<<endl;
	}
}

void Tienda::productosUnicos(){
	cout<<listaArts.size()<<endl;
}

void Tienda::totalSinDescuento(){
	int total=0;
	for(int i=0; i<this->listaArts.size();i++){
		if(listaArts[i]->getDescuento()==0){
			total+=listaArts[i]->getTotal();
		}
	}
	cout<<total<<endl;
}

void Tienda::totalUnidades(){
	int total=0;
	for(int i=0; i<this->listaArts.size();i++){
		total+=listaArts[i]->getCantidad();
	}
	cout<<total<<endl;
}

void Tienda::ordenar(int cat,char talla){
	if(cat!=100 && talla!= 'X'){
		for(int j=0;j<listaArts.size();j++){	
			if(listaCats[cat]==listaArts[j]->getCategoria() /*&& talla==listaArts[j]->getTalla()*/){
				//cha
				Articulo* a = listaArts[j];
				for(int k=0; k<a->getTalla().size();k++){
					if(talla==a->getTalla()[k]){
						cout<<a->toString();
					}
				}
				
			}
			cout<<endl;
		}
	
	}else if(talla=='X'){
		for(int j=0;j<listaArts.size();j++){	
			if(listaCats[cat]==listaArts[j]->getCategoria()){
				cout<<listaArts[j]->toString();
			}
			cout<<endl;
		}
	}else if(cat==100){
		for(int j=0;j<listaArts.size();j++){	
			Articulo* a = listaArts[j];
			for(int k=0;a->getTalla().size();k++){
				if(talla==a->getTalla()[k]){
				cout<<a->toString();
			}
			cout<<endl;
			}
			
		}
	}
}

Tienda::~Tienda()
{
	for(int i=0; i<this->listaArts.size();i++){
		delete listaArts[i];
	}
	for(int i=0; i<this->listaCats.size();i++){
		delete listaCats[i];
	}
}