#ifndef JOGO_HPP
#define JOGO_HPP
#include <iostream>
#include <string>
#include "jogador.hpp"
#include "menu.hpp"
#include "canoa.hpp"
#include "submarino.hpp"
#include "avioes.hpp"

using namespace std;

class Jogo {

private:

	int partida;

public:

	Jogo();
	Jogo(string mapa1, string mapa2);
	~Jogo();
	int get_partida();
	void set_partida(int partida);
	int EstruturarPartida(Jogador *jogador1, Jogador *jogador2, Menu menu);
	int JogarTurno(int num, Canoa *canoa, Submarino *submarino, Pavioes *paviao, string *mapa, Jogador *jogador, Jogador *jogador2, int tam_mapa);

};

#endif