#ifndef AVIOES_HPP
#define AVIOES_HPP
#include <iostream>
#include <string>
#include "embarcacao.hpp"

class Pavioes : public Embarcacao {

private:
	int vida;
	int vida2;
	int vida3;
	int vida4;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
	string direcao;

public:

	Pavioes();
	~Pavioes();
	int get_vida();
	void set_vida(int vida);
	int get_vida2();
	void set_vida2(int vida2);
	int get_vida3();
	void set_vida3(int vida3);
	int get_vida4();
	void set_vida4(int vida4);
	int get_x2();
	void set_x2(int x2);
	int get_y2();
	void set_y2(int y2);
	int get_x3();
	void set_x3(int x3);
	int get_y3();
	void set_y3(int y3);
	int get_x4();
	void set_x4(int x4);
	int get_y4();
	void set_y4(int y4);
	string get_direcao();
	void set_direcao(string direcao);

	int AbaterMissil();
};

#endif