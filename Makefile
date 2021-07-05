run: program
	./program

program: verificar.o printar.o logicaJogo.o
	gcc logicaJogo.o printar.o verificar.o -o program

verificar.o: verificar.c
	gcc -o verificar.o -c verificar.c

printar.o: printar.c
	gcc -o printar.o -c printar.c

logicaJogo.o: logicaJogo.c
	gcc -o logicaJogo.o -c logicaJogo.c

clean:
	rm *.o program

zip:
	zip quarto4.zip *.c Makefile