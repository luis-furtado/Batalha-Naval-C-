#include "jogo.hpp"
#include "menu.hpp"
#include "mapa.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "jogador.hpp"
#include "avioes.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Jogo::Jogo() {
	partida = 0;
}

Jogo::~Jogo() {}

int Jogo::EstruturarPartida(Jogador *jogador1, Jogador *jogador2, Menu menu) {
	while(get_partida()==0) {
			system("clear");

			menu.MenuEntrada();
			// ir para a opção jogar 
			if(menu.get_opcao()==1) {
				set_partida(1);
				system("clear");
				menu.MenuJogar();
				//Opção de ler mapa através do Documento
				if(menu.get_opcao()==1) { 
					//coletando nomes
					jogador1->set_nome(menu.ColetarNomes(1));
					jogador2->set_nome(menu.ColetarNomes(2));
					//seleção do tamanho do mapa
					menu.DefinirMapa();
						// decidindo qual sera o tamanho do ampa
						if(menu.get_opcao()==1) {
							system("clear");
							return 1;
						}
						else if(menu.get_opcao()==2) {
							system("clear");
							return 2;
						}
						else if(menu.get_opcao()==3) {
							system("clear");
							return 3;
						}
						else if(menu.get_opcao()==4) {
							set_partida(0);
							continue;
						}
						else if(menu.get_opcao()==5) {
							exit(1);
						}
						else {
							menu.ComandoInvalido();
						}
				}
				// posicionar embarcações manualmente
				else if(menu.get_opcao()==2) {
					jogador1->set_nome(menu.ColetarNomes(1));
					jogador2->set_nome(menu.ColetarNomes(2));
					return 4;
				}
				else if(menu.get_opcao()==3) {
					set_partida(0);
					continue;
				}
				else if(menu.get_opcao()==4) {
					exit(1);
				}
				else {
					menu.ComandoInvalido();
				}
			}
			// Ir para instruções do jogo
			else if(menu.get_opcao()==2) {
				set_partida(1);
				system("clear");
				menu.MenuInstrucoes();
				if(menu.get_opcao()==1) {
					set_partida(0);
					continue;
				}
				else if(menu.get_opcao()==2) {
					exit(1);
				}
				else {
					while(menu.get_opcao()!=1&&menu.get_opcao()!=2) {
						menu.ComandoInvalido();
						continue;
					}
				}

			}

			else if(menu.get_opcao()==3) {
				exit(1);
			}
			else {
				menu.ComandoInvalido();
			}
	}
}

int Jogo::JogarTurno(int num, Canoa *canoa, Submarino *submarino, Pavioes *paviao, string *mapa, Jogador *jogador, Jogador *jogador2, int tam_mapa) {
	
	int aux=-1,aux2=-1, x, y, random=0;

	cout << endl << endl << endl << "\t\t\t\t\t\t\t\t\tPontuação total de "<< jogador2->get_nome() << " : "<< (jogador->get_embarcacoes()-22)*(-1) << endl;
	cout << "\t\t\t\t\t\t\t\t\tPontuação total de "<< jogador->get_nome() << " : "<< (jogador2->get_embarcacoes()-22)*(-1) << endl;
	cout << endl << endl << "\t\t\t\t\t\t\t - - - - - - Jogador " << num << " - - (" << jogador2->get_nome() << ")" << " - - - - - SUA VEZ! - - - - - - - - - - " << endl << endl;
	cout << endl << "\t\t\t\t\t\t\t\tDigite uma coordenada X para ataque:\t";
	cin >> aux;
	cout << endl <<"\t\t\t\t\t\t\t\tDigite uma coordenada Y para ataque:\t";
	cin >> aux2;
	cin.ignore();

	x = aux-1;
	y = aux2-1;

	int acerto = 0;

		if(aux>tam_mapa||aux2>tam_mapa) {
			cout << endl <<"\t\t\t\t\t\t\t\tVocê digitou uma coordenada inválida e perdeu sua vez. Precione ENTER para continuar." << endl;
			return 2;
		}
		for(int k=0; k<6; k++) {
			if(canoa[k].get_x()-1 == x && canoa[k].get_y()-1 == y) {
				canoa[k].set_vida(canoa[k].get_vida()-1);
				if(canoa[k].get_vida()<0) {
					cout << endl <<"\t\t\t\t\t\t\t\tVocê já acertou essa Canoa. Precione ENTER para continuar." << endl;
					return 2;
				}
				cout << endl <<"\t\t\t\t\t\t\t\tVocê acertou uma canoa! Precione ENTER para continuar." << endl;
				acerto = 1;
				mapa[x][y] = '/';
				jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
			}
		}
		for(int k=0; k<4; k++) {
			if(submarino[k].get_x()-1 == x && submarino[k].get_y()-1 == y) {
				submarino[k].set_vida(submarino[k].get_vida()-1);
				if(submarino[k].get_vida()>0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê acertou um submarino e causou 50% de dano! Precione ENTER para continuar." << endl;
					mapa[x][y] = '!';
				}
				else if(submarino[k].get_vida()==0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê destruiu uma parte de um submarino! Precione ENTER para continuar." << endl;
					mapa[x][y] = '*';
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
				}
				else {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê já destruiu esse submarino! Precione ENTER para continuar." << endl;
				}
				acerto = 1;
			}
			if(submarino[k].get_x2()-1 == x && submarino[k].get_y2()-1 == y) {
				submarino[k].set_vida2(submarino[k].get_vida2()-1);
				if(submarino[k].get_vida2()>0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê acertou um submarino e causou 50% de dano! Precione ENTER para continuar." << endl;
					mapa[x][y] = '!';
				}
				else if(submarino[k].get_vida2()==0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê destruiu uma parte de um submarino! Precione ENTER para continuar." << endl;
					mapa[x][y] = '*';
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
				}
				else {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê já destruiu esse submarino! Precione ENTER para continuar." << endl;
				}
				acerto = 1;
			}
		}
		for(int k=0; k<2; k++) {
			if(paviao[k].get_x()-1 == x && paviao[k].get_y()-1 == y) {
				acerto=1;
				if(paviao[k].get_vida()==0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê já destruiu esse Porta-Aviões! Precione ENTER para continuar." << endl;
					continue;
				}
				random = paviao[k].AbaterMissil();
				if(random==1) {
					continue;
				} 
				else {
					paviao[k].set_vida(paviao[k].get_vida()-1);
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
					mapa[x][y] = '#';
				}
			}
			else if(paviao[k].get_x2()-1 == x && paviao[k].get_y2()-1 == y) {
				acerto=1;
				if(paviao[k].get_vida2()==0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê já destruiu esse Porta-Aviões! Precione ENTER para continuar." << endl;
					continue;
				}
				random = paviao[k].AbaterMissil();
				if(random==1) {
					continue;
				} 
				else {
					paviao[k].set_vida2(paviao[k].get_vida2()-1);
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
					mapa[x][y] = '#';
				}
			}
			else if(paviao[k].get_x3()-1 == x && paviao[k].get_y3()-1 == y) {
				acerto=1;
				if(paviao[k].get_vida3()==0) {
					cout << endl<<"\t\t\t\t\t\t\t\tVocê já destruiu esse Porta-Aviões! Precione ENTER para continuar." << endl;
					continue;
				}
				random = paviao[k].AbaterMissil();
				if(random==1) {
					continue;
				} 
				else {
					paviao[k].set_vida3(paviao[k].get_vida3()-1);
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
					mapa[x][y] = '#';
				}
			}
			else if(paviao[k].get_x4()-1 == x && paviao[k].get_y4()-1 == y) {
				acerto=1;
				if(paviao[k].get_vida4()==0) {
					cout <<endl<< "\t\t\t\t\t\t\t\tVocê já destruiu esse Porta-Aviões! Precione ENTER para continuar." << endl;
					continue;
				}
				random = paviao[k].AbaterMissil();
				if(random==1) {
					continue;
				} 
				else {
					paviao[k].set_vida4(paviao[k].get_vida4()-1);
					jogador->set_embarcacoes(jogador->get_embarcacoes()-1);
					mapa[x][y] = '#';
				}
			}
		}
		if(acerto==0) {
			cout << endl << "\t\t\t\t\t\t\t\tVocê deu um tiro na água! Precione ENTER para continuar." << endl;
			mapa[x][y] = 'X';
		}
}

int Jogo::get_partida() {
	return partida;
}

void Jogo::set_partida(int partida) {
	this->partida = partida;
}