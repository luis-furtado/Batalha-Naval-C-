#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP
#include <iostream>
#include <string>
#include "embarcacao.hpp"

using namespace std;

class Submarino : public Embarcacao {

private:

	int vida;
	int vida2;
	int x2;
	int y2;
	string direcao;

public:

	Submarino();
	~Submarino();

	int get_vida();
	void set_vida(int vida);

	int get_vida2();
	void set_vida2(int vida2);

	int get_x2();
	void set_x2(int x2);

	int get_y2();
	void set_y2(int y2);

	string get_direcao();
	void set_direcao(string direcao);

};

#endif
