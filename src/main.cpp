#include "jogo.hpp"
#include "menu.hpp"
#include "mapa.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "jogador.hpp"
#include "avioes.hpp"
#include "embarcacao.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	Jogador *jogador1 = new Jogador();
	Jogador *jogador2 = new Jogador();

	Menu *menu = new Menu();
	Mapa *mapa = new Mapa();

	Jogo * jogo = new Jogo();

	Canoa canoa1[6], canoa2[6];
	Submarino submarino1[4], submarino2[4];
 	Pavioes paviao1[2], paviao2[2];

	int retorno, tam_mapa=15, contRodadas=0;

	string mapa1[15], mapa2[15];

	retorno = jogo->EstruturarPartida(jogador1,jogador2,*menu);

	mapa->CriarMapas(mapa1, tam_mapa);
	mapa->CriarMapas(mapa2, tam_mapa);

	// Opção de tamanho de mapa 11x11
	if(retorno==1) {
		mapa->PreencherCoordenadas(canoa1, canoa2, submarino1, submarino2, paviao1, paviao2);
		tam_mapa = 11;
	}
	// Opção de tamanho de mapa 13x13
	else if(retorno==2) {
		mapa->PreencherCoordenadas(canoa1, canoa2, submarino1, submarino2, paviao1, paviao2);
		tam_mapa = 13;
	}
	// Opção de tamanho de mapa 15x15
	else if(retorno==3) {
		mapa->PreencherCoordenadas(canoa1, canoa2, submarino1, submarino2, paviao1, paviao2);
		tam_mapa = 15;
	}
	// Opção de colocar as embarcações manualmente
	else if(retorno==4) {
		//preenchendo para jogador 1
		mapa->PreencherCoordenadas(canoa1, submarino1, paviao1, jogador1);
		// Preenchendo para jogador 2 
		mapa->PreencherCoordenadas(canoa2, submarino2, paviao2, jogador2);
		tam_mapa = 13;
	}

	while(jogador1->get_embarcacoes()>0&&jogador2->get_embarcacoes()>0) {
		//turno do jogador 1
		system("clear");

		mapa->MostrarMapa(mapa2,tam_mapa);

		jogo->JogarTurno(1, canoa2, submarino2, paviao2, mapa2, jogador2, jogador1, tam_mapa);

		getchar();

		//turno do jogador 2
		system("clear");

		mapa->MostrarMapa(mapa1,tam_mapa);

		jogo->JogarTurno(2, canoa1, submarino1, paviao1, mapa1, jogador1, jogador2, tam_mapa);

		getchar();

		contRodadas++;
	}

	menu->MostrarVencedor(jogador1,jogador2,contRodadas);

	return 0;

}
