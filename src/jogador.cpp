#include "jogador.hpp"
#include <iostream>
#include <string>

using namespace std;

Jogador::Jogador() {
	set_nome("");
	set_embarcacoes(22);
}

Jogador::~Jogador() {}

string Jogador::get_nome() {
	return nome;
}
void Jogador::set_nome(string nome) {
	this->nome = nome;
}

int Jogador::get_embarcacoes() {
	return embarcacoes;
}
void Jogador::set_embarcacoes(int embarcacoes) {
	this->embarcacoes = embarcacoes;
}

void lancarMissil() {
	cout << "Você lançou um missil!" << endl;
}
