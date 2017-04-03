#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

//struct
struct tipoRankingStr{//dar entrada pelo arquivo
	char nome[50];
	int vitorias; 
	int empates;
	int derrotas;
};
	tipoRankingStr nomeRank[5];
	tipoRankingStr *nomeRankPtr;//ponteiro para criar o vetor de struct
	nomeRankPtr = nomeRank;

//prototipando funcoes
void imprimeRanking ();
void salvarEmArquivo();
void ordenaStr (tipoRankingStr *N, int);

int main(){
	for(int i=0; i<5; i++){ // aqui váo entrar os dados dos jogadores!!!!!!
		cout<<"Digite o nome do jogador "<<i+1<<endl;
		fgets((nomeRankPtr+i)->nome, 50, stdin);//ptr de vetor de struct, ele pega a posicao da primeira;
		cout<<"Digite o numero de vitorias:"<<endl;
		cin>>(nomeRank+i)->vitorias;
		cout<<"Digite o numero de derrotas:"<<endl;
		cin>>(nomeRank+i)->derrotas;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');//DEVE VIR NO FIM DO LOOP!!
	}
int n=5;
std::ofstream aberto("caixaNerd.txt");//abre p escrever arq. TXT
aberto.open("caixaNerd.txt");

aberto<<"\n\n\n\n\nTOPO dos 5\n\n"<<endl;
for(int i=n-1, j=1; i>=0; i--, j++){//imprime do maior por menor
aberto<<"[Jogador "<<j<<"]"<<endl;
aberto<<"Nome = "<<(nomeRankPtr+i)->nome<<endl;
aberto<<"Vitorias = "<<(nomeRankPtr+i)->vitorias<<endl;
aberto<<"Derrotas = "<<(nomeRankPtr+i)->derrotas<<endl;
aberto<<endl;
}


ordenaStr(nomeRankPtr, n);//funcao que ordena os jogadores pelas vitorias do menor pro maior
imprimeRanking();


aberto.close();

return 0;
}

void ordenaStr(tipoRankingStr *N, int n){ //met. de selecao
	tipoRankingStr aux;
int menor=0;

	for(int i=0; i<n-1; i++){
		menor=i;//no inicio
		for(int j=i+1; j<n; j++){
			if(N[menor].vitorias>N[j].vitorias){
				menor=j;
			}
		}
		if(i!=menor){
		aux=N[i];
		N[i]=N[menor];
		N[menor]=aux;
		}
	}
}


void imprimeRanking (){//vai ter que abrir um TXT salvo no formato
std::ifstream saidaDados("caixaNerd.txt");//abre o mesmo arquivo para ser saida de dados
char c;
	while(saidaDados.get(c)){ //le caracter por caracter
		cout<<c;
	}
saidaDados.close();
}










