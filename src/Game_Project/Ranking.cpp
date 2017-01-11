#include "Ranking.h"

//Método que lee los datos del archivo binario y los escribe en la variable ranking
void Ranking::LeerBinario(int n) {

		if (n == 0) {

			ifstream fentrada("rankingEasy.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}
		else if (n == 1) {
			ifstream fentrada("rankingMedium.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}
		else if (n == 2) {
			ifstream fentrada("rankingHard.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}

		else {
		}
}


//Método que escribe los datos de la variable ranking en el archivo binario
void Ranking::EscribirBinario(int n) {
	if (n == 0) {
		ofstream fsalida("rankingEasy.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
	else if (n == 1) {
		ofstream fsalida("rankingMedium.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
	else if (n == 2) {
		ofstream fsalida("rankingHard.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
}

//Método que ordena el array ranking, recibe el array a ordenar y su longitud
void Ranking::OrdenarArray(jugador arr[],int length) {
		jugador temp;
		int i, j;
		for (i = 0; i < (length); i++)
		{
			for (j = (i + 1); j < length; j++)
			{
				if (arr[i].highScore < arr[j].highScore)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
}

//Constructor 
Ranking::Ranking() {

}

//Destructor
Ranking::~Ranking() {
	delete[] ranking;
}