//TESTE DO FORK!
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;
struct player{
	string name;
	bool human;
	char simbolo;
	int round, draw, score;
};
struct game{
	char M[3][3];
	int linha, coluna, velha, roda, turno, partida;
	bool vitoria, VELHA;
};

void intro();
void apagar();
void definir_jogadores(player*, player*);
void verificar_ganhador(game*);
void imprimir(game*);
void teclado(char, game*);
void JOGAR(player*, game*);
void ROBO(player*, game*);
void jogo_da_velha(player*, player*, game*);
void placar(player*, player*, game*);
void replay(player *, player *, game*);
	
int main(){
	setlocale(LC_ALL, "Portuguese");
	player X, O;
	game nerd;
	X.round=1;
	O.round=1;
	X.score=0;
	O.score=0;
	X.draw=0;
	O.draw=0;
	nerd.velha=0;
	nerd.roda=1;
	nerd.turno=1;
	nerd.partida=1;
	intro();
	cout << "\nBem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	definir_jogadores(&X, &O);
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha(&X, &O, &nerd);
	replay(&X, &O, &nerd);
	cout << "\nTCHAU! :-)";
	cout << "***Software desenvolvido por: barbolux && reymc && hugozvanini\n";
	cout << "***Versão 0.5 beta \n";
	cout << "***Atualizado: 29/03/2017 \n";
	cout << "\nVolte sempre para incrementar seus RECORDES! :-)";
	return 0;
}
void jogo_da_velha(player *X, player *O, game *nerd){
	apagar();
	X->round=1;
	O->round=1;
	nerd->turno=1;
	nerd->vitoria=false;
	nerd->VELHA=false;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){nerd->M[i][j]= ' ';}}
	if (X->human==false && O->human==false){
	cout << "O computador venceu de si mesmo 100000 vezes em um segundo!\n";
	srand(time(NULL));
	O->score=rand();
	X->score=rand();
	nerd->velha=rand();
	placar(X, O, nerd);
	replay(X, O, nerd);
	}
	cout << "Que comece a disputa!" << endl;
	imprimir(nerd);
	while((nerd->turno<=9)&&(nerd->vitoria==false)){
		if(nerd->roda%2==1)JOGAR(X, nerd);
		else JOGAR(O, nerd);
	}
	cout << "FIM DA PARTIDA.\n";
	placar(X,O,nerd);
}
void JOGAR(player *p, game *nerd){
if(nerd->VELHA==true)cout << "A VELHA ganhou :-P";
if(p->human==true){
	cout << "Para jogar usa as teclas^^^ acima.\n";
	cout << "Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
	bool certo=false;
	while (certo==false)
	{
		char tecla;
		cin >> tecla;
		teclado(tecla, nerd);
		if(nerd->M[nerd->linha][nerd->coluna]==' '){
			nerd->M[nerd->linha][nerd->coluna]=p->simbolo;
			p->round++;
			nerd->turno++;
			nerd->roda++;
			apagar();
			imprimir(nerd);
			verificar_ganhador(nerd);
			certo=true;
			}
		else {cout << "Jogada inválida! ";}
	}
}
if(p->human==false){
cout << "Computador pensa...Robozinho em fase de testes :-/";
cout << "Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
ROBO(p, nerd);
}
if(nerd->vitoria==true){
cout << "Parabéns! "<<p->name<<" ganhou! "<< endl;
p->score++;}
}

void ROBO(player *r, game *nerd){
srand(time(NULL));
char tecla;
bool certo=false;
cout << "Vez de " << r->name <<"("<<r->simbolo<<") jogar. " << r->round <<"o Turno."<<endl;
	while (certo==false){
		cout << "Robô pensa sua jogada...\n";
		for (int i=0; i<3; i++){
			if      ((nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][2]=r->simbolo; certo=true;}
			else if ((nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(certo==false)){nerd->M[i][0]=r->simbolo; certo=true;}
			else if ((nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][1]=r->simbolo; certo=true;}
			else if ((nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[2][i]=r->simbolo; certo=true;}
			else if ((nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(certo==false)){nerd->M[0][i]=r->simbolo; certo=true;}
			else if ((nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[1][i]=r->simbolo; certo=true;}
			}
		while (certo==false){
			cout << "Debug, você vê esta mensagem? Pelo visto não né :-(";
			tecla = (rand()%9+49);
				cout << "... Ele pensa jogar na" << tecla <<endl;
				teclado((char) tecla, nerd);
				if(nerd->M[nerd->linha][nerd->coluna]==' '){
					nerd->M[nerd->linha][nerd->coluna]=r->simbolo;
					cout << "Robô jogou " << tecla << endl;
					certo=true;
					}
			}
	}
	r->round++;
	nerd->turno++;
	nerd->roda++;
	apagar();
	imprimir(nerd);
	verificar_ganhador(nerd);
}
void teclado(char tecla, game *nerd){
	if ((tecla=='1') || (tecla=='2') || (tecla=='3') || (tecla=='4') || (tecla=='5') || (tecla=='6') || (tecla=='7') || (tecla=='8') || (tecla=='9'))
	{switch (tecla){
		case '1':
		nerd->linha=0;
		nerd->coluna=0;
		break;
		case '2':
		nerd->linha=0;
		nerd->coluna=1;
		break;
		case '3':
		nerd->linha=0;
		nerd->coluna=2;
		break;
		case '4':
		nerd->linha=1;
		nerd->coluna=0;
		break;
		case '5':
		nerd->linha=1;
		nerd->coluna=1;
		break;
		case '6':
		nerd->linha=1;
		nerd->coluna=2;
		break;
		case '7':
		nerd->linha=2;
		nerd->coluna=0;
		break;
		case '8':
		nerd->linha=2;
		nerd->coluna=1;
		break;
		case '9':
		nerd->linha=2;
		nerd->coluna=2;
		break;
		}
	}
	else
	{cout << "Tecla invalida.";
		cin >> tecla;
		teclado(tecla, nerd);
	}
}
void definir_jogadores(player *X, player *O){
cout << "Primeiro vamos definir que sao os jogadores...\n";
cout << endl;
cout << "Digite o nome do jogador 1\n(Escreva ROBO quiser que o computador controle este jogador): ";
cin >> X->name;
if((X->name=="ROBO")||(X->name=="robo")){
	X->name="COMPUTADOR";
	X->human=false;
	X->simbolo='X';
	}
else{
	X->human=true;
	cout << "Escolha um simbolo para o jogador 1. (Padrao X): ";
	X->simbolo='X';
	cin >> X->simbolo;
	if (X->simbolo=='\n')X->simbolo='X';
	if (X->simbolo==' ')X->simbolo='X';
	if (X->simbolo=='O')X->simbolo='X';
	if (X->simbolo=='o')X->simbolo='X';
	}
cout << "Digite o nome do jogador 2.\n(Escreva ROBO quiser que o computador controle este jogador): ";
cin >> O->name;
if ((O->name=="ROBO")||(O->name=="robo")){
	if (X->human==true){
		O->name="COMPUTADOR";
		}
	else if (X->human==false){
		X->name="COMPUTADOR1";
		O->name="COMPUTADOR2";
	}
	O->human=false;
	O->simbolo='O';
	}
else{
	while(O->name==X->name){
		cout << "O nome ja foi tomado pelo jogador 1. Escolha outro nome: ";
		cin >> O->name;
	}
	O->human=true;
	cout << "Escolha um simbolo para o jogador 2. (Padrao O): ";
	O->simbolo='O';
	cin >> O->simbolo;
	if (O->simbolo=='\n')O->simbolo='O';
	if (O->simbolo==' ')O->simbolo='O';
	if (O->simbolo=='X')O->simbolo='O';
	if (O->simbolo=='x')O->simbolo='O';
	if (O->simbolo==X->simbolo)O->simbolo = 'O';
	}
	cout << endl;
	cout << "Jogador 1 sera: " << X->name << ", jogando com o simbolo '" << X->simbolo << "'.\n";
	cout << "Jogador 2 sera: " << O->name << ", jogando com o simbolo '" << O->simbolo << "'.\n" << endl;
}
void imprimir(game *nerd){
	if(nerd->VELHA==true){cout << "DEU VELHA...";}
	cout << ".Rodada geral: " << nerd->roda << endl;
	cout << ".Turno nesta partida: " << nerd->turno << endl;
	cout << ".______________________________.\n";
	if(nerd->turno==9){cout << "| nerdix        |   (Opções:)  | "<< endl;
	cout << "| e "<< nerd->M[0][0] << " | "<< nerd->M[0][1] << " | "<< nerd->M[0][2] << "   |   (";
	if(nerd->M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| r --|---|--   |   (       )  |"<< endl;
	cout << "| d "<< nerd->M[1][0] << " | "<< nerd->M[1][1] << " | "<< nerd->M[1][2] << "   |   (";
	if(nerd->M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| i --|---|--   |   (       )  |"<< endl;
	cout << "| x "<< nerd->M[2][0] << " | "<< nerd->M[2][1] << " | "<< nerd->M[2][2] << "   |   (";
	if(nerd->M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|_______________|______________|\n";}
	else if(nerd->roda%2==1){cout << "| N E R D I X   |   (Opções:)  | "<< endl;
	cout << "| e "<< nerd->M[0][0] << " | "<< nerd->M[0][1] << " | "<< nerd->M[0][2] << "   |   (";
	if(nerd->M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| r --|---|--   |   (       )  |"<< endl;
	cout << "| d "<< nerd->M[1][0] << " | "<< nerd->M[1][1] << " | "<< nerd->M[1][2] << "   |   (";
	if(nerd->M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| i --|---|--   |   (       )  |"<< endl;
	cout << "| x "<< nerd->M[2][0] << " | "<< nerd->M[2][1] << " | "<< nerd->M[2][2] << "   |   (";
	if(nerd->M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|_______________|______________|\n";}
	else{cout << "| N e r d i x   |   (Opções:)  | "<< endl;
	cout << "| E "<< nerd->M[0][0] << " | "<< nerd->M[0][1] << " | "<< nerd->M[0][2] << "   |   (";
	if(nerd->M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| R --|---|--   |   (       )  |"<< endl;
	cout << "| D "<< nerd->M[1][0] << " | "<< nerd->M[1][1] << " | "<< nerd->M[1][2] << "   |   (";
	if(nerd->M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| I --|---|--   |   (       )  |"<< endl;
	cout << "| X "<< nerd->M[2][0] << " | "<< nerd->M[2][1] << " | "<< nerd->M[2][2] << "   |   (";
	if(nerd->M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|_______________|______________|\n";}
}
void verificar_ganhador(game *nerd){
	//horizontal
	if ((nerd->M[0][0]==nerd->M[0][1])&& (nerd->M[0][1]==nerd->M[0][2]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[1][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[1][2]) && (nerd->M[1][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[2][0]==nerd->M[2][1])&& (nerd->M[2][1]==nerd->M[2][2]) && (nerd->M[2][0]!=' ')){
		nerd->vitoria=true;}
	
	//vertical
	if ((nerd->M[0][0]==nerd->M[1][0])&& (nerd->M[1][0]==nerd->M[2][0]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][1]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][1]) && (nerd->M[0][1]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][2])&& (nerd->M[1][2]==nerd->M[2][2]) && (nerd->M[0][2]!=' ')){
		nerd->vitoria=true;}
	
	//diagonal
	if ((nerd->M[0][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][2]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][0]) && (nerd->M[0][2]!=' ')){
		nerd->vitoria=true;}
	
	//VERIFICAÇÃO DA VELHA (não implementada)
	//nerd->VELHA=true;
	//nerd->velha++;
}
void placar(player *X, player *O, game *nerd){
	cout << endl;
	cout << "PONTUAÇÃO:"<< endl;
	cout << "1: O jogador " << X->name << " teve " << X->score << " vitória(s). "<< endl;
	cout << "2: O jogador " << O->name << " teve " << O->score << " vitória(s). "<< endl;
	cout << "3: A VELHA teve " << nerd->velha << " empate(s)."<< endl;
}
void replay(player *X, player *O, game *nerd){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N')cout << "\n\nObrigado por jogar :-D\n";
		else if (novo=='s'||novo=='S'){
		apagar();
		cout << "NOVA PARTIDA.\n";
		jogo_da_velha(X, O, nerd);
		replay(X, O, nerd);
		}
		else {cout << "Quê? Não entendi a tecla. "; replay(X, O, nerd);}
}
void intro(){
cout << "	.___________________.\n";
cout << "	|NERDIX |0.5|     29|\n";
cout << "	|E      |   |  março|\n";
cout << "	|R      |   |   2017|\n";
cout << "	|D      |   |       |\n";
cout << "	|I------|---|-------|\n";
cout << "	|X      |   |  DECOM|\n";
cout << "	|-------|---|-------|\n";
cout << "	| Prof. |   |   UFOP|\n";
cout << "	| Puca  |   |  Ouro |\n";
cout << "	| Huachi|   | Preto |\n";
cout << "	|_______|___|_______|\n";
}
void apagar(){cout << string( 100, '\n' );}
//NERDIX 0.5.0 beta
//DATA: 29/03/2017
//TP1.2016.2, BCC201 - UFOP
/*Universidade Federal de Ouro Preto, 2017.
 *Trabalho Prático JOGO DA VELHA
 **Professor Puca Huachi**
 **DECOM [Departamento de Computação]
	*** Programadores ***               Matrícula:
	* Hugo Zvanini. 					n_16.2.5849
	* Renato Tavares Goia. 				n_16.1.9999
	* Stefano Nogueira de Azevedo. 		n_16.1.5969
////LICENÇA:
////Este programa está licenciado como livre, gratuíto, de código aberto.
////Caso deseje fazer alguma contribuição ao código, fique à vontade.
////http://www.github.com/Barbolux/nerdix

* Informações sobre a versão *

Bugs encontrados:
- Na função definir_jogadores, se apertar ENTER direto quando pede para
receber um char, ele vai receber a primeira letra do string seguinte(letra)
ao invés de atribuir o padrão X ou O.
(Este bug acima já foi encontrado pelo Puca!)

FALTA IMPLEMENTAR:
*** Verificação da velha dentro da função "Verificar Ganhador";
*** ROBO continua burrão e nem ao menos entra no loop onde jogaria numa casa random.
*

"Em caso de dúvidas no código, verifique o código da versão 0.4.3"
 
*/
