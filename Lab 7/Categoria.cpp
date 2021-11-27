#include "Categoria.h"
#include <string>
Categoria::Categoria(string type)
{
	this->tipo=type;
}

Categoria::~Categoria()
{
}

string Categoria::toString(){
	return tipo;
}