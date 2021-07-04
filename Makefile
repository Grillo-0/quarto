run: program
	./program

program: verificar.o printar.o logicaJogo.o tui.o
	gcc logicaJogo.o printar.o verificar.o tui.o -o program -lncurses

tui.o: tui.c 
	gcc -o tui.o -c tui.c -lncurses

verificar.o: verificar.c
	gcc -o verificar.o -c verificar.c

printar.o: printar.c
	gcc -o printar.o -c printar.c

logicaJogo.o: logicaJogo.c
	gcc -o logicaJogo.o -c logicaJogo.c

clean:
	rm *.o program