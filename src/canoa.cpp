#include "canoa.hpp"
#include <iostream>
#include <string>

using namespace std;

Canoa::Canoa() {
	set_x(0);
	set_y(0);
	set_naufragio(false);
	set_vida(1);
}

Canoa::~Canoa() {}

int Canoa::get_vida(){
	return vida;
}
void Canoa::set_vida(int vida) {
	this->vida = vida;
}

