run: program
	.\program

program: verificar printar logicaJogo
	gcc logicaJogo.o printar.o verificar.o -o program

verificar: verificar
	gcc -o verificar.o -c verificar.c

printar: printar
	gcc -o printar.o -c printar.c

logicaJogo: logicaJogo
	gcc -o logicaJogo.o -c logicaJogo.c