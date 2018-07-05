set I := {1..4}; # conjunto das tarefas a serem seqüenciadas;
param P{i in I}; # tempo de processamento da tarefa i;
param T{i in I}; # data desejada para término da produção da tarefa i (due date);
param E1 {i in I}; # custo de antecipação (estoque) da tarefa i por unidade de tempo;
param E2 {i in I}; # custo do atraso da produção da tarefa i por unidade de tempo;
param S{i in I, j in I}; # tempo de preparação para produzir a tarefa j depois da tarefa i;
var Y {i in I, j in I}; #,={0,1}; #variável que determina a sequência de produção, sendo igual a 1 se a tarefa j é produzido depois da tarefa i e 0, se não;
var t {i in I}; # variável que determina a data de início da produção da tarefa i;
var h1 {i in I}; # variável que determina o tempo de antecipação da tarefa i;
var h2 {i in I}; # variável que determina o tempo de atraso da tarefa i;

# criar matriz?
# param matriz{i in I, i in I};

minimize custo: sum {i in I} E1[i] * h1[i] + sum {i in I} E2[i] * h2[i];

s.t.

tempos{i in I, j in I}: t[j]-t[i] - ( 99999 + S[i,j]) >=  P[i] - 99999;
fila {i in I, j in I}: Y[i, j] + Y[j, i] = 1;
antecipacao_atraso {i in I}: t[i] + P[i] - h2[i] + h1[i] = T[i];

#ou
#tempos{i in I, j in I}: t[j]-t[i] - ( 99999 + S[i,j]) >=  P[i] - 99999;
#como indicar somatoria aqui? e usar a matriz?

# como indicar se Y={0,1} é binário ?

solve;

data;

param P:=
1 24
2 30
3 30
4 16;

param T:=
1 0
2 24
3 48
4 87;

param E1:=
1 10
2 20
3 10
4 30;

param E2:=
1 100
2 200
3 100
4 300;

param S :
1 2 3 4:=
1 0 4 0 6 
2 4 0 4 5
3 0 4 0 6
4 6 5 6 0;

end;

# Renato, Stefano e Bruno.
