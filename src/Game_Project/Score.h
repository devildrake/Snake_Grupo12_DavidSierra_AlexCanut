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

using namespace std;


//Clase score, tiene m�todos publicos Draw, Update y MakeTexture
class Score {
public:

	//M�todo que actualiza la puntuaci�n en funci�n de la puntuaci�n en escena
	void Update(int);

	//M�todo que Pinta la textura sobre el rect�ngulo a trav�s de la instancia de SDLRenderer
	void Draw();

	//M�todo que crea la textura en la posici�n de pantalla indicada
	void MakeTexture(int,int);

private:
	//Tama�o base de la fuente (p�xeles)
	int fontsize = 100;

	//Anchura texto 
	int t_width = 250;

	//Altura Texto
	int t_height = 100;

	//Posici�n del texto (x,y);
	int transformX = 0;
	int transformY = 0;

	//Variable que guarda la puntuaci�n que se debe imprimir por pantalla
	int puntuacionAImprimir;

	//Color del texto
	SDL_Color text_color = { 0,0,0 };

	//camino a la fuente del texto
	string fontpath = "../../res/fnt/arial.ttf";

	//Texto (Conjunto de Puntuaci�n y a�adiendole la variable puntuaci�n pasada a string
	string text = "Puntuaci�n: " + to_string(puntuacionAImprimir);

	//Puntero a variable Fuente
	TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);
	
	//Puntero a textura 
	SDL_Texture* ftexture = NULL; 

	//Rectangulo SDL sobre el que se imprimir� la textura de la puntuaci�n
	SDL_Rect dst = { transformX, transformY, t_width, t_height };

};