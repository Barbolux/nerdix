/*BCC201 - TP1 - Semestre 2016.2 //cabeçalho

Trabalho prático JOGO DA VELHA.
UFOP - Universidade Federal de Ouro Preto.
DECOM - Departamento de Computação.
Professor. Puca
*** Programadores ***
	* Stefano Nogueira de Azevedo. n_16.1.5969
	* Hugo Zvanini. n_
	* Renato Tavares Goia. n_
*/

#include <iostream>
#include <stdio.h>
using namespace std;

//structs utilizadas no programa.

//funções utilizadas no programa.
void escolha_jogador();
void tabuleiro(); //novo nome da função "elementos_matriz"
void imprimir(); //novo nome da função "escrever_matriz"
void jogar_humano(); //novo nome da função "jogadas"
void jogar_robo();
void verificar_ganhador(); //ESTE ALGORITMO NAO ESTA DANDO CERTO :(
void jogo_da_velha(); //alterei o nome da função de jogo para jogo_da_velha.
void replay(); //transformei o replay numa função blz?
void placar(); //transformei o placar numa função blz?
void teclado(int); //função que recebe o valor do teclado e reverte em duas posições da matriz.

//declaração de variáveis globais.
	char M[3][3], jogador1, jogador2;
	int m_linha, m_coluna, tecla, jogada=0, turno=1, v1=0, v2=0;
	//mudei o nome das variaveis i e j para m_linha e m_coluna.
	bool certo=false, fim= false, ganhou= false;

int main(){ // MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN!
	cout << "Bem vindo ao jogo NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	jogo_da_velha();
	replay();
	placar();
	cout << "\nObrigado por jogar. TCHAU! :-)";
	return 0;
}
void escolha_jogador(){
	while (certo == false){
		cout << "Escolha o simbololo do jogador 1, [X] ou [O]: "<< endl;
		cin >> jogador1;

		if ((jogador1== 'X') || (jogador1== 'x')){
			jogador1 = 'X';
			jogador2 = 'O';
			certo= true;
		}
		else if((jogador1== 'O') || (jogador1== 'o')){
			jogador1 = 'O';
			jogador2 = 'X';
			certo = true;
		}
		else if(((jogador1 != 'X') || (jogador1 != 'x')) || ((jogador1== 'O') || (jogador1== 'o'))){
			cout << " Voce digitou um valor inválido! "<< endl;
			certo = false;
		}
	}
	cout << "Jogador 1 escolheu: "<< jogador1 << endl;
	cout << "Jogador 2 escolheu: "<< jogador2 << endl;

}
void tabuleiro(){
	for (m_linha=0; m_linha<3; m_linha++){
		for (m_coluna=0; m_coluna<3; m_coluna++){
			M[m_linha][m_coluna]= ' ';
		}
	}
}
void imprimir(){
	cout << endl;
	cout << "N E R D I X"<< endl;
	cout << "E "<< M[0][0] << " | "<< M[0][1] << " | "<< M[0][2] << " | "<<"   (1  2  3)"<<endl;
	cout << "R --|---|--"<< endl;
	cout << "D "<< M[1][0] << " | "<< M[1][1] << " | "<< M[1][2] << " | "<<"   (4  5  6)"<<endl;
	cout << "I --|---|--"<< endl;
	cout << "X "<< M[2][0] << " | "<< M[2][1] << " | "<< M[2][2] << " | "<<"   (7  8  9)"<<endl;
	cout << endl;
}
void jogar_humano(){
	certo = false;
	if (fim==false){
		if (turno==1){
			while (certo == false){
				cout << "Escolha a linha e coluna que deseja: ";
				cin >> tecla;
				teclado(tecla);
				if (M[m_linha][m_coluna]==' '){
					M[m_linha][m_coluna]=jogador1;
					certo = true;
					jogada++;
					turno=2;
					imprimir();
				}
				else {
					cout << "Jogada invalida"<< endl;
				}
			}
		}
		else if (turno==2){
			certo=false;
			while (certo==false){
				cout << "Escolha a linha e coluna que deseja: ";
				cin >> tecla;
				teclado(tecla);
				if (M[m_linha][m_coluna]==' '){
					M[m_linha][m_coluna]=jogador2;
					certo = true;
					jogada++;
					turno=1;
					imprimir();
				}
				else {
					cout << "Jogada invalida"<< endl;
				}
			}
		}
	}
}
void jogar_robo(){
	//blalaslas
}
void teclado(int a){
	if ( (a >= 1) && (a <= 9) ){
	switch (a){
		case 1:
		m_linha=0;
		m_coluna=0;
		break;
		case 2:
		m_linha=0;
		m_coluna=1;
		break;
		case 3:
		m_linha=0;
		m_coluna=2;
		break;
		case 4:
		m_linha=1;
		m_coluna=0;
		break;
		case 5:
		m_linha=1;
		m_coluna=1;
		break;
		case 6:
		m_linha=1;
		m_coluna=2;
		break;
		case 7:
		m_linha=2;
		m_coluna=0;
		break;
		case 8:
		m_linha=2;
		m_coluna=1;
		break;
		case 9:
		m_linha=2;
		m_coluna=2;
		break;
		}
								}
	else{
			cout << "Tecla inválida.";
			cin >> tecla;
			teclado(tecla);
			}
} //funciona, porém poderia ser otimizada.
void verificar_ganhador(){
	//horizontal
	if ((M[0][0]==M[0][1])&& (M[0][1]== M[0][2]) && (M[0][0]!=' ')){
		ganhou=true;
	}
	if ((M[1][0]==M[1][1])&& (M[1][1]== M[1][2]) && (M[1][0]!=' ')){
		ganhou=true;
	}
	if ((M[2][0]==M[2][1])&& (M[2][1]== M[2][2]) && (M[2][0]!=' ')){
		ganhou=true;
	}
	//vertical
	if ((M[0][0]==M[1][0])&& (M[1][0]== M[2][0]) && (M[0][0]!=' ')){
		ganhou=true;
	}
	if ((M[0][1]==M[1][1])&& (M[1][1]== M[2][1]) && (M[0][1]!=' ')){
		ganhou=true;
	}
	if ((M[0][2]==M[1][2])&& (M[1][2]== M[2][2]) && (M[0][2]!=' ')){
		ganhou=true;
	}
	//diagonal
	if ((M[0][0]==M[1][1])&& (M[1][1]== M[2][2]) && (M[0][0]!=' ')){
		ganhou=true;
	}
	if ((M[0][2]==M[1][1])&& (M[1][1]== M[2][0]) && (M[0][2]!=' ')){
		ganhou=true;
	}

	if (jogada==9){
		if (ganhou==false){
			cout << "Deu velha! "<< endl;
			fim = true;
		}
	}
	if (ganhou==true){
		if(turno==1){
			cout << "Parabens o jogador 2 ganhou! "<< endl;
			v2++;
		}
		else if (turno==2){
			cout << "Parabens o jogador 1 ganhou! "<< endl;
			v1++;
		}
	}

}
void jogo_da_velha(){
	escolha_jogador();
	tabuleiro();
	imprimir();
	jogada=0;
	while((jogada<=9)&&(ganhou==false)){
		jogar_humano();
		jogada++;
		verificar_ganhador();
	}
	placar();
}
void replay(){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N') cout << "Obrigado por jogar :-D Veja agora o resultado final do placar. \n\n";
		else if (novo=='s'||novo=='S') jogo_da_velha();
		else {cout << "Quê? Não entendi a tecla. "; replay();}
}
void placar(){
	cout << "PONTUAÇÃO:"<< endl;
	cout << "O jogador1 obteve " << v1 << " vitoria(s). "<< endl;
	cout << "O jogador2 obteve " << v2 << " vitoria(s). "<< endl;}
