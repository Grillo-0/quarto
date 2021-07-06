#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"
#include "verificar.h"
#include "printar.h"

int main(int argc, char *argv[]){
	jogo *quarto;
	quarto = InicializarJogo();

	while (quarto->res.flag && quarto->jogadas < 16)
	{
		ColocarPeca(quarto);

		verificarDiagonalS(quarto);
		verificarDiagonalP(quarto);
		verificarColunas(quarto);
		verificarLinhas(quarto);
	}
	printarResultado(quarto);
	free(quarto);
}

void InicializarTabuleiro(jogo *quarto){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			quarto->tabuleiro[i][j] = -1;
		}
	}
}

jogo *InicializarJogo(){
	jogo *game = malloc(sizeof(jogo) * 1);
	InicializarTabuleiro(game);
	game->jogadas = 0;
	game->res.flag = 1;
	return game;
}

void ColocarPeca(jogo *quarto){
	int peca, pos;
	scanf("%X\n%X",&peca, &pos);

	int linha = pos/4;
	int coluna = pos%4;

	quarto->tabuleiro[linha][coluna] = peca;
	quarto->jogadas++;
}
