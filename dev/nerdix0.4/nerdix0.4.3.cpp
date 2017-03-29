//notas da versão 0.4.3:
//NOVA FUNCAO: JOGAR()
//NOVA FUNCAO: ROBO()
//(funções jogar_robo e jogar_humano foram removidas!)
//Alternância de jogadores funciona :-D
//verificação da VELHA acontecerá dentro da verificação "ganhador" (não implementada)
//Robo continua sendo muito idiota!

#include <iostream>
#include <cstdlib>
#include <ctime>//usado para randomização.
#include <locale.h>//localização PT_BR.
using namespace std;
struct player{// contém os dados de cada jogador.
//Serão inicializados em main() os players X e O.
	string name; //nome do jogador.
	bool human; //quando false o jogador se comporta como robô.
	char simbolo; //simbolo que será utilizado como marcador no jogo.
	int round, draw, score;
	//round registra quantos turnos ele jogou.
	//score é a pontuação total deste jogador.
	//draw é os empates do jogador.
	//(diferença entre empate e velha: empate é ponto que os jogadores ganham,
	//e velha é ponto que a velha ganha.)
};
struct game{//quase todas variáveis do jogo estão aqui.
//Será inicializada em main() o game "nerd" (apenas uma que será usado sempre).
	char M[3][3];
	int linha, coluna, velha, roda, turno, partida;
	bool vitoria, VELHA;
	//velha com letra minuscula recebe a pontuação da velha.
	//VELHA com letra maiúscula é o verificador de jogo já deu velha.
};
	//funções que não recebem nenhum parâmetro:
	void intro();// animação de abertura.
	void apagar();// imprime um monte de couts de espaços vazios para apagar a tela.
	
	//funções que recebem dois players como parâmetro:
	void definir_jogadores(player*, player*); //usuário insere os dados dos jogadores por cin.
	
	//funções que recebem por referência apenas game:
	void verificar_ganhador(game*); //verifica o ganhador comparando as 8 condições de vitória.
	void imprimir(game*); //faz verificações de casas marcadas e lança os couts na tela.
	void teclado(char, game*); //recebe o valor do teclado e reverte em duas posições da matriz.	
	//função teclado pode ser otimizada!!!
	
	//funções que recebem game e apenas um player:
	void JOGAR(player*, game*);//nova função jogar.
	void ROBO(player*, game*);//nova função robo.
	//void jogar_humano(player*, game*); //.............depreciada
	//void jogar_robo(player*, game*); //...............depreciada
	
	//funções que recebem os dois players e game (tudo):
	void jogo_da_velha(player*, player*, game*); //contém a ordem das funções para acontecer o jogo.
	void placar(player*, player*, game*); //mostra os resultados gerais.
	void replay(player *, player *, game*); //permite começar a partida novamente.
	
	//funções em fase de teste:
	//void alternar_jogador(); //função que alterna os turnos e seleciona jogadores.
	
int main(){ // MAIN MAIN MAIN MAIN MAIN MAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAIN
	setlocale(LC_ALL, "Portuguese"); //Português funcionando para windows e outras plataformas.
	player X, O; // declaração dos jogadores Xis e Bolinha.
	game nerd; // declaração do game "NERD".
	//atribuir valores inciais às variáveis.
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
	intro();//mostra animação de abertura.
	cout << "\nBem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	definir_jogadores(&X, &O);
	cout << "Vamos brincar um pouquinho?\n";
	jogo_da_velha(&X, &O, &nerd);
	placar(&X, &O, &nerd);
	replay(&X, &O, &nerd);
	cout << "\nVolte sempre. TCHAU! :-)";
	return 0;
}
void jogo_da_velha(player *X, player *O, game *nerd){
	X->round=1; //reinicializa partida.
	O->round=1;
	nerd->turno=1;
	nerd->vitoria=false;
	nerd->VELHA=false;
	for (int i=0; i<3; i++){ //atribui o char "espaço em branco" a cada elemento da matriz.
		for (int j=0; j<3; j++){nerd->M[i][j]= ' ';}}//segunda iteração.
	//EASTER EGG DOIS ROBOS.
	if (X->human==false && O->human==false){//easter egg.
	cout << "O computador venceu de si mesmo 100000 vezes em um segundo!\n";
	srand(time(NULL));
	O->score=rand();
	X->score=rand();
	placar(X, O, nerd);
	replay(X, O, nerd);
	}
	apagar();
	cout << "Que comece a disputa :-D" << endl;
	imprimir(nerd);//primeira impressão, termina reinicialização do jogo.
	while((nerd->turno<=9)&&(nerd->vitoria==false)){
		if(nerd->roda%2==1)JOGAR(X, nerd);
		else JOGAR(O, nerd);
	}
	cout << "FIM DA PARTIDA.\n";
//
//	if(X->human==true && O->human==true){//caso dos dois jogadores humanos.
//		while((nerd->turno<=9)&&(nerd->vitoria==false)){
//			if(nerd->roda%2==1){jogar_humano(X, nerd);}//se a roda é impar, X joga.
//			else{jogar_humano(O, nerd);}//se a roda é par, O joga.
//			if(nerd->vitoria==true){
//				if(nerd->roda%2==1){
//					cout << "Parabéns! "<<O->name<<" ganhou! "<< endl;
//					O->score++;
//				}
//				else{
//					cout << "Parabéns! "<<X->name<<" ganhou! "<< endl;
//					X->score++;
//				}
//			}	
//			if((nerd->vitoria==false)&&(nerd->turno==9)){
//					cout << "Deu VELHA :( " << endl;
//					nerd->velha++;
//					X->draw++;
//					O->draw++;
//			}
//		}
//	}
//	if (X->human!=O->human){//caso humano contra robô.
//		while((nerd->turno<=9)&&(nerd->vitoria==false)){
//		if(nerd->roda%2==1){jogar_robo(X, nerd);}
//		else{jogar_robo(O, nerd);}
//		if (nerd->vitoria==true){
//			if(nerd->roda%2==1){
//				cout << "Parabens! "<<X->name<<" ganhou! "<< endl;
//				X->score++;
//			}
//			else{
//				cout << "Parabens! "<<O->name<<" ganhou! "<< endl;
//				O->score++;
//			}
//		}
//		cout << "FIM DA PARTIDA.\n";
//		}
//}
//if (X->human==false && O->human==false){//easter egg.
//	cout << "O computador venceu de si mesmo 100000 vezes em um segundo!\n";
//	srand(time(NULL));
//	O->score=rand();
//	X->score=rand();
//	}
}
void JOGAR(player *p, game *nerd){
if(nerd->VELHA==true){
cout << "A VELHA ganhou :-P";
}
	if(p->human==true){//{JOGADA DO HUMANO!
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
if(p->human==false){//jogada do ROBO!
	cout << "Computador pensa...";
	cout << "Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
	cout << "Jogador robô em fase de testes";
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
cout << "ROBÔ PENSA.\n";
cout << "Vez de " << r->name <<"("<<r->simbolo<<") jogar. " << r->round <<"o Turno."<<endl;
//PRIMEIRO O ROBO PENSA NA SUA JOGADA PREFERIDA.
while (certo==false){
cout << "Robô pensa sua jogada...\n";
	for (int i=0; i<3; i++){//loop do robô pensando nas casas que já tem 2 marcadas.
		if      ((nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][2]=r->simbolo; certo=true;}//i_linha verificação A.
		else if ((nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(certo==false)){nerd->M[i][0]=r->simbolo; certo=true;}//i_linha verificação B.
		else if ((nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][1]=r->simbolo; certo=true;}//i_linha verificação C.
		else if ((nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[2][i]=r->simbolo; certo=true;}//i_coluna verificação A.
		else if ((nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(certo==false)){nerd->M[0][i]=r->simbolo; certo=true;}//i_coluna verificação B.
		else if ((nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[1][i]=r->simbolo; certo=true;}//i_coluna verificação C.
		}
//Se nenhuma jogada for preferida, ele joga RANDOM.
		while (certo==false){
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
//encerramento do turno.
	r->round++;
	nerd->turno++;
	nerd->roda++;
	apagar();
	imprimir(nerd);
	verificar_ganhador(nerd);
}
/*void jogar_humano(player *p, game *nerd){
	bool certo=false;
	cout << "Para jogar use as teclas^^^ acima.\n";
	cout <<"Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
	while (certo==false){
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
}*/
/*void jogar_robo(player *p, game *nerd){
	srand(time(NULL));
	char tecla;
	bool certo=false;
	while ((certo==false)&&(nerd->turno%2==1)){
			cout << "Para jogar use as teclas^^^ acima.\n";
			cout << "Vez de " << p->name <<"("<<p->simbolo<<") jogar. " << p->round <<"o Turno."<<endl;
			cin >> tecla;
			teclado(tecla, nerd);
			if(nerd->M[nerd->linha][nerd->coluna]==' '){
				nerd->M[nerd->linha][nerd->coluna]=p->simbolo;
				p->round++;
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
				if ((nerd->M[i][0]==nerd->M[i][1])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][2]=p->simbolo; certo=true;}//i_linha verificação A.
				else if ((nerd->M[i][1]==nerd->M[i][2])&&(nerd->M[i][1]!=' ')&&(certo==false)){nerd->M[i][0]=p->simbolo; certo=true;}//i_linha verificação B.
				else if ((nerd->M[i][0]==nerd->M[i][2])&&(nerd->M[i][0]!=' ')&&(certo==false)){nerd->M[i][1]=p->simbolo; certo=true;}//i_linha verificação C.
				else if ((nerd->M[0][i]==nerd->M[1][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[2][i]=p->simbolo; certo=true;}//i_coluna verificação A.
				else if ((nerd->M[1][i]==nerd->M[2][i])&&(nerd->M[1][i]!=' ')&&(certo==false)){nerd->M[0][i]=p->simbolo; certo=true;}//i_coluna verificação B.
				else if ((nerd->M[0][i]==nerd->M[2][i])&&(nerd->M[0][i]!=' ')&&(certo==false)){nerd->M[1][i]=p->simbolo; certo=true;}//i_coluna verificação C.
			}
			while (certo==false){
				tecla = (rand()%9+49);
				cout << "... Ele pensa jogar na" << tecla <<endl;
				teclado((char) tecla, nerd);
				if(nerd->M[nerd->linha][nerd->coluna]==' '){
					nerd->M[nerd->linha][nerd->coluna]=p->simbolo;
					cout << "Robô jogou " << tecla << endl;
					certo=true;
				}
			}
		p->round++;
		nerd->turno++;
		nerd->roda++;
		imprimir(nerd);
		verificar_ganhador(nerd);
	}
	}*/

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
	//VERIFICAÇÃO DA VITORIA!!!
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
	
	//VERIFICAÇÃO DA VELHA!
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
		placar(X, O, nerd);
		replay(X, O, nerd);
		}
		else {cout << "Quê? Não entendi a tecla. "; replay(X, O, nerd);}
}
void intro(){
cout << "***Software desenvolvido por: barbolux && reymc && hugozvanini\n";
cout << "***Versão 0.4.3 - 29/03/2017 \n";
cout << "	.___________________.\n";
cout << "	|N E R D I X        |\n";
cout << "	|E                  |\n";
cout << "	|R      |   |2017   |\n";
cout << "	|D      |   |       |\n";
cout << "	|I -----|---|-----  |\n";
cout << "	|X      |   |       |\n";
cout << "	|  -----|---|-----  |\n";
cout << "	|       |   |       |\n";
cout << "	|  DECOM|   |UFOP   |\n";
cout << "	|___________________|\n";
}
void apagar(){cout << string( 100, '\n' );}
//NERDIX 0.4.3 beta
//TP1.2016.2, BCC201 - UFOP
/*Universidade Federal de Ouro Preto, 2017.
 *Trabalho Prático JOGO DA VELHA
 **Professor Puca Huachi**
 **DECOM [Departamento de Computação]
	*** Programadores ***               Matrícula:
	* Hugo Zvanini. 					n_16.2.5849
	* Renato Tavares Goia. 				n_16.1.9999
	* Stefano Nogueira de Azevedo. 		n_16.1.5969

DATA: 29/03/2017
* Software versão 0.4.2
* Informações sobre a versão:
* Foram removidas todas as variáveis globais :-D
* Agora o trabalho está recheado de ponteirinhos :)
* Agora tem função APAGAR que apaga a tela.
* incluido locale "portuguese"
* VERIFICAÇÃO DA VELHA PAROU DE FUNCIONAR DEPOIS DE 0.4.1;
* Foi implementada uma alternância de jogadores para diminuir o número de linhas escritas.
* Em breve poderá otimizar ainda mais o código devido a isso.

LICENÇA: Este programa está licenciado como SOFTWARE LIVRE, gratuíto de código aberto.
* Para conhecer o Projeto NERDIX visite o site: http://www.github.com/Nerdix.
* Caso deseje fazer uma contribuição ao programa, fique à vontade.
INDEX - Todas funções do jogo.
* ESCREVER INDEX!
* ESCREVER INDEX!
* Escrever...
O QUE FALTA IMPLEMENTAR/CORRIGIR/Bugs.
**** Robô ainda ta meio idiota. Não verifica diagonais. Tem vezes que ele não joga, coitado.
**** Correção de bugs do cin >> char. (na seleção de simbolo de jogador, se apertar ENTER sem escrever nada temos bug).
**** Este bug do cin já foi encontrado pelo Puca!
*/
