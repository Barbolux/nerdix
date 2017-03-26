//tentativa de implementar funçao ALTERNAR.
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct player{// estrutura que contém os dados de cada jogador.
	string name; //nome do jogador.
	bool human; //quando false o jogador se comporta como robô.
	char simbolo; //simbolo que será utilizado como marcador no jogo.
	int round; //registra quantos turnos ele jogou.
	int score; //pontuação total deste jogador.
};
struct tabuleiro{
	char M[3][3];
	int linha, coluna, turno, roda, velha;
	bool vitoria;
};
	void intro();// animação de abertura.
	void jogo_da_velha(player *X, player *O, player **gira, player *aux, tabuleiro *nerd); //contém a ordem das funções para acontecer o jogo.
	void jogar_humano(player *X, player *O, player **gira, player *aux, tabuleiro *nerd); //jogada do player humano.
	void jogar_robo(player *X, player *O, player **gira, player *aux, tabuleiro *nerd); //jogada do player robô.
	void definir_jogadores(player *X, player *O, player **gira); //usuário insere os dados dos jogadores por cin.
	void imprimir(tabuleiro *nerd); //faz verificações de casas marcadas e lança os couts na tela.
	void verificar_ganhador(tabuleiro *nerd); //verifica o ganhador comparando as 8 condições de vitória.
	void placar(player *X, player *O, tabuleiro *nerd); //mostra os resultados gerais.
	void replay(player *X, player *O, player **gira, player *aux, tabuleiro *nerd); //permite começar a partida novamente.
	void teclado(char, tabuleiro *nerd); //recebe o valor do teclado e reverte em duas posições da matriz.
	void alternar(player *X, player *O, player **gira, player *aux, tabuleiro *nerd); //função que alterna os turnos e seleciona jogadores.
int main(){ // MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAINMAINMAINMAIN
	//declaração de variáveis e inicialização de valores.
	player X, O, aux, *gira;
	tabuleiro nerd;
	X.score=0;
	O.score=0;
	nerd.velha=0;
	nerd.roda=1;
	//início da interação com usuário.
	intro();
	cout << "\nBem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	definir_jogadores(&X, &O, &gira);
	cout << "nome X" << X.name << endl;
	cout << "nome O" << O.name << endl;
	cout << "nome gira" << (*gira).name << endl;
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha(&X, &O, &gira, &aux, &nerd);
	placar(&X, &O, &nerd);
	replay(&X, &O, &*gira, &aux, &nerd);
	cout << "\nVolte sempre. TCHAU! :-)";
	return 0;
}
void jogo_da_velha(player *X, player *O, player **gira, player *aux, tabuleiro *nerd){
	//reinicialização de valores para início da partida:
	X->round=1;
	O->round=1;
	nerd->turno=1;
	nerd->vitoria=false;
	//loop para preencher os elementos da matriz com "espaço em branco".
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			nerd->M[i][j]= ' ';}}
	//impressão de tela inicial.
	cout << endl << "Que comece a disputa!" << endl;
	imprimir(nerd);
	//jogo HUMANO X HUMANO.
	if(X->human==true && O->human==true){
		while((nerd->turno<=9)&&(nerd->vitoria==false)){jogar_humano(X, O, *gira, aux, nerd);}
		if (nerd->vitoria==true){
			cout << "Parabéns! " << gira->name << " ganhou! "<< endl;
			gira->score++;
		}
		imprimir(nerd);
		cout << "FIM DA PARTIDA.\n";
	}
	if (X->human!=O->human){//caso humano contra robô.
		while((nerd->turno<=9)&&(nerd->vitoria==false)){
		jogar_robo(X, O, gira, aux, nerd);}
		if (nerd->vitoria==true){
			cout << "Parabéns! " << gira->name <<" ganhou! "<<endl;
			gira->score++;
		}
		cout << "FIM DA PARTIDA.\n";
	}
	if (X->human==false && O->human==false){//easter egg.
		cout << "O computador venceu de si mesmo 100000 vezes em um segundo!\n";
		srand(time(NULL));
		O->score=rand();
		X->score=rand();
		}
}
void jogar_humano(player *X, player *O, player **gira, player *aux, tabuleiro *nerd){
	cout << "nome X" << X->name << endl;
	cout << "nome O" << O->name << endl;
	cout << "nome gira" << gira->name << endl;
	alternar(X, O, gira, aux, nerd);
	bool certo=false;
	cout << "Para jogar use as teclas^^^ acima.\n";
	cout << "Vez de " << gira->name <<"("<< gira->simbolo << ") jogar. " << endl;
	cout << "Seu [" << gira->round << "o TURNO]."<<endl;
	while (certo==false){
		char tecla;
		cin >> tecla;
		teclado(tecla, nerd);
		if(nerd->M[nerd->linha][nerd->coluna]==' '){
			certo=true;
			nerd->M[nerd->linha][nerd->coluna]=gira->simbolo;
			gira->round++;
			nerd->turno++;
			nerd->roda++;
			imprimir(nerd);
			verificar_ganhador(nerd);
		}
		else {cout << "Jogada inválida!\n";}
		}
}
void jogar_robo(player *X, player *O, player **gira, player *aux, tabuleiro *nerd){
	srand(time(NULL));
	char tecla;
	bool certo=false;
	while ((certo==false)&&(nerd->turno%2==1)){
			cout << "Para jogar use as teclas^^^ acima.\n";
			cout << "Vez de " << X->name <<"("<<X->simbolo<<") jogar. " << X->round <<"o Turno."<<endl;
			cin >> tecla;
			teclado(tecla, nerd);
			if(nerd->M[nerd->linha][nerd->coluna]==' '){
				nerd->M[nerd->linha][nerd->coluna]=X->simbolo;
				X->round++;
				nerd->turno++;
				nerd->roda++;
				certo=true;
			}
			else {cout << "Jogada inválida!\n";}
			verificar_ganhador(nerd);
	}
	while ((certo==false)&&(nerd ->turno%2==0)){
			cout << "Robô pensa sua jogada...\n";
			for (int i=0; i<3; i++){//loop do robô pensando nas casas que já tem 2 marcadas.
				if ((nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][2]=O->simbolo; certo=true;}//i_linha verificação A.
				else if ((nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(certo==false)){nerd->M[i][0]=O->simbolo; certo=true;}//i_linha verificação B.
				else if ((nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][1]=O->simbolo; certo=true;}//i_linha verificação C.
				else if ((nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[2][i]=O->simbolo; certo=true;}//i_coluna verificação A.
				else if ((nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(certo==false)){nerd->M[0][i]=O->simbolo; certo=true;}//i_coluna verificação B.
				else if ((nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[1][i]=O->simbolo; certo=true;}//i_coluna verificação C.
			}
			while (certo==false){
				tecla = (rand()%9+49);
				cout << "... Ele pensa jogar na" << tecla <<endl;
				teclado((char) tecla, nerd);
				if(nerd->M[nerd->linha][nerd->coluna]==' '){
					nerd->M[nerd->linha][nerd->coluna]=O->simbolo;
					cout << "Robô jogou " << tecla << endl;
					certo=true;
				}
			}
		O->round++;
		nerd->turno++;
		nerd->roda++;
		imprimir(nerd);
		verificar_ganhador(nerd);
	}
	}
void teclado(char tecla, tabuleiro *nerd){
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
void intro(){
cout << "	._______________.\n";
cout << "	| N E R D I X   |\n";
cout << "	| E   |   |     |\n";
cout << "	| R --|---|--   |\n";
cout << "	| D   |   |     |\n";
cout << "	| I --|---|--   |\n";
cout << "	| X   |   |     |\n";
cout << "	|_______________|\n";
}
void definir_jogadores(player *X, player *O, player **gira){
cout << "Primeiro vamos definir que sao os jogadores...\n";
cout << endl;
cout << "Digite o nome do jogador 1: ";
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
	if (X->simbolo=='o')X->simbolo='X';//verificações para evitar escolha de símbolos iguais.
	}
cout << "Digite o nome do jogador 2.\n(Escreva ROBO quiser que o computador controle este jogador): ";
cin >> O->name;
if ((O->name=="ROBO")||(O->name=="robo")){
	if (X->human==true){
		O->name="COMPUTADOR";
		}
	else if (X->human==false){
		X->name="COMPUTADOR1";
		O->name="COMPUTADOR2";//caso os dois sejam computadores serão rebatizados com o sobrenome 1 e 2.
	}
	O->human=false;
	O->simbolo='O';
	}
else{
	while(O->name==X->name){//verificação para evitar escolha de nomes repetidos.
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
	if (O->simbolo==X->simbolo)O->simbolo = 'O';//verificações para evitar escolha de símbolos iguais.
	}
	gira = X;
	cout << endl;
	cout << "Jogador 1 sera: " << X->name << ", jogando com o simbolo '" << X->simbolo << "'.\n";
	cout << "Jogador 2 sera: " << O->name << ", jogando com o simbolo '" << O->simbolo << "'.\n" << endl;
}
void imprimir(tabuleiro *nerd){
	cout << ".Rodada geral: " << nerd->roda << endl;
	cout << ".Turno nesta partida: " << nerd->turno << endl;
	cout << ".______________________________.\n";
	cout << "| N E R D I X   |   (Opções:)  | "<< endl;
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
	cout << "|_______________|______________|\n";
}
void verificar_ganhador(tabuleiro *nerd){
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
}
void placar(player *X, player *O, tabuleiro *nerd){
	cout << endl;
	cout << "PONTUACAO:"<< endl;
	cout << "1: O jogador " << X->name << " teve " << X->score << " vitória(s). "<< endl;
	cout << "2: O jogador " << O->name << " teve " << O->score << " vitória(s). "<< endl;
	cout << "3: A VELHA teve " << nerd->velha << " empate(s)."<< endl;
}
void replay(player *X, player *O, player **gira, player *aux, tabuleiro *nerd){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N'){
		cout << "\n\nObrigado por jogar :-D Veja agora o resultado final do placar.\n";
		placar(X, O, nerd);}
		else if (novo=='s'||novo=='S'){
		jogo_da_velha(X, O, gira, aux, nerd);
		placar(X, O, nerd);
		replay(X, O, gira, aux, nerd);}
		else {cout << "Quê? Não entendi a tecla. "; replay(X, O, *gira, aux, nerd);}
}
void alternar(player *X, player *O, player **gira, player *aux, tabuleiro *nerd){
	if (nerd->roda > 1){
		if (nerd->roda%2==1){
		aux=*gira;
		*gira=&X;
		O=aux;}
		if (nerd->roda%2==0){
		aux=*gira;
		*gira=&O;
		X=aux;}
	}
}
//NERDIX 0.4 beta
//TP1.2016.2, BCC201 - UFOP
/*Universidade Federal de Ouro Preto, 2017.
 *Trabalho Prático JOGO DA VELHA
 **Professor Puca Huachi**
 **DECOM [Departamento de Computação]
	*** Programadores ***
	* Hugo Zvanini. n_16.2.5849
	* Renato Tavares Goia. n_16.1.9999
	* Stefano Nogueira de Azevedo. n_16.1.5969

DATA: 25/03/2017
* Software versão 0.4.0
* Informações sobre a versão: continuidade do trabalho até agora.
* Foram removidas todas as variáveis globais :-D
* Agora o trabalho está recheado de ponteirinhos :)

LICENÇA: Este programa está licenciado como SOFTWARE LIVRE, gratuíto de código aberto.
* Para conhecer o Projeto NERDIX visite o site: http://www.github.com/Barbolux/Nerdix
* Caso deseje fazer uma contribuição ao programa, fique à vontade!

INDEX - Documentação, referência, implementação e instruções deste software.
***Perguntas & Respostas ***
* P: Quem é o jogador "gira"?
* R: Também conhecido como Ninja Jiraiya pelos homens ou Pomba-Gira pelas mulheres,
* este jogador apenas recebe os dados copiados de X ou O toda vez que é chamada
* a função "alternar".

* ESCREVER INDEX!
* ESCREVER INDEX!
* Escrever...

BUGTRACKER!
O QUE FALTA IMPLEMENTAR/CORRIGIR/Bugs.
**** Robô ainda ta meio idiota. Não verifica diagonais. Tem vezes que ele não joga, coitado.
**** Correção de bugs do cin >> char. (na seleção de simbolo de jogador, se apertar ENTER sem escrever nada temos bug).
**** Uma função que alterne os dois jogadores, baseada na variavel "roda".
**** Ainda não avisa quando deu VELHA.
**** Quando acontece a vitória, ele não imprime o tabuleiro.
*/
