#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <string>

using namespace std;

	class Jogador {

	private:
		string nome;
		int embarcacoes;

	public:
		Jogador();
		~Jogador();

		string get_nome();
		void set_nome(string nome);

		int get_embarcacoes();
		void set_embarcacoes(int embarcacoes);

		void lancarMissil();

	};

#endif
