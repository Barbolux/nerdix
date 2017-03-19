//MUDANÇAS DA VERSÃO 0.3.1: a escolha de jogador agora coloca dados numa struct.
/*BCC201 - TP1 - Semestre 2016.2
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
#include <string>
using namespace std;

//structs utilizadas no programa.
struct player{// estrutura que contém os dados de cada jogador.
	string name; //nome do jogador.
	bool human; //quando false o jogador se comporta como robô.
	char simbolo; //permite você substituir o X e O por qualquer char do teclado.
//	int round=0; //registra quantas vezes ele jogou.
};

//funções utilizadas no programa.
void tabuleiro(); // Função que monta o tabuleiro vazio para início da partida.
void imprimir(); //
void jogar_humano(); // Jogada do player humano.
void jogar_robo(); // Jogada do player robô.
void verificar_ganhador(); //
void jogo_da_velha(); //
void replay(); //
void placar(); //
void teclado(char); //função que recebe o valor do teclado e reverte em duas posições da matriz.
//void escolha_jogador(); // colocado no main, mas queria devolver isso à condição de função quando descobrir como.

//declaração de variáveis globais:
	player X, O;
	char M[3][3], tecla;
	int m_linha, m_coluna, jogada=0, turno=1, v1=0, v2=0;
	bool certo=false, fim=false, ganhou=false;

int main(){ // MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN!
	cout << endl;
	cout << "Bem vindo ao jogo NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	cout << endl;
	cout << "Primeiro vamos definir que são os jogadores.\n";
	cout << endl;
	
	//a escolha do jogador será colocada no main agora. Depois vamos entender como ela pode voltar a ser uma função.
	//inicio da escolha do jogador 1.
	cout << "Digite o nome do jogador 1.\n(Escreva ROBO se quiser que o computador controle este jogador): ";
		cin >> X.name;
		if((X.name=="ROBO")||(X.name=="robo")){
			X.name="COMPUTADOR";
			X.human=false;
			X.simbolo='X';
		}
		else{
		X.human=true;
		cout << "Escolha o simbolo do jogador 1. (Padrão X): ";
		cin >> X.simbolo;
		if (X.simbolo==' ')X.simbolo='X';
		if (X.simbolo=='O')X.simbolo='X';
		if (X.simbolo=='o')X.simbolo='X';
		//verificações para evitar escolha de símbolos iguais.
		}
		cout << "Digite o nome do jogador 2.\n(Escreva ROBO quiser que o computador controle este jogador): ";
		cin >> O.name;
		if ((O.name=="ROBO")||(O.name=="robo")){
			if (O.human==true){
			O.name="COMPUTADOR";
			}
			if (O.human==false){
			X.name="COMPUTADOR1";
			O.name="COMPUTADOR2";
			}
			O.human=false;
			O.simbolo='O';
		}
		else{
		O.human=true;
		do{
		cout << "O nome já foi tomado pelo jogador 1. Escolha outro nome: ";
		cin >> O.name;}
		while (O.name==X.name);
		//verificação para evitar escolha de nomes repetidos.
		cout << "Escolha o simbolo do jogador 2. (Padrão O): ";
		cin >> O.simbolo;
		if (O.simbolo==' ')O.simbolo='O';
		if (O.simbolo=='X')O.simbolo='O';
		if (O.simbolo=='x')O.simbolo='O';
		if (O.simbolo==X.simbolo)O.simbolo = 'O';
		//verificações para evitar escolha de símbolos iguais.
		}

	cout << endl;
	cout << "Jogador 1 será: " << X.name << ", jogando com o símbolo '" << X.simbolo << "'.\n";
	cout << "Jogador 2 será: " << O.name << ", jogando com o símbolo '" << O.simbolo << "'.\n" << endl;
	//fim da escolha de jogadores. Queria entender como colocar isso tudo dentro de uma função
	//fim da escolha de jogadores. e passar os parâmetros da struct player por referência.
	//fim da escolha de jogadores. 
	//fim da escolha de jogadores.
	//fim da escolha de jogadores. 
	
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha();
	replay();
	placar();
	cout << "\nObrigado por jogar. TCHAU! :-)";
	return 0;
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
	cout << "N E R D I X   |"<< endl;
	cout << "E "<< M[0][0] << " | "<< M[0][1] << " | "<< M[0][2] << "   |   (1  2  3)"<<endl;
	cout << "R --|---|--   |"<< endl;
	cout << "D "<< M[1][0] << " | "<< M[1][1] << " | "<< M[1][2] << "   |   (4  5  6)"<<endl;
	cout << "I --|---|--   |"<< endl;
	cout << "X "<< M[2][0] << " | "<< M[2][1] << " | "<< M[2][2] << "   |   (7  8  9)"<<endl;
	cout << endl;
}
void jogar_humano(){
	
	jogada=0;
	while (ganhou!=true && jogada<9){
		certo = false;
		if (fim==false){
			if (turno==1){
				while (certo == false){
					cout << "Para jogar use as ^^^ teclas acima.\n(Turno do primeiro jogador)";
					cin >> tecla;
					teclado(tecla);
					if (M[m_linha][m_coluna]==' '){
						M[m_linha][m_coluna]=X.simbolo;
						certo = true;
						jogada+=1;
						turno=2;
						imprimir();
						verificar_ganhador();
					}
					else {
						cout << "Jogada inválida!"<< endl;
					}
				}
			}
			else if (turno==2){
				certo=false;
				while (certo==false){
					cout << "Para jogar use as ^^^ teclas acima.\n(Turno do segundo jogador)";
					cin >> tecla;
					teclado(tecla);
					if (M[m_linha][m_coluna]==' '){
						M[m_linha][m_coluna]=O.simbolo;
						certo = true;
						jogada+=1;
						turno=1;
						imprimir();
						verificar_ganhador();
					}
					else {
						cout << "Jogada invalida"<< endl;
					}
				}
			}
		}
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
void jogar_robo(){
	//blalaslas
}
void teclado(char a){
	if ((a=='1') || (a=='2') || (a=='3') || (a=='4') || (a=='5') || (a=='6') || (a=='7') || (a=='8') || (a=='9'))
	{switch (a){
		case '1':
		m_linha=0;
		m_coluna=0;
		break;
		case '2':
		m_linha=0;
		m_coluna=1;
		break;
		case '3':
		m_linha=0;
		m_coluna=2;
		break;
		case '4':
		m_linha=1;
		m_coluna=0;
		break;
		case '5':
		m_linha=1;
		m_coluna=1;
		break;
		case '6':
		m_linha=1;
		m_coluna=2;
		break;
		case '7':
		m_linha=2;
		m_coluna=0;
		break;
		case '8':
		m_linha=2;
		m_coluna=1;
		break;
		case '9':
		m_linha=2;
		m_coluna=2;
		break;
		}
	}
	else
	{	cout << "Tecla inválida.";
		cin >> tecla;
		teclado(tecla);
	}
}
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

}
void jogo_da_velha(){
	tabuleiro();
	imprimir();
	jogada=0;
	while((jogada<=9)&&(ganhou==false)){
		jogar_humano();
		jogada++;
		//verificar_ganhador();
	}
	replay();
}
void replay(){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N') cout << "Obrigado por jogar :-D Veja agora o resultado final do placar. \n\n";
		if (novo=='s'||novo=='S') jogo_da_velha();
		else {cout << "Quê? Não entendi a tecla. "; replay();}
}
void placar(){
	cout << endl;
	cout << "PONTUACAO:"<< endl;
	cout << "O jogador1 obteve " << v1 << " vitoria(s). "<< endl;
cout << "O jogador2 obteve " << v2 << " vitoria(s). "<< endl;
}
//void escolha_jogador(){} depreciada, por enquanto...
