#pragma once
#include "SDL.h"
#include <string.h>
#include <string>
#include <iostream>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_render.h"
#include "Renderer.h"
#include "Window.h"
#include "Scene.h"
#include "Ranking.h"
#include "Sprites.h"
#include "ID.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Niveles.h"
using namespace std;

//Escena que muestra
class RankingScene : public Scene
{
public: //decalaracion de variables y metodos publicos

	//Constructor
	explicit RankingScene();

	//Destructor
	~RankingScene() override;

	//M�todo ejecutado al cambiar el estado de la escena a RUNNING
	void OnEntry(void) override;
	
	//M�todo ejecutado al cambiar el estado de la escena a SLEEPING
	void OnExit(void) override;

	//M�todo ejecutado en el Update General de escenas de GameEngine
	void Update(void) override;

	//M�todo ejecutado en el Draw General de escenas de Renderer
	void Draw(void) override;

	//M�todo que, una vez le�dos los archivos desde el binario, establece los valores en los arrays declarados arriba
	void SetScores();

	//M�todo que hace una textura por cada texto declarado y las asigna a los arrays de texturas declarados arriba
	void MakeTextures();

	//M�todo que establece si se accede a la escena desde GameScene o desde el Men� principal
	void static SetFrom(bool);

private:

	//Tama�o base de la fuente (p�xeles)
	int fontsize = 80;

	//Anchura texto 
	int t_width = 250;

	//Altura Texto
	int t_height = 100; // height of the loaded font-texture

	//Posici�n Titulo
	int transformX = 0;
	int transformY = 0;

	//Booleanos para que solo se ejecute una vez el c�digo de lectura y creaci�n de texturas
	bool set;
	bool drawn;

	//Array preexistente al que asignarle los datos del array guardado en el archivo binario
	int puntuacionesAImprimir[10];

	//Color del texto
	SDL_Color text_color = { 0,0,0 };

	//camino a la fuente del texto
	string fontpath = "../../res/fnt/arial.ttf";

	//Texto del T�tulo
	string iText = "HighScores";

	//Imagen de fondo
	Sprite background;

	//Bot�n Back
	Sprite backButton;

	//Array que contendr� las puntuaciones pasadas a string para poderlas poner en pantalla
	string scores[10];

	//Array que contendr� los nombres de los jugadores del ranking
	string names[10];

	//Variable Fuente
	TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);

	//Puntero a textura para el titulo
	SDL_Texture* ftexture = NULL;

	//Punteros a texturas de las puntuaciones
	SDL_Texture* texturaScore[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	//Punteros a texturas de los nombres
	SDL_Texture* texturaNombres[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	//Instancia de la clase Ranking
	Ranking instanciaRank;

	//Rectangulo SDL sobre el que se imprimir� el textos iText
	SDL_Rect dst = { transformX + W.GetWidth() / 3, transformY, t_width, t_height };

	//Rectangulos SDL sobre los que se imprimir�n las texturas de la puntuaci�n y nombres
	SDL_Rect scoresRect[10];
	SDL_Rect namesRect[10];
	

};