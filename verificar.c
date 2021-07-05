#include <stdio.h>
#include <string.h>

#include "jogo.h"

extern jogo *quarto;

int verificar(int pecas[]){
	int and=-1;
	int or = 0;
	for(int i=0; i<4; i++){
		and &= pecas[i];
		or |= pecas[i];
	}
	int xor = and ^ or;
	int xnor = ~xor;
	if(xnor>>4 && xor ^ 0xf && and != or){
		quarto->res.flag = 0;
		quarto->res.carac = xnor & and;
		quarto->res.comum = xnor;
		return 1;
	}
	return 0;
}

void verificarLinhas(){
	int pecas[4];
	int pos[4][2];
	for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			pecas[j] = quarto->tabuleiro[i][j];
			pos[j][0] = i;
			pos[j][1] = j;
		}
		if(verificar(pecas)){
			memcpy(quarto->res.sequencia,pos,sizeof(pos));
			break;
		}
	}
}

void verificarColunas(){
	int pecas[4];
	int pos[4][2];
	for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			pecas[j] = quarto->tabuleiro[j][i];
			pos[j][0] = j;
			pos[j][1] = i;
		}
		if(verificar(pecas)){
			memcpy(quarto->res.sequencia,pos,sizeof(pos));
			break;
		}
	}
}
void verificarDiagonalP(){
    int pecas[4];
    int pos[4][2];
    for (int i = 0; i < 4; i++){
        pecas[i] = quarto->tabuleiro[i][i];
        pos[i][0] = pos[i][1] = i;
    }
    if(verificar(pecas)){
        memcpy(quarto->res.sequencia,pos,sizeof(pos));
    }
}

void verificarDiagonalS(){
    int pecas[4];
    int pos[4][2];
    for (int i = 0; i < 4; i++){
        pecas[i] = quarto->tabuleiro[i][3-i];
        pos[i][0] = i;
        pos[i][1] = 3-i;
    }
    if(verificar(pecas)){
        memcpy(quarto->res.sequencia,pos,sizeof(pos));
    }
}
