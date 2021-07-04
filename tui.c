#include <stdio.h>
#include <ncurses.h>

#include "tui.h"
#include "jogo.h"

extern jogo *quarto;

void InitializeScreen(){
    initscr(); 
}

void UpdateScreen(){
    clear();

    for (int linha = 0; linha < 4; linha++)
    {
        printw("|");

        for (int coluna = 0; coluna < 4; coluna++)
        {
            int number = quarto->tabuleiro[linha][coluna];

            if(number == -1) printw(" - |", quarto->tabuleiro[linha][coluna]);
            else printw(" %X |", quarto->tabuleiro[linha][coluna]);
            
        }
        
        printw("\n");
    }

    refresh();
}

void ClearScreen(){
    getch();
    endwin();
}