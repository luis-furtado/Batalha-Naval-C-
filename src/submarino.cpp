#include "submarino.hpp"
#include <iostream>
#include <string>

using namespace std;

Submarino::Submarino() {
	set_x(0);
	set_y(0);
	set_x2(0);
	set_y2(0);
	set_vida(2);
	set_vida2(2);
	set_direcao("");
	set_naufragio(false);
}

Submarino::~Submarino() {}

int Submarino::get_x2() {
	return x2;
}
void Submarino::set_x2(int x2) {
	this->x2 = x2;
}

int Submarino::get_y2() {
	return y2;
}
void Submarino::set_y2(int y2) {
	this->y2 = y2;
}

int Submarino::get_vida(){
	return vida;
}
void Submarino::set_vida(int vida) {
	this->vida = vida;
}

int Submarino::get_vida2() {
	return vida2;
}
void Submarino::set_vida2(int vida2) {
	this->vida2 = vida2;
}

string Submarino::get_direcao() {
	return direcao;
}
void Submarino::set_direcao(string direcao) {
	this->direcao = direcao;
}

