#pragma once
#include <iostream>

enum class ObjectID : const int { //enum de los distintos ids del juego
	S_00, //ID TitleFondo
	S_01, //ID Titulo
	S_02, //ID Bot�n Player
	S_03, //ID Bot�n F�cil
	S_04, //ID Bot�n Medio
	S_05, //ID Bot�n Dificil
	S_06, //ID Bot�n Salir
	S_07, //ID Fondo
	S_08, //ID CabezaSnake
	S_09, //ID CuerpoSnake
	S_10, //ID Manzana
	S_11, //ID Celda Roja
	S_12, //ID Celda Vac�a
	S_13, //ID Bot�n Ranking
	S_14, //ID Bot�n Back
	S_15  //ID imagen Cuadrado amarillo
	
};
inline std::ostream &operator<<(std::ostream &os, const ObjectID &id) { return os << int(id); }; //sobre carga ooperador <<
inline std::istream &operator>>(std::istream &is, ObjectID &id) { return is >> reinterpret_cast<int&>(id); }; //sobrecarga operador >>