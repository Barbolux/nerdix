#include <iostream>
#include <stdio.h>
using namespace std;


//char ModoDeJogo (char);
void escolha_jogador ();
void elementos_matriz();
void escrever_matriz ();
void jogadas();
void verificar_ganhador();
void jogo();

char M[3][3], jogador1, jogador2;
int i, j, jogada=0, turno=1, v1=0, v2=0;
bool certo=false, fim= false, ganhou= false;

int main()
{
	jogo();
	char novo; 
	while (novo !='n'){
		cout << "Deseja jogar novamente?"<< endl;
		cout << "Digite (s) para jogar (n) para sair: "<< endl;
		cin >> novo;
		if (novo=='s'|| novo=='S'){
			jogo();
		}
	}
	cout << " PONTUACAO:"<< endl;
	cout << "O jogador 1 obteve " << v1 << " vitorias. "<< endl;
	cout << "O jogador 2 obteve " << v2 << " vitorias. "<< endl;
	
	return 0;
}
/*char ModoDejogo (Char modo)
{
	/cout << "Selecione um das seguintes opções: "<< endl;
	//cout << "[1] jogador 1 começa o jogo"<< endl;
	//cout << "[2] jogador 2 começa o jogo"<< endl;
	//cout << "[s] se voce deseja sair do jogo "<< endl;
	//cin >> 
	//return 0;
	
	char modo;
	cout << "Selecione o modo de jogo: "<< endl;
	cout << "[C] Jogar conta o computador (jogador 2) "<< endl;
	cout << "[p] Jogar contra outra pessoa (jogador 1 e jogador 2 "<< endl;
	cin >> modo;
	return modo;*/
	
void escolha_jogador (char escolha)
{
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
			cout << " Voce digitou um valor invalido! "<< endl;
			certo = false;
		}
	}
	cout << "Jogador 1 escolheu: "<< jogador1 << endl;
	cout << "Jogador 2 escolheu: "<< jogador2 << endl;
	
}
void elementos_matriz()
{
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			M[i][j]= ' ';
		}
	}
}
void escrever_matriz ()
{
	cout << endl;
	cout << "  0   1   2"<< endl;
	cout << "0 "<< M[0][0] << " | "<< M[0][1] << " | "<< M[0][2] << " | "<< endl;
	cout << "  --|---|--"<< endl;
	cout << "1 "<< M[1][0] << " | "<< M[1][1] << " | "<< M[1][2] << " | "<< endl;
	cout << "  --|---|--"<< endl;
	cout << "2 "<< M[2][0] << " | "<< M[2][1] << " | "<< M[2][2] << " | "<< endl;
	
}
void jogadas()
{
	certo = false;
	if (fim==false){
		if (turno==1){
			while (certo == false){
				cout << "Escolha o numero e coluna que deseja: ";
				cin >> i >> j;
				if (M[i][j]==' '){
					M[i][j]=jogador1;
					certo = true;
					turno=2;
					escrever_matriz();
				}
				else {
					cout << "Jogada invalida";
				}
			}
		}
		else if (turno==2){
			certo=false;
			while (certo==false){
				cin >> i >> j;
				if (M[i][j]==' '){
					M[i][j]=jogador2;
					certo = true;
					turno=2;
					escrever_matriz();
				}
				else {
					cout << "Jogada invalida";
				}
			}
		}
	}
}
void verificar_ganhador()
{
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
}
void jogo()
{
	escolha_jogador ();
    elementos_matriz();
	escrever_matriz ();
	jogada=0;
	while((jogada<=9)&&(ganhou==false)){
		jogadas();
		jogada++;
		verificar_ganhador();
	}
}