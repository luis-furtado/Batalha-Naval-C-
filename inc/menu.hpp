#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include <jogador.hpp>

using namespace std;

class Menu {

private:
	int opcao;

public:

	Menu();
	~Menu();

	int get_opcao();
	void set_opcao(int opcao);

	void MenuEntrada();
	void MenuJogar();
	void ComandoInvalido();
	void DefinirMapa();
	string ColetarNomes(int num);
	void MostrarVencedor(Jogador *jogador1, Jogador *jogador2, int Rodadas);
	void MenuInstrucoes();

};

#endif