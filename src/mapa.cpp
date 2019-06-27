#include "mapa.hpp"
#include "canoa.hpp"
#include "submarino.hpp"
#include "avioes.hpp"
#include "embarcacao.hpp"
#include "jogador.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Mapa::Mapa() {
	tam =0;
}

Mapa::~Mapa() {}

int Mapa::get_tam() {
	return tam;
}
void Mapa::set_tam(int tam) {
	this->tam = tam;
}

void Mapa::MostrarMapa(string *mapa, int tam_mapa) {

	int l;

	cout << endl <<"\t\t\t\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = BATALHA - NAVAL = = = = = = = = = = = = = = = = = = = = = = = = = " << endl<<endl;
	if(tam_mapa==11) {
			cout << "\t\t\t\t\t\t       1       2       3       4       5       6       7       8       9       10      11  ";
		}
		else if(tam_mapa==13) {
			cout << "\t\t\t\t\t\t       1       2       3       4       5       6       7       8       9       10      11      12      13";
		}
		else {
			cout << "\t\t\t\t\t\t       1       2       3       4       5       6       7       8       9       10      11      12      13     14     15";
		}

		for(int i=0;i<tam_mapa;i++) {
			l=0;
				cout << endl << "\t\t\t\t\t\t   ";
				for(int k=0;k<=tam_mapa*8;k++) {
				if(k%8!=0&&k!=64) {
					cout <<"▬";
				}
				else if(k==64) {
					cout << "│";	
				}
				else {
					cout << "│";
				}
			}
			cout << endl;
			for(int j=0;j<tam_mapa*8; j++) {
				if(j%8==0||j==0) {
					if(j==0) {
						if(i<9) {
							cout << "\t\t\t\t\t\t" << i+1 << "  │   ";
						}
						else {
							cout << "\t\t\t\t\t\t" << i+1 << " │   ";
						}
					}
					cout << mapa[i][l];
					l++;
				}
				else if(j%4==0) {
					cout << "│";
				}
				else {
					cout << ' ';
				}
			}
				if(i==tam_mapa-1) {
					cout << endl;
				}
				cout << "\t\t\t\t\t\t   ";
			if(i==tam_mapa-1) {
				for(int k=0;k<=tam_mapa*8;k++) {
					if(k%8!=0&&k!=64) {
						cout <<"▬";
					}
					else if(k==64) {
						cout << "│";	
					}
					else {
						cout << "│";
					}
				}
			}
		}
	

}

void Mapa::CriarMapas(string *mapa, int tam_mapa) {

	for(int i=0;i<tam_mapa;i++) {
		for(int j=0;j<tam_mapa;j++) {
			mapa[i][j] = ' ';
		}
	}
}


// Preenchendo lendo o arquivo txt
void Mapa::PreencherCoordenadas(Canoa *canoa1, Canoa *canoa2, Submarino *submarino1, Submarino *submarino2, Pavioes *paviao1, Pavioes *paviao2) {

	ifstream file;
	file.open("./doc/mapa.txt");

	int x,y;
	string tipo, sentido;

	char aux;
	string comentario;

 	int contCanoa=0, contSubmarino=0, contPaviao=0, i=-1;

	while(!file.eof()) {
		i++;
		aux = file.peek();
		if(aux=='#'||aux=='\n') {
			getline(file,comentario);
			i--;
		}
		else {
			file >> x >> y >> tipo >> sentido;

			if(tipo!="canoa") {
				contCanoa = 0;
			}
			if(tipo!="submarino") {
				contSubmarino = 0;
			}
			if(tipo!="porta-avioes") {
				contPaviao =0;
			}
			if(tipo=="canoa") {
				if(i<=6) {
					canoa1[contCanoa].set_x(x);
					canoa1[contCanoa].set_y(y);
					contCanoa++;
				}
				else {
					canoa2[contCanoa].set_x(x);
					canoa2[contCanoa].set_y(y);
					contCanoa++;
				}
			}
			else if(tipo=="submarino") {
				if(i<=10) {
					submarino1[contSubmarino].set_x(x);
					submarino1[contSubmarino].set_y(y);
					if(sentido == "esquerda") {
						submarino1[contSubmarino].set_x2(x);
						submarino1[contSubmarino].set_y2(y-1);
						submarino1[contSubmarino].set_direcao("esquerda");
					}
					else if(sentido == "direita") {
						submarino1[contSubmarino].set_x2(x);
						submarino1[contSubmarino].set_y2(y+1);
						submarino1[contSubmarino].set_direcao("direita");
					}
					else if(sentido == "cima") {
						submarino1[contSubmarino].set_x2(x-1);
						submarino1[contSubmarino].set_y2(y);
						submarino1[contSubmarino].set_direcao("cima");
					}
					else {
						submarino1[contSubmarino].set_x2(x+1);
						submarino1[contSubmarino].set_y2(y);
						submarino1[contSubmarino].set_direcao("baixo");
					}
					contSubmarino++;
				}
				else {
					submarino2[contSubmarino].set_x(x);
					submarino2[contSubmarino].set_y(y);
					if(sentido == "esquerda") {
						submarino2[contSubmarino].set_x2(x);
						submarino2[contSubmarino].set_y2(y-1);
						submarino2[contSubmarino].set_direcao("esquerda");
					}
					else if(sentido == "direita") {
						submarino2[contSubmarino].set_x2(x);
						submarino2[contSubmarino].set_y2(y+1);
						submarino2[contSubmarino].set_direcao("direita");
					}
					else if(sentido == "cima") {
						submarino2[contSubmarino].set_x2(x-1);
						submarino2[contSubmarino].set_y2(y);
						submarino2[contSubmarino].set_direcao("cima");
					}
					else {
						submarino2[contSubmarino].set_x2(x+1);
						submarino2[contSubmarino].set_y2(y);
						submarino2[contSubmarino].set_direcao("baixo");
					}
					contSubmarino++;
				}
			}
			else {
				if(i<=12) {
					paviao1[contPaviao].set_x(x);
					paviao1[contPaviao].set_y(y);
					if(sentido=="esquerda") {
						paviao1[contPaviao].set_x2(x);
						paviao1[contPaviao].set_y2(y-1);
						paviao1[contPaviao].set_x3(x);
						paviao1[contPaviao].set_y3(y-2);
						paviao1[contPaviao].set_x4(x);
						paviao1[contPaviao].set_y4(y-3);
						paviao1[contPaviao].set_direcao("esquerda");
					}
					else if(sentido=="direita") {
						paviao1[contPaviao].set_x2(x);
						paviao1[contPaviao].set_y2(y+1);
						paviao1[contPaviao].set_x3(x);
						paviao1[contPaviao].set_y3(y+2);
						paviao1[contPaviao].set_x4(x);
						paviao1[contPaviao].set_y4(y+3);
						paviao1[contPaviao].set_direcao("direita");
					}
					else if(sentido=="cima") {
						paviao1[contPaviao].set_x2(x-1);
						paviao1[contPaviao].set_y2(y);
						paviao1[contPaviao].set_x3(x-2);
						paviao1[contPaviao].set_y3(y);
						paviao1[contPaviao].set_x4(x-3);
						paviao1[contPaviao].set_y4(y);
						paviao1[contPaviao].set_direcao("cima");
					}
					else {
						paviao1[contPaviao].set_x2(x+1);
						paviao1[contPaviao].set_y2(y);
						paviao1[contPaviao].set_x3(x+2);
						paviao1[contPaviao].set_y3(y);
						paviao1[contPaviao].set_x4(x+3);
						paviao1[contPaviao].set_y4(y);
						paviao1[contPaviao].set_direcao("baixo");
					}
					contPaviao++;
				}
				else {
					paviao2[contPaviao].set_x(x);
					paviao2[contPaviao].set_y(y);
					if(sentido=="esquerda") {
						paviao2[contPaviao].set_x2(x);
						paviao2[contPaviao].set_y2(y-1);
						paviao2[contPaviao].set_x3(x);
						paviao2[contPaviao].set_y3(y-2);
						paviao2[contPaviao].set_x4(x);
						paviao2[contPaviao].set_y4(y-3);
						paviao2[contPaviao].set_direcao("esquerda");
					}
					else if(sentido=="direita") {
						paviao2[contPaviao].set_x2(x);
						paviao2[contPaviao].set_y2(y+1);
						paviao2[contPaviao].set_x3(x);
						paviao2[contPaviao].set_y3(y+2);
						paviao2[contPaviao].set_x4(x);
						paviao2[contPaviao].set_y4(y+3);
						paviao2[contPaviao].set_direcao("direita");
					}
					else if(sentido=="cima") {
						paviao2[contPaviao].set_x2(x-1);
						paviao2[contPaviao].set_y2(y);
						paviao2[contPaviao].set_x3(x-2);
						paviao2[contPaviao].set_y3(y);
						paviao2[contPaviao].set_x4(x-3);
						paviao2[contPaviao].set_y4(y);
						paviao2[contPaviao].set_direcao("cima");
					}
					else {
						paviao2[contPaviao].set_x2(x+1);
						paviao2[contPaviao].set_y2(y);
						paviao2[contPaviao].set_x3(x+2);
						paviao2[contPaviao].set_y3(y);
						paviao2[contPaviao].set_x4(x+3);
						paviao2[contPaviao].set_y4(y);
						paviao2[contPaviao].set_direcao("baixo");
					}
					contPaviao++;
				}
			}
		}
	}

	file.close();
}

//preenchendo coordenadas manualmente (dentro do jogo)
void Mapa::PreencherCoordenadas(Canoa *canoa, Submarino *submarino, Pavioes *paviao, Jogador *jogador) {
	int x, y, direcao;

	ifstream file1, file2, file3;
	file1.open("./doc/canoas.txt");
	file2.open("./doc/submarino.txt");
	file3.open("./doc/porta-aviao.txt");

	string arquivo1[35], arquivo2[35], arquivo3[35];

	for(int i=0; i<35; i++) {
		getline(file1, arquivo1[i]);
		getline(file2, arquivo2[i]);
		getline(file3, arquivo3[i]);
	}

	//Preenchendo coordenadas canoa
	for(int i=0; i<6; i++) {
		system("clear");
		for(int i=0; i<35; i++) {
			cout << arquivo1[i] << endl;
		}
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t - - - - - Jogador - - - - - (" << jogador->get_nome() << ") - - - "<<endl<< endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada X para a " << i+1 << " canoa:\t";
		cin >> x;
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada Y para a " << i+1 << " canoa:\t";
		cin >> y;
		if(x<1||x>13||y<1||y>13) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher uma coordenada entre 1 e 13. Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		canoa[i].set_x(x);
		canoa[i].set_y(y);
	}
	//Preenchendo coordenadas submarino
	for(int i=0; i<4; i++) {
		system("clear");
		for(int i=0; i<35; i++) {
			cout << arquivo2[i] << endl;
		}
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada X para o " << i+1 << " submarino:\t";
		cin >> x;
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada Y para o " << i+1 << " submarino:\t";
		cin >> y;
		cout << "\t\t\t\t\t\t\t\tEscolha uma direção para o submarino"<<endl << "\t\t\t\t\t\t\t\t1 - Esquerda" << endl << "\t\t\t\t\t\t\t\t2 - Direita" << endl << "\t\t\t\t\t\t\t\t3 - Cima" << endl << "\t\t\t\t\t\t\t\t4 - Baixo" << endl;
		cin >> direcao;
		if(x<1||x>13||y<1||y>13) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher uma coordenada entre 1 e 13. Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao!=1&&direcao!=2&&direcao!=3&&direcao!=4) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==1&&y==1) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==2&&y==13) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==3&&x==1) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==1&&x==13) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		submarino[i].set_x(x);
		submarino[i].set_y(y);
		if(direcao==1) {
			submarino[i].set_x2(x);
			submarino[i].set_y2(y-1);
		}
		else if(direcao==2) {
			submarino[i].set_x2(x);
			submarino[i].set_y2(y+1);
		}
		else if(direcao==3) {
			submarino[i].set_x2(x-1);
			submarino[i].set_y2(y);
		}
		else if(direcao==4) {
			submarino[i].set_x2(x+1);
			submarino[i].set_y2(y);
		}

	}

	for(int i=0; i<2; i++) {
		system("clear");
		for(int i=0; i<35; i++) {
			cout << arquivo3[i] << endl;
		}
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada X para o " << i+1 << " Porta-Aviões:\t";
		cin >> x;
		cout << "\t\t\t\t\t\t\t\tEscolha uma coordenada Y para o " << i+1 << " Porta-Aviões:\t";
		cin >> y;
		cout << "\t\t\t\t\t\t\t\tEscolha uma direção para o Porta-Aviões"<<endl << "\t\t\t\t\t\t\t\t1 - Esquerda" << endl << "\t\t\t\t\t\t\t\t2 - Direita" << endl << "\t\t\t\t\t\t\t\t3 - Cima" << endl << "\t\t\t\t\t\t\t\t4 - Baixo" << endl;
		cin >> direcao;
		if(x<1||x>13||y<1||y>13) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher uma coordenada entre 1 e 13. Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao!=1&&direcao!=2&&direcao!=3&&direcao!=4) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==1&&y<4) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==2&&y>10) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==3&&x<4) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		if(direcao==1&&x>10) {
			cout << "\t\t\t\t\t\t\t\tVocê deve escolher um valor válido para a direção! Precione ENTER para continuar" << endl;
			cin.ignore();
			getchar();
			i--;
			continue;
		}
		paviao[i].set_x(x);
		paviao[i].set_y(y);
		if(direcao==1) {
			paviao[i].set_x2(x);
			paviao[i].set_y2(y-1);
			paviao[i].set_x3(x);
			paviao[i].set_y3(y-2);
			paviao[i].set_x4(x);
			paviao[i].set_y4(y-3);
		}
		else if(direcao==2) {
			paviao[i].set_x2(x);
			paviao[i].set_y2(y+1);
			paviao[i].set_x3(x);
			paviao[i].set_y3(y+2);
			paviao[i].set_x4(x);
			paviao[i].set_y4(y+3);
		}
		else if(direcao==3) {
			paviao[i].set_x2(x-1);
			paviao[i].set_y2(y);
			paviao[i].set_x3(x-2);
			paviao[i].set_y3(y);
			paviao[i].set_x4(x-3);
			paviao[i].set_y4(y);
		}
		else if(direcao==4) {
			paviao[i].set_x2(x+1);
			paviao[i].set_y2(y);
			paviao[i].set_x3(x+2);
			paviao[i].set_y3(y);
			paviao[i].set_x4(x+3);
			paviao[i].set_y4(y);
		}

	}

}



