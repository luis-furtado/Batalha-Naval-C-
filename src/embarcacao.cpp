#include "embarcacao.hpp"
#include <iostream>
#include <string>

using namespace std;

Embarcacao::Embarcacao() {
	x = 0;
	y = 0;
	naufragio = false;
}

Embarcacao::~Embarcacao() {}

int Embarcacao::get_x() {
	return x;
}
void Embarcacao::set_x(int x){
	this->x = x;
}

int Embarcacao::get_y() {
	return y;
}
void Embarcacao::set_y(int y){
	this->y = y;
}

bool Embarcacao::get_naufragio() {
	return naufragio;
}
void Embarcacao::set_naufragio(bool naufragio){
	this->naufragio = naufragio;
}
