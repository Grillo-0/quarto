#ifndef __VERIFICAR_H__
#define __VERIFICAR_H__

int verificar(jogo *quarto, int pecas[]);
void verificarLinhas(jogo *quarto);
void verificarColunas(jogo *quarto);
void verificarDiagonalP(jogo *quarto);
void verificarDiagonalS(jogo *quarto);

#endif
