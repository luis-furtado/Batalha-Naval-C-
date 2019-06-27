#include "avioes.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

Pavioes::Pavioes() {
	set_vida(1);
	set_vida2(1);
	set_vida3(1);
	set_vida4(1);
	set_x(0);
	set_y(0);
	set_x2(0);
	set_y2(0);
	set_x3(0);
	set_y3(0);
	set_x4(0);
	set_y4(0);
	set_direcao("");
	set_naufragio(false);
}

Pavioes::~Pavioes() {}

int Pavioes::get_vida() {
	return vida;
}
void Pavioes::set_vida(int vida) {
	this->vida = vida;
}

int Pavioes::get_vida2() {
	return vida2;
}
void Pavioes::set_vida2(int vida2) {
	this->vida2 = vida2;
}

int Pavioes::get_vida3() {
	return vida3;
}
void Pavioes::set_vida3(int vida3) {
	this->vida3 = vida3;
}

int Pavioes::get_vida4() {
	return vida4;
}
void Pavioes::set_vida4(int vida4) {
	this->vida4 = vida4;
}

int Pavioes::get_x2() {
	return x2;
}
void Pavioes::set_x2(int x2) {
	this->x2 = x2;
}

int Pavioes::get_y2() {
	return y2;
}
void Pavioes::set_y2(int y2) {
	this->y2 = y2;
}

int Pavioes::get_x3() {
	return x3;
}
void Pavioes::set_x3(int x3) {
	this->x3 = x3;
}

int Pavioes::get_y3() {
	return y3;
}
void Pavioes::set_y3(int y3) {
	this->y3 = y3;
}

int Pavioes::get_x4() {
	return x4;
}
void Pavioes::set_x4(int x4) {
	this->x4 = x4;
}

int Pavioes::get_y4() {
	return y4;
}
void Pavioes::set_y4(int y4) {
	this->y4 = y4;
}

string Pavioes::get_direcao() {
	return direcao;
}
void Pavioes::set_direcao(string direcao) {
	this->direcao = direcao;
}

int Pavioes::AbaterMissil() {
	int aux = floor(rand()%2);
	if(aux==1) {
		cout << endl << "\t\t\t\t\t\t\t\tMissil Abatido pelo Porta-Aviões! Precione ENTER para continuar." << endl;
		return 1;
	}
	else {
		cout << "\t\t\t\t\t\t\t\tVocê destruiu uma parte de um Porta-Aviões! Precione ENTER para continuar." << endl;
		return 0;
	}
}
