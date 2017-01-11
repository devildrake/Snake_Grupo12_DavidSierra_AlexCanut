#pragma once
#include <vector>
#include "Sprites.h"
using namespace std;

//Esta clase es la que contiene el conjunto de sprites que forman el cuerpo de la serpiente, as�
//Como sus funciones de actualizaci�n y pintado, comprovaci�n de choque con sigo misma y aumento de 
//posicion relativa en la tabla


class Snake{
public:
	vector<Sprite> conjuntoSerp; //Vector de sprites que conforman el cuerpo de la serpiente

    Snake(); //Constructor de la clase, inicializa los atributos necesarios
	
	~Snake(); //Destructor de la serpiente, hace un erase de todos los sprites contenidos en el 
	//vector <Sprite>conjuntoserp

	void Mov();//M�todo que detecta las inputs, funciona en funci�n de isBlocked e isAlive y cambia la variable dir 

	void Update(void); //M�todo que actualiza la posici�n "virtual" de la serpiente en la tabla

	void Draw(void); //M�todo que pinta todos los sprites del vector<Sprite> conjuntoSerp

	void A�adirTrozo(); //M�todo que a�ade sprites al vector

	void CheckCol(); //M�todo que comprueba las colisiones de la serpiente consigo misma

	int dir = 0; //Integer en funci�n del cual se varia la direccion de la serpiente

	float vel; //Variable que regula la velocidad de la serpiente

	int vidas; //Contador de vidas de la sepriente

	bool vidasChanged;

	int longSerpN; //Longitud que tenia la serpiente al entrar a cada nivel

	int iPosX; //Posicion inicial X de la cabeza dentro de la tabla

	int iPosY;//Posicion inicial  Y de la cabeza dentro de la tabla

	bool isBlocked; //Flag para que no se le puedan dar mas de una orden a la vez,
	//haciendo bypass a la prohibicion de cambio de rumbo de izquierda a derecha
	//sin pasar por arriba o abajo

	bool isAlive; //Booleano de vida

	bool hasMoved; //Flag para que el GameScene.cpp sepa cuando la serpiente se ha movido


	int posX; //Posicion X de la serpiente en la tabla
	int posY; //Posicion Y de la serpiente en la tabla

	int prevPosX; //Previa posicion X de la serpiente en la tabla
	int prevPosY; //Previa posicion Y de la serpiente en la tabla

	Uint64 timer; //Timer que marca el tiempo hasta el siguiente movimiento
	Uint64 prevTime; //contador del tiempo anterior para hacer comparaciones

	Sprite head; //Sprite de cabeza
	Sprite body; //Sprite de cuerpo
	Sprite tail; //Sprite de cuerpo (pero ir� en tercera posicion al principio)

private:

	//Atributo que se utiliza para comprobar si ha habido un cambio en el n�mero
	//de vidas de la serpiente para as� cambiar el numero de Vidas que se pintan
	int prevVidas;
};