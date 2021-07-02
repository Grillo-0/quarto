#ifndef __JOGO_H__
#define __JOGO_H__

typedef struct{
    int flag;
    int sequencia[4][2];
    int comum;
    int carac;
}resultado;

typedef struct{
    int tabuleiro[4][4];
    int jogadas;
    resultado res;
}jogo;

void InicializarJogo();

void InicializarTabuleiro();

void ColocarPeca();

#endif 