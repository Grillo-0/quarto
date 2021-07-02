#include <stdio.h>

#include "jogo.h"
#include "printar.h"

extern jogo *quarto;

void printarResultado(){
    printarTabuleiro();
    
    if(quarto->jogadas >= 16){
        printf("0\n"); //empate
        return;
    }else{
        printarVencedor();
        printarSequencia();
        printarCarac();
    }
}

void printarSequencia(){
    for (int i = 0; i < 4; i++)
    {
        int linha = quarto->res.sequencia[i][0];
        int coluna = quarto->res.sequencia[i][1];

        int peca = quarto->tabuleiro[linha][coluna];

        printf("%X", peca);
    }  
}