#pragma once
#include "Scene.h"
#include "Sprites.h"
#include "Snake.h"
#include "Slider.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include "Niveles.h"
#include "MainMenu.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include <time.h>
#include "XML.h"
#include <math.h>
#include <utility>
#include "Ranking.h"
#include "Score.h"
#include "RankingScene.h"
#include "Vidas.h"
#include "Tabla.h"

//Clase GameScene que conglomera la mayor�a de los dem�s elemento del juego y gestiona algunas
//de sus interacci�nes

class GameScene : public Scene
{
public: 

	//Variable que guarda el numero de columnas y filas
	static int columnaFila;

	//Constructor, se inicializa la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	explicit GameScene();

	//Destructor de la clase
	~GameScene() override;
	
	//M�todo llamado cuando el estado de la escena cambia a RUNNING
	//Que inicializa hasStarted y grid.wasMade en false para poder 
	//Volver a crear un grid y llamar a la funci�n Start
	void OnEntry(void) override;

	//M�todo llamado cuando el estado de la escena cambia a SLEEPING
	void OnExit(void) override;

	//M�todo que se llama cada vez que se llama al Update general, el cual
	//Hace llamadas a todos los m�todos que son necesarios para actualizar
	//el mundo de juego
	void Update(void) override;

	//M�todo que se llama en el Draw general de GameEngine.h y que pinta todos los
	//elementos que forman parte de GameScene y deben ser pintados
	void Draw(void) override;

	//M�todo que comprueba las colisiones de la cabeza con todas las paredes de la tabla 
	//Y con los obst�culos en caso de que los haya y pone en false el booleano snake.isAlive
	//en caso de detectar colision
	void CheckHit();

	//M�todo que actualiza la posici�n en pantalla de la cabeza de la serpiente en funci�n
	//De su posici�n en tabla y borra el �ltimo sprite del vector adem�s de introducir un 
	//nuevo sprite en la segunda posici�n para generar la sensaci�n de que la serpiente se est� 
	//moviendo
	void ActualizarSnake();


	//M�todo que comprueba las colisiones con la manzana y en caso de haberla
	//Actua en consecuencia
	void CheckManzana();

	//M�todo que cambia la posici�n de la Snake a su posici�n original en tabla
	//Cambia su direcci�n a 0(nula) y borra todos los trozos de serpiente adicionales
	//en comparaci�n con los que ten�a al empezar el nivel en el que se encuentra
	void SnakeSpawn();

	//M�todo que cambia el "nivel" en el que se encuentra el jugador y actualiza los contadores temporales
	//de manzanas consecutivas sin perder vidas,longitud de la serpiente y puntuaci�n en funci�n de los valores que estos
	//tienen al empezar el nivel, tambien reinicia a 0 las manzanas comidas en el nivel actual.
	void ChangeLevel();


	//M�todo que coloca la serpiente en su posici�n original y reinicia los atributos de 
	//puntuaci�n, manzanas comidas consecutivamente sin perder vidas, manzanas comidas 
	//consecutivamente en el nivel actual, las variables de control de movimiento de la serpiente
	//as� como su variable de vida. Adem�s realiza llamadas a las funciones de reaparici�n de serpiente
	//as� como de cambio de posici�n de manzana.
	void Restart();


	//M�todo que borra el obstaculo previo (si lo hay) y establece uno nuevo en funci�n de la dificultad
	//en una posicion aleatoria teniendo en cuenta las dimensiones del nivel y en funcion de un numero random
	void SetObstacle();

	//M�todo que dibuja todos los sprites que conforman el obstaculo actual
	void DrawObstacle();

	//M�todo que comprueba si las vidas de la serpiente son 0, y de serlo 
	//pone en true el booleano gameOver
	void GameOverCheck();

	//M�todo al que se llama en caso de que el booleano hasStarted sea false 
	//cada vez que se llama al m�todo Update() y que se dedica a incializar
	//todos los elementos que considera necesarios para comenzar sin problemas
	//una partida
	void Start();

	//M�todo que cambia la posici�n de la manzana a una aleatoria dentro de las dimensiones de la tabla 
	void ChangeManPos(void);

	//Instancia de la clase Slider que representar� el tiempo restante del nivel actual al jugador
	Slider timeS;

	//Array de instancias de la clase Vidas que representar�n las vidas restantes del jugador
	Vidas lasVidas[3];

	//Instancia de la clase Score que representar� la puntuaci�n del jugador en pantalla
	Score scoreDisplay;

	//Instancia de la clase Ranking que se usar� para leer y escribir los archivos binarios
	Ranking instanciaRank;

	//Variable que guarda el tiempo por nivel en funci�n de XML
	Uint64 tiempoLevel;

	//Variable que guarda el tiempo por nivel en funci�n de XML pero teniendo en cuenta CurrentTime
	Uint64 realTiempoLevel;

	//Varpiable que guarda el tiempo previo para hacer calculos 
	Uint64 prevTime;

	int dificultad; //0 es easy, 1 es medium 2 es hard

	//Incremento de manzana obtenido por XML
	int applIncrease;

	//Nivel en el que se encuentra el jugador
	int lvl;
	
	//numero de manzanas a comer para pasar al siguiente nivel
	int numapples;

	//Manzanas comidas seguidas sin perder vidas
	int applesComidas;

	//manzanas comidas de forma consecutiva en lo que va de nivel
	int applesComidasNivel;

	//Tama�o orignial del Slider, se lee desed XML
	int sliderSize;

	//booleano que gestiona el fin del juego
	bool gameOver;

	//booleano que gestiona el comienzo del juego
	bool hasStarted;

	//booleano que gestiona la finalizaci�n del fin del juego
	bool ended;

	//Variable que guarda la puntuaci�nS
	float score;

	//Vector de sprites que forman el obst�culo
	vector <Sprite> obstaculo;

	//Atributo que guarda el numero de columnas
	int numC;

	//Atributo que guarda el numero de filas
	int numR;

	//Sprite de la manzana
	Sprite unaManzana;



private:
	//Atributo que guarda el tiempo restante teniendo en cuenta CurrentTime
	Uint64 remainingTime;

	//Instancia de la clase grid que se usar� para representar la tabla y mover 
	//y colocar el resto de elementos de juego
	Tabla grid;

	//Sprite del fondo
	Sprite fondo;
	//Sprite de pared;
	Sprite pared;

	//Sprite de la cabeza del snake
	Snake snake;

	//Sprite de la manzana
	Sprite manzana;

	//Variable de puntuaci�n previa
	int prevScore;

	//Posici�n Y en tabla de manzana
	int posAY;

	//Posici�n X en tabla de manzana
	int posAX;

};