#ifndef CANOA_HPP
#define CANOA_HPP
#include <iostream>
#include <string>
#include "embarcacao.hpp"

using namespace std;

class Canoa : public Embarcacao {

private:

	int vida;

public:

	Canoa();
	~Canoa();

	int get_vida();
	void set_vida(int vida);
	
};

#endif
