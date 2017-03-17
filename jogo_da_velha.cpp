//ESTADO DA PRODUÇÃO deste software é antes do Alfa. o codigo não compila.
/*BCC201-TP1. //cabeçalho
Trabalho prático JOGO DA VELHA.
UFOP - Universidade Federal de Ouro Preto
DECOM - Ciência da Computação. Março/2017
Professor. Puca
** Programadores **
 * Stefano Nogueira de Azevedo. n_16.1.5969
 * Hugo Zvanini.
 * Renato Tavares Goya.
 */
/*INDICE.
 - Anotações, instruções, convenções e padrões para compreender melhor o codigo deste jogo.
***HELP****
* Jogador Zero é bola e jogador Um é xis!
nomes de variaveis globais da função:
* 0 - variavel do tipo player que representa o jogador 1.
* 1 - variavel do tipo player que representa o jogador 2.
* roda - variavel local dentro do loop for, de valor 0 a 8 que registra qual é rodada.
* Convenções do jogo. vetores de posição vão representar:
* (quando armazenado em vetores lineares. sera que era melhor um vetor 2x2?
* 0 = Norte, a direção ao alto da tela. CIMA.
* 1 = Leste, a direção de cima.
* 2 = Sul, a direção abaixo na sua tela. BAIXO.
* 3 = Oeste, a direção da esquerda.
 */
#include <iostream>
#include <string>
using namespace std;

//ESTRUTURAS DO JOGO.

struct player{//o jogador. durante a função main do programa será declarados os jogadores 0 e 1.
	bool human=true; //inicializa com humano verdadeiro; quando é false o player se comporta como robô.
	char simbolo; //permite você substituir o X e O por qualquer char do teclado.
	string name; //nome do jogador.
	int jogada=0; //registra quantas vezes ele jogou.
	int pontos; //pontuação final
	GOL pontos_pessoais; //quantidade de GOL que a pessoa fez no jogo.
	
}
struct casa{//o espaço quadrado onde será marcado seu simbolo.
	bool ativado=false; //indica se a casa está vazia ou ocupada.
	vizinho entorno[2][2][2]; //matriz 3d o tipo de struct vizinho mostrando as 8 posições entorno.
	int id; //identificação numerica linear 1 a 9.
	int ad[3][3]; //identificação por matriz (localização na avenida)
}
struct vizinho{//mostra os vizinhos ocupados ou vazios em relação a uma casa marcada.
	casa lado[4]//os quatro lados. 0norte, 1leste, 2sul, 3oeste.
	casa canto[4]//os quatro cantos. 0norte, 1leste, 2sul, 3oeste. (referencia: da esquerda para direita).
	bool lado[4]=false; //se torna true quando o vizinho é colocado.
	bool canto[4]=false; //vetor de quatro posições
	char parede; //char aloca 4 bits assim podemos representar se é encostado numa 4 paredes.
}
struct linha{//contem informações sobre a casa e sobre a linha.
	bool vazia=true;
	bool cheia=false;
	int disponiveis=3;
	int ocupadas=0;
	GOL linha_ganha;
	casa L[3]
}
struct tabuleiro{//Lê as informações do tabuleiro para dar dicas ao jogador.
	linha vert;
	linha hori;
	linha diag;
}
struct GOL{//estrutura de pontuação do jogo da velha que vai de zero a dois.
	bool zero=true;
	bool um=false;
	bool dois=false;
	bool velha=false; //em caso de linha preenchida 2a1(empate, velha)
	int total=0; //total de pontos que se chegar a dois significa vitoria.
};
//cabeçalhos das funções:
void iniciar(); //incompleto. Função que apaga tudo que estiver no lixo e cria o novo jogo.
int turno(); //incompleto. Monta o vetor TABULEIRO com base nas informações anteriores.
int jogar(); //incompleto. Jogada do Jogador.
int toctoc(); //incompleto. função que atualiza informação de todos os vizinhos. 
int pontuar(); //incompleto. Computa os pontos das structs GOL.
int qt();//função que envia para a interface grafica.
void imprimir(); //incompleto.
void select_player(); //incompleto
bool vitoria(); //incompleto
bool XO(int); //incompleto. função que alterna entre os dois jogadores.
void fim(); //função chamada quando o jogo termina.
int main{ //MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
	player 0, 1;
	cout << "Bem Vindo ao Jogo da Velha Nerdix" << endl;
	//Selecionar jogador e modo dejogo
	select_player();
	//Jogo começa nas linhas a seguir... Quem será o vencedor da disputa??
	for (int roda=0, roda<9, roda++){ //a variavel local roda significa cada rodada.		
		XO(roda);
		turno(roda);
		jogada(roda);
		pontuar(roda);
		imprimir(roda);
		if (vitoria==true){break; fim();}//se a função vitoria se tornar true, da um break no loop e chama função "fim".
		}

return 0;
}
//FUNCOES DO JOGO
int turno(){//Descreve os turnos.
		//primeira parte do turno. Avaliar se o jogador é humano ou robô para decidir o comportamento da jogada.

	if(flag.player.human==true){//jogadas do jogador humano.

	switch(roda)
	case 0{}//primeira jogada. cria um vetor com 9 posições.
	//Tabuleiro em branco com 9 espaços livres.
	//Pode ser marcadas as posições: pares, impares ou centro.
	break;
	case 1{}
	//Tabuleiro com 8 espaços livres.
	break;
	case 2{}
	//Tabuleiro com 7 espaços livres.
	break;
	case 3{}
	//Tabuleiro com 6 espaços livres.
	break;
	case 4{}
	//Tabuleiro com 5 espaços livres.
	break;
	case 5{}
	//Tabuleiro com 4 espaços livres.
	break;
	case 6{}
	//Tabuleiro com 3 espaços livres.
	break;
	case 7{}
	//Tabuleiro com 2 espaços livres.
	break;
	case 8{}
	//Tabuleiro com 1 espaço livre.
	break;
	

	if(flag.player.human==false){//Jogadas do computador."Inteligência Artificial"
	switch
	case 0{}
	break;
	case 1{}
	break;
	case 2{}
	break;
	case 3{}
	break;
	case 4{}
	break;
	case 5{}
	break;
	case 6{}
	break;
	case 7{}
	break;
	case 8{}
	break;
	};
}

vitoria()//ao fim do turno ele analiza a condição de jogada.

}
 //incompleto
 
 
int jogar(){//incompleto
	cout << "Digite qual número quer jogar. ";
	cin >> 
}; 
	
int pontuar(); //incompleto
void imprimir(); //incompleto
void select_player{ //escrita mas, não testada. função para selecionar jogadores.
	for (int i=0; i<2; i++){
	cout << "Entrar dados do JOGADOR " << i+1;
	cout << "Digite nome ou apenas pressione ENTER para que seja controlado pelo computador." << endl;
	cin >> i.player.name;
	if (i.player.name==NULL){i.player.human==false}; /*neste momento o NULL é nossa tentativa para saber se
	o usuario apenas apertou enter sem digitar nada*/
	cout << "Digite a tecla que este jogador usará para marcar o tabuleiro: "
	cin >> i.player.simbolo;
	cout << endl << "DADOS do jogador " << i+1 << " REGISTRADOS." << endl;
	}
	};
bool vitoria(){
	if (GOL.dois==true)
	return true};
bool XO(int roda){ //nao testada.
	if(roda % 2 == 0) //rodada par pertence ao jogador X (xis)
	return true;
	if(roda % 2 == 1) //rodada impar pertence ao jogador O (bola)
	return false;
}

//COMENTARIOS FINAIS E EXPLICACOES DO JOGO.
/* Estudando as condições de vitoria...
 * 
 * Existem 8 resultados que significam vitoria.
 * 1+2+3,
 * 4+5+6,
 * 7+8+9.
 * 1+5+9,
 * 3+5+7;
	...


/* Grade do Jogo da Velha
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * PRIMEIRA JOGADA: JOGADOR I
 * Três casos possíveis.
 * Jogar 5.
 * Jogar pares.
 * Jogar impares.
 * 
 * if (cin = 5)
 * Duas jogadas possíveis:
 * Jogada Impar (1, 3, 7, 9)
 * Jogada Par (2, 4, 6, 8) 
 *
 * if (cin = numero impar do tabuleiro)
 * Cinco jogadas possíveis.
 * (exemplo. Jogou na casa 1)
 * (2 = 4);
 * (3 = 7);
 * (6 = 8);
 *  5;
 *  9.
 * 
 * if (cin = numero PAR do tabuleiro)
 * Cinco jogadas possíveis.
 * (exemplo. Jogou na casa 2)
 * (1 = 3);
 * (4 = 6);
 * (7 = 9);
 * 5;
 * 8;
 * /
* matriz(xadrez[3][3])
* i0j0, i0j1, i0j2
* i1j0, i1j1, i1j2
* i2j0, i2j1, i2j2
