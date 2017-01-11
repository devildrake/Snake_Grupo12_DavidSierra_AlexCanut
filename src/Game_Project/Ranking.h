#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Ranking {
public:
	//Struct jugador para guardar Puntuaciones y nombres
	typedef struct {
		string name;
		int highScore;

	}jugador;
	Ranking();
	
	~Ranking();
	
	 //Inicialización del array
	 jugador ranking[10] = { p1,p2,p3,p4,p5,p6,p7,p8,p9,p10 };

	 //Método que lee de un archivo binario los valores del array ranking en función del integer que se pasa como parametro
	void LeerBinario(int);

	//Método que escribe en un archivo binario los valores del array ranking en función del integer que se pasa como parametro
	void EscribirBinario(int);

	//Método que ordena el array ranking, recibe el array a ordenar y su longitud
	void OrdenarArray(jugador[],int);
private:
	//Diez variables Sample que se utilizan para inicializar el array ranking[10]
	jugador p1 = { "  ---  ",0 };
	jugador p2 = { "  ---  ",0 };
	jugador p3 = { "  ---  ",0 };
	jugador p4 = { "  ---  ",0 };
	jugador p5 = { "  ---  ",0 };
	jugador p6 = { "  ---  ",0 };
	jugador p7 = { "  ---  ",0 };
	jugador p8 = { "  ---  ",0 };
	jugador p9 = { "  ---  ",0 };
	jugador p10 = { "  ---  ",0 };
};