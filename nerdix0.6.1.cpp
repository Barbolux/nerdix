//versao 0.6.1
//novidades do NERDIX0.6...
//funções em inglês tiveram nome traduzido para português :-D
//foi colocada opção de ver os recordes no inicio, ou pular direto para o inicio do jogo.
//havia uma redundância nas funções JOGAR e ROBO que fui suprimida, reduzindo o codigo da parte robô;
//(a pontuação ++, turno ++, etc. estao somente na função jogar, agora.)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;

struct jogador{
	string nome;
	bool humano;
	char simbolo;
	int vez, pontos;
	//colocar string "lema" com fgets para o vencedor gravar uma frase com seu grito de vitoria.
	//colocar int "empates" para registrar quantidade de empates.
};
struct jogo{
	char M[3][3];
	int velha, roda, turno;
	//colocar int "partidas" registrando quantas partidas houve no total.
};
void intro();
void apagar();
void imprimir(jogo*);
void definir_jogadores(jogador*, jogador*);
void bis(jogador *, jogador *, jogo*);
void jogo_da_velha(jogador*, jogador*, jogo*);
void JOGAR(jogador*, jogo*);
void ROBO(jogador*, jogo*);
void teclado(jogador*, jogo*);
void placar(jogador*, jogador*, jogo*);
bool vitoria(jogo*);
	
void mostrar_livro();
void gravar_livro(jogador, jogador, jogo);
	
int main(){
	jogador X, O;
	jogo nerd;
	X.vez=1;
	O.vez=1;
	X.pontos=0;
	O.pontos=0;
	nerd.velha=0;
	nerd.roda=1;
	nerd.turno=1;
	cout << "Bem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	intro();
	cout << "\nDigite R para ver os recordes ou qualquer tecla para continuar";
	char de;
	cin >> de; 
	if(de=='R'||de=='r') mostrar_livro();
	definir_jogadores(&X, &O);
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha(&X, &O, &nerd);
	bis(&X, &O, &nerd);
	gravar_livro(X, O, nerd);
	cout << "\nTCHAU!\n :-)\n";
	cout << "***Software desenvolvido por: barbolux && hugotones && reymc\n";
	cout << "***Versão 0.6.1 beta \n";
	cout << "***Atualizado: 08/04/2017 \n";
	cout << "\nVolte sempre para incrementar seus RECORDES! :-)";
	return 0;
}
void jogo_da_velha(jogador *X, jogador *O, jogo *nerd){
	apagar();
	X->vez=1;
	O->vez=1;
	nerd->turno=1;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){nerd->M[i][j]=' ';}}
	if (!X->humano && !O->humano){
	cout << "O computador venceu de si mesmo 100000 vezes em um segundo!\n";
	srand(time(NULL));
	O->pontos=rand();
	X->pontos=rand();
	nerd->velha=rand();
	placar(X, O, nerd);
	bis(X, O, nerd);
	}
	cout << "Que comece a disputa!" << endl;
	imprimir(nerd);
	while((nerd->turno<=9)&&(!vitoria(nerd))){
		if(nerd->roda%2==1)JOGAR(X, nerd);
		else JOGAR(O, nerd);
	}
	cout << "FIM DA PARTIDA.\n";
	placar(X,O,nerd);
}
void JOGAR(jogador *p, jogo *nerd){
cout << "Para jogar usa as teclas^^^ acima.\n";
cout << p->vez << "a vez de " << p->nome <<"("<<p->simbolo<<") jogar. "<<endl;
if(p->humano)teclado(p, nerd);
else{ROBO(p, nerd);}
p->vez++;
nerd->turno++;
nerd->roda++;
apagar();
if(vitoria(nerd)){
cout << "Parabéns! "<<p->nome<<" ganhou! "<< endl;
p->pontos++;}
imprimir(nerd);
if ((!vitoria(nerd)) && (nerd->turno > 9)){
cout << "A VELHA ganhou :-P\n";
nerd->velha++;
}
}
void ROBO(jogador *p, jogo *nerd){
cout << "Robô pensa...\n";
bool certo=false;
if (p->vez==1){teclado(p, nerd);}
if (p->vez==2){
	for (int i=0; i<3; i++){
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][2]==' ')){nerd->M[i][2]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(nerd->M[i][0]==' ')){nerd->M[i][0]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(nerd->M[i][1]==' ')){nerd->M[i][1]=p->simbolo; certo=true; i=3;}
	
	if((certo==false)&&(nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[2][i]==' ')){nerd->M[2][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(nerd->M[0][i]==' ')){nerd->M[0][i]=p->simbolo; certo=true; i=3;}
	if((certo==false)&&(nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(nerd->M[1][i]==' ')){nerd->M[1][i]=p->simbolo; certo=true; i=3;}
	}
	
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][0])&&(nerd->M[0][0]!=' ')&&(nerd->M[2][2]==' ')){nerd->M[2][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[0][0]==' ')){nerd->M[0][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[2][0])&&(nerd->M[2][0]!=' ')&&(nerd->M[0][2]==' ')){nerd->M[0][2]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[1][1]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[2][0]==' ')){nerd->M[2][0]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[0][0]==nerd->M[2][2])&&(nerd->M[2][2]!=' ')&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	if((certo==false)&&(nerd->M[2][0]==nerd->M[0][2])&&(nerd->M[0][2]!=' ')&&(nerd->M[1][1]==' ')){nerd->M[1][1]=p->simbolo; certo=true;}
	if(!certo)teclado(p, nerd);
}
if ((p->vez==3)||(p->vez==4)){
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
	if(!certo)teclado(p, nerd);
}

if(p->vez==5){
	for (int i=0; i<3; i++){for (int j=0; j<3; j++){ //loop duplicado para percorrer a matriz.
	if(nerd->M[i][j]==' '){nerd->M[i][j]=p->simbolo;}}}
}
}
void teclado(jogador *p, jogo *nerd){
bool certo;
char tecla;
int linha, coluna;
srand(time(NULL));
do{
if (p->humano)cin >> tecla;//jogada do humano
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
else{cout << "Tecla inválida.";}
}
while(!certo);
}
void definir_jogadores(jogador *X, jogador *O){
apagar();
cout << "Primeiro vamos definir que sao os jogadores...\n";
cout << endl;
cout << "Digite o nome do jogador 1\n(Escreva ROBO quiser que o computador controle este jogador): ";
cin >> X->nome;
if((X->nome=="ROBO")||(X->nome=="robo")){
	X->nome="COMPUTADOR";
	X->humano=false;
	X->simbolo='X';
	}
else{
	X->humano=true;
	cout << "Escolha um simbolo para o jogador 1. (Padrao X): ";
	X->simbolo='X';
	cin >> X->simbolo;
	if (X->simbolo=='\0'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo==' '){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo=='O'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	if (X->simbolo=='o'){X->simbolo='X'; cout <<"Símbolo padrão inserido\n";}
	}
cout << "Digite o nome do jogador 2.\n(Escreva ROBO quiser que o computador controle este jogador): ";
cin >> O->nome;
if ((O->nome=="ROBO")||(O->nome=="robo")){
	if(X->humano){
		O->nome="COMPUTADOR";
		}
	else{
		X->nome="COMPUTADOR1";
		O->nome="COMPUTADOR2";
	}
	O->humano=false;
	O->simbolo='O';
	}
else{
	while(O->nome==X->nome){
		cout << "O nome ja foi tomado pelo jogador 1. Escolha outro nome: ";
		cin >> O->nome;
	}
	O->humano=true;
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
	cout << "Jogador 1 sera: " << X->nome << ", jogando com o simbolo '" << X->simbolo << "'.\n";
	cout << "Jogador 2 sera: " << O->nome << ", jogando com o simbolo '" << O->simbolo << "'.\n" << endl;
}
void imprimir(jogo *nerd){
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
bool vitoria(jogo *nerd){
	bool vitoria=false;
	if ((nerd->M[0][0]==nerd->M[0][1])&& (nerd->M[0][1]==nerd->M[0][2]) && (nerd->M[0][0]!=' ')){
		vitoria=true;}
	if ((nerd->M[1][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[1][2]) && (nerd->M[1][0]!=' ')){
		vitoria=true;}
	if ((nerd->M[2][0]==nerd->M[2][1])&& (nerd->M[2][1]==nerd->M[2][2]) && (nerd->M[2][0]!=' ')){
		vitoria=true;}
	
	if ((nerd->M[0][0]==nerd->M[1][0])&& (nerd->M[1][0]==nerd->M[2][0]) && (nerd->M[0][0]!=' ')){
		vitoria=true;}
	if ((nerd->M[0][1]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][1]) && (nerd->M[0][1]!=' ')){
		vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][2])&& (nerd->M[1][2]==nerd->M[2][2]) && (nerd->M[0][2]!=' ')){
		vitoria=true;}
	
	if ((nerd->M[0][0]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][2]) && (nerd->M[0][0]!=' ')){
		vitoria=true;}
	if ((nerd->M[0][2]==nerd->M[1][1])&& (nerd->M[1][1]==nerd->M[2][0]) && (nerd->M[0][2]!=' ')){
		vitoria=true;}
return vitoria;
}
void placar(jogador *X, jogador *O, jogo *nerd){
	cout << endl;
	cout << "PONTUAÇÃO:"<< endl;
	cout << "1: O jogador " << X->nome << " teve " << X->pontos << " vitória(s). "<< endl;
	cout << "2: O jogador " << O->nome << " teve " << O->pontos << " vitória(s). "<< endl;
	cout << "3: A VELHA teve " << nerd->velha << " empate(s)."<< endl;
}
void bis(jogador *X, jogador *O, jogo *nerd){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N'){
			apagar();
			cout << "\n\nObrigado por jogar :-D\n";}
		else if (novo=='s'||novo=='S'){
		apagar();
		cout << "NOVA PARTIDA.\n";
		jogo_da_velha(X, O, nerd);
		bis(X, O, nerd);
		}
		else {cout << "Quê? Não entendi a tecla. "; bis(X, O, nerd);}
}
void intro(){
cout << "	.___________________.\n";
cout << "	|NERDIX |0.6|       |\n";
cout << "	|E      |   |     08|\n";
cout << "	|R      |   |  abril|\n";
cout << "	|D      |   |   2017|\n";
cout << "	|I------|---|-------|\n";
cout << "	|X      |   |  DECOM|\n";
cout << "	|-------|---|-------|\n";
cout << "	| Prof. |   |   UFOP|\n";
cout << "	| Puca  |   |  Ouro |\n";
cout << "	| Huachi|   | Preto |\n";
cout << "	|_______|___|_______|\n";
}
void apagar(){cout << string( 100, '\n' );}

void mostrar_livro(){
cout << "Livro dos Recordes" << endl;
ifstream livro;
livro.open("velha.txt");
if(livro.fail()){
cout<< "Ainda não há recordes!" <<endl;
}
char c;
while(livro.get(c)){
cout << c;
}
livro.close();
char de;
do{
cout << "\nPressione J para começar o jogo.";
cin >> de;
}
while ((de!='J')&&(de!='j'));
}
void gravar_livro(jogador X, jogador O, jogo nerd){
	ofstream registro;
	registro.open("velha.txt", ios::app);
	registro << X.pontos << " " << X.nome << endl;
	registro << O.pontos << " " << O.nome << endl;
	registro.close();
}
