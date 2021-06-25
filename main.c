#include <stdio.h>

void inicializarTabuleiro(int tabuleiro[]);
int *verificar(int *tabuleiro);

int main(int argc, char *argv[]){
	int tabuleiro[16];
	inicializarTabuleiro(tabuleiro);
	int jogadas = 0;
	do{
		int peca;
		int posicao;
		scanf("%X %X",&peca, &posicao);
		tabuleiro[posicao] = peca;

		int *sequencia = verificar(tabuleiro);
		int ganhou = 0;
		if(*sequencia > 0){
			ganhou = 1;
		}
		jogadas++;
	}
	while(!ganhou && jogadas < 16);

	if(ganhou){
		printarTabuleiro(tabuleiro);
		printf("%d",!(jogadas % 2) + 1);
		printarSequencia(sequencia);
	}
}
//teste
//ehescura ehbaixa ehquadrada  ehoca
//   0        0        0         0

void inicializarPinos(int pinos[]){
	for(int i=0; i<16; i++){
		pinos[i]=i;
	}
}

void inicializarTabuleiro(int tabuleiro[]){
	for(int i=0; i<16; i++){
		tabuleiro[i]=-1;
	}
}
