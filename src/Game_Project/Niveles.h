#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <vector>

//Escena que controla la dificultad le�da a trav�s de XML de los niveles del juego
class Niveles : public Scene 
{
public:
	//Constructor
	explicit Niveles(); 
	//Destructor
	~Niveles() override;

	//Funci�n ejecutada al cambiar el estado de la escena a RUNNING
	void OnEntry(void) override;

	//Funci�n ejecutada al cambiar el estado de la escena a SLEEPING
	void OnExit(void) override;

	//Funci�n ejecutada en el Update General de escenas de GameEngine
	void Update(void) override;

	//Funci�n ejecutada en el Draw General de escenas de Renderer
	void Draw(void) override;

	//Funci�n que retorna datos del vector xmlVal en funci�n del valor pedido
	int static GetValue(std::string valor);


private:
	//Sprite del fondo
	Sprite background;

	//Sprite del t�tulo
	Sprite title;

	//Sprite del bot�n Facil
	Sprite easy;

	//Sprite del bot�n Medio
	Sprite med;

	//Sprite del bot�n Dif�cil
	Sprite hard;

	//Sprite del bot�n Back
	Sprite backButton;

};