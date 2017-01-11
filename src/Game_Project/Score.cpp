#include "Score.h"

//M�todo que actualiza la puntuaci�n en funci�n de la puntuaci�n en escena
void Score::Update(int score) {
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	ftexture = SDL_CreateTextureFromSurface(R.m_SDLRenderer, text_surface);
	puntuacionAImprimir = score;
	 text = "Puntuaci�n: " + to_string(score);
	 SDL_FreeSurface(text_surface);
}

//M�todo que Pinta la textura sobre el rect�ngulo a trav�s de la instancia de SDLRenderer
void Score::Draw() {
	SDL_RenderCopy(R.m_SDLRenderer, ftexture, NULL, &dst); 
}

//M�todo que crea la textura en la posici�n de pantalla indicada
void Score::MakeTexture(int anX, int anY) {
	dst.x = anX;
	dst.y = anY;
	if (font == NULL) {
		cerr << "Failed the load the font!\n";
		cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
	}
	else {
		// now create a surface from the font
		SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);

		// render the text surface
		if (text_surface == NULL) {
			cerr << "Failed to render text surface!\n";
			cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
		}
		else {
			// create a texture from the surface
			ftexture = SDL_CreateTextureFromSurface(R.m_SDLRenderer, text_surface);

			if (ftexture == NULL) {
				cerr << "Unable to create texture from rendered text!\n";
			}
			else {
				t_width = text_surface->w; // assign the width of the texture
				t_height = text_surface->h; // assign the height of the texture

											// clean up after ourselves (destroy the surface)
				SDL_FreeSurface(text_surface);
			}
		}
	}
}
