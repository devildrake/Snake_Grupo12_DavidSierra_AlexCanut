#pragma once
#include "Scene.h"
#include "Sprites.h"

class MainMenu : public Scene
{
public: 

	//Constructor
	explicit MainMenu();

	//Destructor
	~MainMenu() override;

	//Metodo ejecutado al cambiar el estado de la escena a RUNNING
	void OnEntry(void) override;

	//Metodo ejecutado al cambiar el estado de la escena a SLEEPING
	void OnExit(void) override;

	//Metodo ejecutado en el Update General de escenas de GameEngine
	void Update(void) override;

	//Metodo ejecutado en el Draw General de escenas de Renderer
	void Draw(void) override;


private:
	//Sprite del fondo
	Sprite background; 

	//Sprite del t�tulo
	Sprite title;

	//Sprite del bot�n Jugar
	Sprite play;

	//Sprite del bot�n Exit
	Sprite exit;

	//Sprite del bot�n Ranking
	Sprite Sranking;

	//Posici�n transform.x de todos los botones
	int posX;

	//Anchura general de los botones
	int generalW;

	//Posicion transform.y de el boton play
	int posPlayY;

	//Posicion transform.y de el boton Ranking
	int posRankY;

	//Posicion transform.y de el boton Exit
	int posExitY;



};