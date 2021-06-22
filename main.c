#include <stdio.h>

void inicializarPinos(int pinos[]);
void inicializarTabuleiro(int tabuleiro[]);

int main(int argc, char *argv[]){
int pinos[16];
int tabuleiro[16];

inicializarPinos(pinos);
inicializarTabuleiro(tabuleiro);
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
