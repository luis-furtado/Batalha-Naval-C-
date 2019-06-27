#include <iostream>
#include <fstream>
#include <string>
#include "menu.hpp"

using namespace std;

Menu::Menu() {
	opcao = -1;
}

Menu::~Menu() {}

void Menu::MenuEntrada() {

	ifstream file;
	file.open("./doc/menuEntrada.txt");

	string arquivo[45];

	for(int i=0; i<45; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<45; i++) {
		cout << arquivo[i] << endl;
	}
	
	cin >> opcao;
	cin.ignore();
}

void Menu::MenuInstrucoes() {
	ifstream file;
	file.open("./doc/menuInstrucoes.txt");

	string arquivo[50];

	for(int i=0; i<50; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<50; i++) {
		cout << arquivo[i] << endl;
	}
	
	cin >> opcao;
	cin.ignore();

	set_opcao(opcao);
}

void Menu::MenuJogar() {
	ifstream file;
	file.open("./doc/menuJogar.txt");

	string arquivo[45];

	for(int i=0; i<45; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<45; i++) {
		cout << arquivo[i] << endl;
	}
	
	cin >> opcao;
	cin.ignore();

	set_opcao(opcao);
}

void Menu::DefinirMapa() {
	system("clear");
	ifstream file;
	file.open("./doc/definirMapa.txt");

	string arquivo[46];

	for(int i=0; i<46; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<46; i++) {
		cout << arquivo[i] << endl;
	}
	
	cin >> opcao;
	cin.ignore();

	set_opcao(opcao);
}

string Menu::ColetarNomes(int num) {
	system("clear");
	ifstream file;
	char arquivos[30];
	sprintf(arquivos,"./doc/definirNomes_%d.txt",num);
	file.open(arquivos);

	string arquivo[46];

	for(int i=0; i<46; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<46; i++) {
		cout << arquivo[i] << endl;
	}

	cout << endl << "\t\t\t\t\t\t\tNome:\t";
	string nome;
	getline(cin,nome);
	return nome;
}

void Menu::ComandoInvalido() {
	cout << "Comando Invalido! Programa encerrado." << endl;
	exit(1);
}

void Menu::MostrarVencedor(Jogador *jogador1, Jogador *jogador2, int Rodadas) {
	system("clear");
	ifstream file;
	file.open("./doc/vencedor.txt");

	string arquivo[40];

	for(int i=0; i<40; i++) {
		getline(file, arquivo[i]);
	}

	for(int i=0; i<40; i++) {
		cout << arquivo[i] << endl;
	}
	
	if(jogador2->get_embarcacoes()==0) {
		cout << endl <<"\t\t\t\t = = = = = = = = = = = = = = = = = = BATALHA - NAVAL = = = = = = = = = = = = = = = = =  " << endl;
		cout << endl << endl << "\t\t\t\t\t\t\t\t " << jogador1->get_nome() << " VENCEU !" << endl;
		cout << endl << "\t\t\t\t\t\t\t\t Quantidade de Rodadas:\t" << Rodadas << endl;
	}
	else {
		cout << endl <<"\t\t\t\t = = = = = = = = = = = = = = = = = = BATALHA - NAVAL = = = = = = = = = = = = = = = = =  " << endl;
		cout << endl << endl << "\t\t\t\t\t\t\t\t " << jogador2->get_nome() << " V E N C E U !" << endl;
		cout << endl << "\t\t\t\t\t\t\t\t Quantidade de Rodadas:\t" << Rodadas << endl;
	}
}

int Menu::get_opcao() {
	return opcao;
}

void Menu::set_opcao(int opcao) {
	this->opcao = opcao;
}
