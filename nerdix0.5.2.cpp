//ROBO FUNCIONA!(em fase de testes porra)
//Diferenças da versão:
//função teclado MODIFICADA, varias coisas foram colocadas dentro dela!
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;
struct player{
	string name;
	bool human;
	char simbolo;
	int round, draw, score;
};
struct game{
	char M[3][3];
	int velha, roda, turno, partida;
	bool vitoria, VELHA;
};
void intro();
void apagar();
void imprimir(game*);
void definir_jogadores(player*, player*);
void jogo_da_velha(player*, player*, game*);
void verificar_ganhador(game*);
void teclado(player*, game*);
void JOGAR(player*, game*);
void ROBO(player*, game*);
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
	nerd.velha=0;
	nerd.roda=1;
	nerd.turno=1;
	nerd.partida=1;
	intro();
	//ranking();
	cout << "\nBem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	definir_jogadores(&X, &O);
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha(&X, &O, &nerd);
	replay(&X, &O, &nerd);
	cout << "\nTCHAU! :-)";
	cout << "***Software desenvolvido por: barbolux && hugotones && reymc\n";
	cout << "***Versão 0.5.2 beta \n";
	cout << "***Atualizado: 02/04/2017 \n";
	cout << "\nVolte sempre para incrementar seus RECORDES! :-)";
	X.draw=nerd.velha;
	O.draw=nerd.velha;
	//recordes();
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
		for (int j=0; j<3; j++){nerd->M[i][j]=' ';}}
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
	teclado(p, nerd);
	p->round++;
	nerd->turno++;
	nerd->roda++;
	apagar();
	imprimir(nerd);
	verificar_ganhador(nerd);
}
if(p->human==false){ROBO(p, nerd);}
if(nerd->vitoria==true){
cout << "Parabéns! "<<p->name<<" ganhou! "<< endl;
p->score++;}
if (nerd->vitoria==false && nerd->turno > 9){
	cout << "A VELHA ganhou :-P\n";
	nerd->velha++;
	nerd->VELHA=true;
}
}
void ROBO(player *p, game *nerd){
bool certo=false;
if (p->round==1){teclado(p, nerd);}//no primeiro turno, basta uma só jogada aleatória né!
if (p->round==2){
	//algoritmo "IMPEDIR VITORIA DO ADVERSARIO":
	for (int i=0; i<3; i++){
	//linhas
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][2]==' ')){nerd->M[i][2]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(nerd->M[i][0]==' ')){nerd->M[i][0]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][1]==' ')){nerd->M[i][1]=p->simbolo; certo=true; i=3;}
	//colunas
	if((certo==false)&&(nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[2][i]==' ')){nerd->M[2][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(nerd->M[0][i]==' ')){nerd->M[0][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[1][i]==' ')){nerd->M[1][i]=p->simbolo; certo=true; i=3;}
	}
	//diagonais
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][0])&&(nerd->M[0][0]!=' ')&&(nerd->M[2][2]==' ')){nerd->M[2][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[0][0]==' ')){nerd->M[0][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][0])&&(nerd->M[2][0]!=' ')&&(nerd->M[0][2]==' ')){nerd->M[0][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[2][0]==' ')){nerd->M[2][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[0][0]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[2][0]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	//se nada funcionar, joga o teclado:
	if(certo==false)teclado(p, nerd);
}
if ((p->round==3)||(p->round==4)){
	//primeiro robô analiza se tem 2 marcadas por ele proprio e tenta GANHAR.
	for (int i=0; i<3; i++){
	//linhas
	if((certo==false)&&(nerd->M[i][0]==p->simbolo)&&(nerd->M[i][1]==p->simbolo)&&(nerd->M[i][2]==' ')){nerd->M[i][2]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][1]==p->simbolo)&&(nerd->M[i][2]==p->simbolo)&&(nerd->M[i][0]==' ')){nerd->M[i][0]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][0]==p->simbolo)&&(nerd->M[i][2]==p->simbolo)&&(nerd->M[i][1]==' ')){nerd->M[i][1]=p->simbolo; certo=true; i=3;}
	//colunas
	if((certo==false)&&(nerd->M[0][i]==p->simbolo)&&(nerd->M[1][i]==p->simbolo)&&(nerd->M[2][i]==' ')){nerd->M[2][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[1][i]==p->simbolo)&&(nerd->M[2][i]==p->simbolo)&&(nerd->M[0][i]==' ')){nerd->M[0][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[2][i]==p->simbolo)&&(nerd->M[0][i]==p->simbolo)&&(nerd->M[1][i]==' ')){nerd->M[1][i]=p->simbolo; certo=true; i=3;}
	}
	//diagonais
	if((certo==false)&&(nerd->M[1][1]==p->simbolo)&&(nerd->M[0][0]==p->simbolo)&&(nerd->M[2][2]==' ')){nerd->M[2][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==p->simbolo)&&(nerd->M[2][2]==p->simbolo)&&(nerd->M[0][0]==' ')){nerd->M[0][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==p->simbolo)&&(nerd->M[2][0]==p->simbolo)&&(nerd->M[0][2]==' ')){nerd->M[0][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==p->simbolo)&&(nerd->M[0][2]==p->simbolo)&&(nerd->M[2][0]==' ')){nerd->M[2][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[0][0]==p->simbolo)&&(nerd->M[2][2]==p->simbolo)&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[2][0]==p->simbolo)&&(nerd->M[0][2]==p->simbolo)&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	
	//em seguida, ele vai tentar o impedimento da vitoria do adversario.
	for (int i=0; i<3; i++){
	//linhas
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][0]!=p->simbolo)&&(nerd->M[i][2]==' ')){nerd->M[i][2]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(nerd->M[i][1]!=p->simbolo)&&(nerd->M[i][0]==' ')){nerd->M[i][0]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][0]!=p->simbolo)&&(nerd->M[i][1]==' ')){nerd->M[i][1]=p->simbolo; certo=true; i=3;}
	//colunas
	if((certo==false)&&(nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[0][i]!=p->simbolo)&&(nerd->M[2][i]==' ')){nerd->M[2][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(nerd->M[1][i]!=p->simbolo)&&(nerd->M[0][i]==' ')){nerd->M[0][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[0][i]!=p->simbolo)&&(nerd->M[1][i]==' ')){nerd->M[1][i]=p->simbolo; certo=true; i=3;}
	}
	//diagonais
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][0])&&(nerd->M[0][0]!=' ')&&(nerd->M[0][0]!=p->simbolo)&&(nerd->M[2][2]==' ')){nerd->M[2][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[2][2]!=p->simbolo)&&(nerd->M[0][0]==' ')){nerd->M[0][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][0])&&(nerd->M[2][0]!=' ')&&(nerd->M[2][0]!=p->simbolo)&&(nerd->M[0][2]==' ')){nerd->M[0][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[0][2]!=p->simbolo)&&(nerd->M[2][0]==' ')){nerd->M[2][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[0][0]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[2][2]!=p->simbolo)&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[2][0]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[0][2]!=p->simbolo)&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	//se não achou nada, chama o teclado.{teclado(p, nerd);
	if(certo==false)teclado(p, nerd);
}

if(p->round==5){
	for (int i=0; i<3; i++){for (int j=0; j<3; j++){ //loop duplicado para percorrer a martriz.
	if(nerd->M[i][j]==' '){nerd->M[i][j]=p->simbolo;}}}
}

//TERMINO DA FUNÇÃO...
	cout << "Robô pensa...\n";
	p->round++; nerd->turno++; nerd->roda++;
	apagar();
	imprimir(nerd);
	verificar_ganhador(nerd);
}
void teclado(player *p, game *nerd){
bool certo;
char tecla;
int linha, coluna;
srand(time(NULL));
do{
if (p->human)cin >> tecla;//jogada do humano
else {tecla=(char)(rand()%9+49);}//jogada do robo
switch (tecla){
		case '1':
		linha=0;
		coluna=0;
		break;
		case '2':
		linha=0;
		coluna=1;
		break;
		case '3':
		linha=0;
		coluna=2;
		break;
		case '4':
		linha=1;
		coluna=0;
		break;
		case '5':
		linha=1;
		coluna=1;
		break;
		case '6':
		linha=1;
		coluna=2;
		break;
		case '7':
		linha=2;
		coluna=0;
		break;
		case '8':
		linha=2;
		coluna=1;
		break;
		case '9':
		linha=2;
		coluna=2;
		break;
		}
if((tecla=='1')||(tecla=='2')||(tecla=='3')||(tecla=='4')||(tecla=='5')||(tecla=='6')||(tecla=='7')||(tecla=='8')||(tecla=='9')){
	if(nerd->M[linha][coluna]!=' ')cout << "Casa ocupada, jogada inválida.";
	if(nerd->M[linha][coluna]==' '){
	certo=true;
	nerd->M[linha][coluna]=p->simbolo;}
	}
else{cout << "Tecla invalida.";}
}
while(certo==false);
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
	if (X->simbolo=='\0'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo==' '){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo=='O'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo=='o'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
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
	if (O->simbolo=='\0'){O->simbolo='O'; cout <<"Símbolo padrão inserido\n";}
	if (O->simbolo==' '){O->simbolo='O'; cout <<"Símbolo padrão inserido\n";}
	if (O->simbolo=='X'){O->simbolo='O'; cout <<"Símbolo padrão inserido\n";}
	if (O->simbolo=='x'){O->simbolo='O'; cout <<"Símbolo padrão inserido\n";}
	if (O->simbolo==X->simbolo){O->simbolo = 'O'; cout <<"Símbolo padrão inserido\n";}
	}
	cout << endl;
	cout << "Jogador 1 sera: " << X->name << ", jogando com o simbolo '" << X->simbolo << "'.\n";
	cout << "Jogador 2 sera: " << O->name << ", jogando com o simbolo '" << O->simbolo << "'.\n" << endl;
}
void imprimir(game *nerd){
	if(nerd->VELHA==true){cout << "DEU VELHA...";}
	cout << ".Rodadas no total: " << nerd->roda << endl;
	cout << ".Rodada nesta partida: " << nerd->turno << endl;
	cout << "._______________________________.\n";
	if(nerd->roda%2==1){cout << "| N E R D I X    |   (Opções:)  | "<< endl;
	cout << "| e  "<< nerd->M[0][0] << " | "<< nerd->M[0][1] << " | "<< nerd->M[0][2] << "   |   (";
	if(nerd->M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| r  --|---|--   |   (       )  |"<< endl;
	cout << "| d  "<< nerd->M[1][0] << " | "<< nerd->M[1][1] << " | "<< nerd->M[1][2] << "   |   (";
	if(nerd->M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| i  --|---|--   |   (       )  |"<< endl;
	cout << "| x  "<< nerd->M[2][0] << " | "<< nerd->M[2][1] << " | "<< nerd->M[2][2] << "   |   (";
	if(nerd->M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|________________|______________|\n";}
	else{cout << "| N e r d i x    |   (Opções:)  | "<< endl;
	cout << "| E  "<< nerd->M[0][0] << " | "<< nerd->M[0][1] << " | "<< nerd->M[0][2] << "   |   (";
	if(nerd->M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| R  --|---|--   |   (       )  |"<< endl;
	cout << "| D  "<< nerd->M[1][0] << " | "<< nerd->M[1][1] << " | "<< nerd->M[1][2] << "   |   (";
	if(nerd->M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| I  --|---|--   |   (       )  |"<< endl;
	cout << "| X  "<< nerd->M[2][0] << " | "<< nerd->M[2][1] << " | "<< nerd->M[2][2] << "   |   (";
	if(nerd->M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(nerd->M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|________________|______________|\n";}
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
cout << "	|NERDIX 0.5.2     02|\n";
cout << "	|E      |   |  abril|\n";
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
