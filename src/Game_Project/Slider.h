#pragma once
#include "TimeManager.h"
#include "Sprites.h"
#include "ID.h"
#include <iostream>
#include <math.h>

class Slider {
public:

	//Constructor de la clase para inicializar valores
	Slider();

	//Destructor de la clase
	~Slider();

	//M�todo que actualiza el transform.w del sprite imagen
	//En funci�n de los dos Uint64 recibidos
	void Update(Uint64,Uint64);

	//M�todo que cambia los valores de posici�n y anchura original
	//a los parametros recibidos
	void StartSlider(int, int,int);

	//M�todo que pinta el sprite imagen
	void Draw();
private:
	//Sprite que se alargar� o acortar�
	Sprite imagen;

	//Atributo que contiene la informaci�n del tama�o original (m�ximo de la imagen)
	float originalSize;

};