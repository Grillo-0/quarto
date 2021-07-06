#include <stdio.h>

#include "jogo.h"
#include "printar.h"

extern jogo *quarto;

void printarResultado(){
    printarTabuleiro();
    if(quarto->jogadas >= 16 && quarto->res.flag){
        printf("0\n"); //empate
        return;
    }else{
        printarVencedor();
		printf("\n");
        printarSequencia();
		printf("\n");
        printarCarac();
    }
}

void printarSequencia(){
    for (int i = 0; i < 4; i++)
    {
        int linha = quarto->res.sequencia[i][0] * 4;
        int coluna = quarto->res.sequencia[i][1];

        int pos = linha + coluna;

        printf("%X", pos);
    }
}

void printarVencedor(){
	if (quarto->jogadas % 2){
	  printf("2");
	}
	else{
	  printf("1");
	}
}

void printarTabuleiro(){

for (int i = 0; i < 4; i++){
  for (int j = 0; j < 4; j++){  
    if (quarto->tabuleiro[i][j] == -1){
      printf("-");
    }
    else{
      printf("%X", quarto->tabuleiro[i][j]);
    }
  }
  printf("\n");
}
}

void printarCarac(){
	int mask = 0b0001;
	for(int i=3;i>=0;i--){
		int res = (mask<<i & quarto->res.comum)>>i;
		int tipo = (mask<<i & quarto->res.carac)>>i;
		if(res){
			if(tipo){
				switch(i){
					case 0:
						printf("oca\n");
						return;
					case 1:
						printf("quadrada\n");
						return;
					case 2:
						printf("pequena\n");
						return;
					case 3:
						printf("escura\n");
						return;
				}
			}
			else{
				switch(i){
					case 0:
						printf("solida\n");
						return;
					case 1:
						printf("circular\n");
						return;
					case 2:
						printf("grande\n");
						return;
					case 3:
						printf("branca\n");
						return;
				}
			}
		}
	}
}
