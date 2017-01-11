#pragma once
#include "Sprites.h"
#include "ID.h"


//Clase tabla, la cual contiene un Array2D de sprites generado 
//de forma din�mica, las coordenadas del cual se usan como 
//referencia para mover y colocar el resto de elementos del juego
//As� como un m�todo para crear la tabla

class Tabla {
public:
	//Constructor de la tabla para incializar valores
	Tabla();

	//Destructor de la tabla para liberar la memoria del array 2D
	~Tabla();

	//M�todo Draw llamado desde el .Draw de la escena en la que se encuentre
	//una instancia de esta clase, el cual pinta toda la tabla, con celdas vac�as 
	//y bordes
	void Draw(void);

	//M�todo que reserva memoria para un array2D de sprites en funci�n de los dos
	//parametros integer que se le pasan
	void CrearTabla(int,int);

	//Puntero doble que luego se utilizar� como Array2D
	Sprite** sprites;

	//Atributos en los que se guardar�n el n�meor de filas y columnas asignados
	//Al llamar a CrearTabla
	int numC, numR;

	//Booleano que se asegura que la tabla no se cree m�s de una vez cada vez
	//que sea necesario 
	bool wasMade;

private:

};
