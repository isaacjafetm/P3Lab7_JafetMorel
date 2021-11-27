#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
using namespace std;

class Categoria
{
	public:
		Categoria(string);
		~Categoria();
		string toString();
	private:
		string tipo;
};

#endif