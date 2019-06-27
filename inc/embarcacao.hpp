#ifndef EMBARCACAO_HPP
#define EMBARCACAO_HPP
#include <iostream>
#include <string>

using namespace std;

class Embarcacao {
	
private:
	int x;
	int y;
	bool naufragio;

public:
	Embarcacao();
	~Embarcacao();

	int get_x();
	void set_x(int x);

	int get_y();
	void set_y(int y);

	bool get_naufragio();
	void set_naufragio(bool naufragio);

};

#endif
