#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"
#include "verificar.h"
#include "printar.h"

jogo *quarto;

int main(int argc, char *argv[]){
	InicializarJogo();

	while (quarto->res.flag && quarto->jogadas < 16)
	{
		ColocarPeca();

		verificarDiagonalS();
		verificarDiagonalP();
		verificarColunas();
		verificarLinhas();
	}
	printarResultado();
	free(quarto);
}

void InicializarTabuleiro(){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			quarto->tabuleiro[i][j] = -1;
		}
	}
}

void InicializarJogo(){
	quarto = malloc(sizeof(jogo) * 1);
	InicializarTabuleiro();
	quarto->jogadas = 0;
	quarto->res.flag = 1;
}

void ColocarPeca(){
	int peca, pos;
	scanf("%X\n%X",&peca, &pos);

	int linha = pos/4;
	int coluna = pos%4;

	quarto->tabuleiro[linha][coluna] = peca;
	quarto->jogadas++;
}
