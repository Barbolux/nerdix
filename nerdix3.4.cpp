//MUDANÇAS DA VERSÃO 0.3.1: a escolha de jogador agora coloca dados numa struct.
//MUDANÇAS DA VERSÃO 0.3.2: interface grafica mostra opções ainda disponíves.
//MUDANÇAS DA VERSÃO 0.3.3: apenas algumas correções levando os nomes dos players para imprimir nas jogadas.
//PROBLEMA> no enunciado do TP solicita-se "Não utilize variáveis globais no programa."
//"Faça funções para marcar a posicao  selecionado  pelos jogadores
// e tambem para efetuar todas as operacoes e verificacoes necessarias.
// Pode-se utilizar passagem de parametros por valor ou referência nas funcoes.
// Uai, como que faz isso??? Imagino que é com um monte de ponteiros :'(

/*BCC201 - TP1 - Semestre 2016.2
Trabalho prático JOGO DA VELHA.
UFOP - Universidade Federal de Ouro Preto.
DECOM - Departamento de Computação.
Professor. Puca
*** Programadores ***
	* Stefano Nogueira de Azevedo. n_16.1.5969
	* Hugo Zvanini. n_
	* Renato Tavares Goia. n_16.1.9999
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//structs utilizadas no programa.
struct player{// estrutura que contém os dados de cada jogador.
	string name; //nome do jogador.
	bool human; //quando false o jogador se comporta como robô.
	char simbolo; //permite você substituir o X e O por qualquer char do teclado.
	int round; //registra quantas vezes ele jogou.
	int score; //pontuação total deste jogador.
};

//funções utilizadas no programa.
void tabuleiro(); // Função que monta o tabuleiro vazio para início da partida.
void imprimir(); //
void jogar_humano(); // Jogada do player humano.
void jogar_robo(); // Jogada do player robô.
void verificar_ganhador(); // Verifica o ganhador comparando as 8 condições de vitória.
void jogo_da_velha(); //
void replay(); //
void placar(); //
void teclado(char); //função que recebe o valor do teclado e reverte em duas posições da matriz.
//void escolha_jogador(); // colocado no main, mas queria devolver isso à condição de função quando descobrir como.

//declaração de variáveis globais: //QUE DEVEM SER ELIMINADAS! :'( 
	player X, O;
	char M[3][3], tecla;
	int m_linha, m_coluna, jogada=0, turno=1;
	bool certo=false, fim=false, ganhou=false;

int main(){ // MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN!
	cout << endl;
	cout << "Bem vindo ao NERDIX, o jogo-da-velha mais nerd do mundo!\n";
	cout << endl;
	cout << "Primeiro vamos definir que sao os jogadores...\n";
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
		cout << "Escolha um simbolo para o jogador 1. (Padrao X): ";
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
			//caso os dois sejam computadores serão rebatizados com o sobrenome 1 e 2.
			}
			O.human=false;
			O.simbolo='O';
		}
		else{
			while (O.name==X.name){
			cout << "O nome ja foi tomado pelo jogador 1. Escolha outro nome: ";
			cin >> O.name;}
			//verificação para evitar escolha de nomes repetidos.
			O.human=true;
			cout << "Escolha um simbolo para o jogador 2. (Padrao O): ";
			cin >> O.simbolo;
			if (O.simbolo==' ')O.simbolo='O';
			if (O.simbolo=='X')O.simbolo='O';
			if (O.simbolo=='x')O.simbolo='O';
			if (O.simbolo==X.simbolo)O.simbolo = 'O';
			//verificações para evitar escolha de símbolos iguais.
		}

	cout << endl;
	cout << "Jogador 1 sera: " << X.name << ", jogando com o simbolo '" << X.simbolo << "'.\n";
	cout << "Jogador 2 sera: " << O.name << ", jogando com o simbolo '" << O.simbolo << "'.\n" << endl;
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
	cout << ".______________________________.\n";
	cout << "| N E R D I X   |   (Opcoes:)  | "<< endl;
	cout << "| E "<< M[0][0] << " | "<< M[0][1] << " | "<< M[0][2] << "   |   (";
	if(M[0][0]==' '){cout<<"1";}
	else{cout<<" ";}
	cout << "  ";
	if(M[0][1]==' '){cout<<"2";}
	else{cout<<" ";}
	cout << "  ";
	if(M[0][2]==' '){cout<<"3";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| R --|---|--   |   (       )  |"<< endl;
	cout << "| D "<< M[1][0] << " | "<< M[1][1] << " | "<< M[1][2] << "   |   (";
	if(M[1][0]==' '){cout<<"4";}
	else{cout<<" ";}
	cout << "  ";
	if(M[1][1]==' '){cout<<"5";}
	else{cout<<" ";}
	cout << "  ";
	if(M[1][2]==' '){cout<<"6";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "| I --|---|--   |   (       )  |"<< endl;
	cout << "| X "<< M[2][0] << " | "<< M[2][1] << " | "<< M[2][2] << "   |   (";
	if(M[2][0]==' '){cout<<"7";}
	else{cout<<" ";}
	cout << "  ";
	if(M[2][1]==' '){cout<<"8";}
	else{cout<<" ";}
	cout << "  ";
	if(M[2][2]==' '){cout<<"9";}
	else{cout<<" ";}
	cout << ")  |"<<endl;
	cout << "|_______________|______________|\n";
}

void jogar_humano(){
	
	jogada=0;
	while (ganhou!=true && jogada<9){
		certo = false;
		if (fim==false){
			if (turno==1){
				while (certo == false){
					cout << "Para jogar use as teclas^^^ acima.\n";
					cout << X.round <<"o Turno do " << X.name <<"("<<X.simbolo<<") jogar: ";
					cin >> tecla;
					teclado(tecla);
					if (M[m_linha][m_coluna]==' '){
						M[m_linha][m_coluna]=X.simbolo;
						certo = true;
						X.round++;
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
					cout << "Para jogar use as ^^^ teclas acima.\n";
					cout << O.round <<"o Turno do " << O.name <<"("<<O.simbolo<<") jogar: ";
					cin >> tecla;
					teclado(tecla);
					if (M[m_linha][m_coluna]==' '){
						M[m_linha][m_coluna]=O.simbolo;
						certo = true;
						O.round++;
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
			cout << "Parabens o jogador "<<O.name<<" ganhou! "<< endl;
			O.score++;
		}
		else if (turno==2){
			cout << "Parabens o jogador "<<X.name<<" ganhou! "<< endl;
			X.score++;
		}
	}
	
}
void jogar_robo(){
	//blalaslas
	tecla = (rand()%9);
	teclado(tecla);
	//essa função gera numeros eleatorias, só que eu não sei como usa-la no nosso codigo.
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
	X.round=1;
	O.round=1;
	ganhou=false;
	fim=false;
	certo=false;
	//reinicializar essas booleanas para não dar pau no replay.
	tabuleiro();
	imprimir();
	jogada=0;
	while((jogada<=9)&&(ganhou==false)){
		jogar_humano();
		jogada++;
		replay();
	}
}
void replay(){
	char novo;
		cout << "Deseja jogar novamente? "<< endl;
		cout << "Digite (s) para jogar (n) para sair: ";
		cin >> novo;
		if (novo=='n'||novo=='N'){
		cout << "Obrigado por jogar :-D Veja agora o resultado final do placar. \n\n";
		placar();}
		else if (novo=='s'||novo=='S') jogo_da_velha();
		else {cout << "Quê? Não entendi a tecla. "; replay();}
}
void placar(){
	cout << endl;
	cout << "PONTUACAO:"<< endl;
	cout << "1: O jogador " << X.name << " obteve " << X.score << " vitoria(s). "<< endl;
	cout << "2: O jogador " << O.name << " obteve " << O.score << " vitoria(s). "<< endl;
}
//void escolha_jogador(){} depreciada, por enquanto...