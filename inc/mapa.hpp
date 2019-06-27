#ifndef MAPA_HPP
#define MAPA_HPP
#include <iostream>
#include <string>
#include "canoa.hpp"
#include "submarino.hpp"
#include "avioes.hpp"
#include "embarcacao.hpp"
#include "jogador.hpp"

using namespace std;

class Mapa {

private:
	int tam;

public:

	Mapa();
	~Mapa();

	int get_tam();
	void set_tam(int tam);
	void MostrarMapa(string *mapa, int tam_mapa);
	//preencher coordenadas através do mapa txt
	void PreencherCoordenadas(Canoa *canoa1, Canoa *canoa2, Submarino *submarino1, Submarino *submarino2, Pavioes *paviao1, Pavioes *paviao2);
	//preencher coordenadas manualmente
	void PreencherCoordenadas(Canoa *canoa, Submarino *submarino, Pavioes *paviao, Jogador *jogador);
	void CriarMapas(string *mapa, int tam_mapa);
	
};

#endif