#include <iostream>//biblioteca padrao
#include <cstdlib>//funciona o rand
#include <ctime>//funciona o srand
#include <clocale>//padrao portugues
using namespace std;
setlocale(LC_ALL, "Portuguese");//padrao PT(13) para lingua
struct player{ //sera criada o player X e player O; 
	string name; //recebe o nome do jogador
	bool human; // se for falso entra no modo robo
	char simbolo;//escolha de simbolo p. marcar
	int round, draw, score;
	//round=incremento a cada jogada, draw=incremento a cada empate, score=recebe incremento a cada vitoria
};
struct game{//utilizada so uma vez que guarda todos esses parametros abaixo (game nerd;)
	char M[3][3];//matriz principal
	int linha, coluna, velha, roda, turno, partida;
	//linha & coluna = utilizado nas funcoes teclado & jogar;
	//velha=recebe o incremento a cada empate do jogo (desde instalado);
	//roda=recebe o incremento todos os turnos, para quando finalizar uma partida trocar quem comeca;
	//turno=vai de 0 a 9, e os loops principais utilizam essa variavel;
	//partida=recebe o incremento toda vez que termina uma partida;
	bool vitoria, VELHA;
	//ambas sao utilizadas pela funcao verificar jogador;
};
//VOLTAR AQUI >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void intro();//animacao de abertura;
void apagar();//solta uma porrada de cout`s vazios
void definir_jogadores(player*, player*);//e isso ai, recebe duas structs como parametro
void verificar_ganhador(game*);//struct
void imprimir(game*);
void teclado(char, game*);
void JOGAR(player*, game*);
void ROBO(player*, game*);
void jogo_da_velha(player*, player*, game*);
void placar(player*, player*, game*);
void replay(player *, player *, game*);
	
int main(){
	
	player X, O;// variaveis utilizadas em todo o programa
	game nerd;//tambem sao utilizadas em todo o programa
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
	//valores inicializados com valores inteiros;
	intro();//animacao
	cout << "\nBem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	definir_jogadores(&X, &O);//pega o endereco das variaveis X e O, que serao manipulados nas funcoes;
	cout << "Vamos brincar um pouquinho?\n";//convite
	jogo_da_velha(&X, &O, &nerd);//com esses enderecos manipula os valores que estao neles.
	replay(&X, &O, &nerd);//para comecar de novo
	cout << "\nTCHAU! :-)";
	cout << "***Software desenvolvido por: barbolux && reymc && hugozvanini\n";
	cout << "***Versão 0.5 beta \n";
	cout << "***Atualizado: 29/03/2017 \n";
	cout << "\nVolte sempre para incrementar seus RECORDES! :-)";
	return 0;
}
void jogo_da_velha(player *X, player *O, game *nerd){ //no replay e chamada outra vez
	apagar();
	X->round=1;//no player X, vai ser iniciado com 1 o round;
	O->round=1;
	nerd->turno=1;
	nerd->vitoria=false;
	nerd->VELHA=false;
	for (int i=0; i<3; i++){//inicializou tudo em negro nosso tabuleiro;
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
		if(nerd->roda%2==1)JOGAR(X, nerd);//alternancia entre os jogadores de cada turno
		else JOGAR(O, nerd);
	}
	cout << "FIM DA PARTIDA.\n";
	placar(X,O,nerd);
}
void JOGAR(player *p, game *nerd){
if(nerd->VELHA==true)cout << "A VELHA ganhou :-P";//
if(p->human==true){
	cout << "Para jogar usa as teclas^^^ acima.\n";
	cout << "Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
	bool certo=false; // verificacao se a casa a ser marcada esta vazia;
	while (certo==false)//
	{
		char tecla;
		cin >> tecla;
		teclado(tecla, nerd);//transpoe a tecla apertada para matriz
		if(nerd->M[nerd->linha][nerd->coluna]==' '){
			nerd->M[nerd->linha][nerd->coluna]=p->simbolo;// se estiver em branco coloca-se o simbolo no tabuleiro
			p->round++;
			nerd->turno++;
			nerd->roda++;
			apagar();
			imprimir(nerd);
			verificar_ganhador(nerd);
			certo=true;
			}//acontecem todas as operacoes
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
		}//COLOCAR Defaul<<<<<<<<<<
	}
	else
	{cout << "Tecla invalida.";
		cin >> tecla;
		teclado(tecla, nerd);
	}
}
void definir_jogadores(player *X, player *O){//definir o nome dos jogadores e simbolo
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
	}//colocar um cout dizendo que foi mudado para o padrao
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
	if ((nerd->M[0][0]==nerd->M[0][1])&& (nerd->M[0][1]==nerd->M[0][2]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[1][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[1][2]) && (nerd->M[1][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[2][0]==nerd->M[2][1])&& (nerd->M[2][1]==nerd->M[2][2]) && (nerd->M[2][0]!=' ')){
		nerd->vitoria=true;}
	
	if ((nerd->M[0][0]==nerd->M[1][0])&& (nerd->M[1][0]==nerd->M[2][0]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][1]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][1]) && (nerd->M[0][1]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][2])&& (nerd->M[1][2]==nerd->M[2][2]) && (nerd->M[0][2]!=' ')){
		nerd->vitoria=true;}
	
	if ((nerd->M[0][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][2]) && (nerd->M[0][0]!=' ')){
		nerd->vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][0]) && (nerd->M[0][2]!=' ')){
		nerd->vitoria=true;}

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
