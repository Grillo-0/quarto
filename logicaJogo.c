#include <stdio.h>

void inicializarTabuleiro();
void verificaTabuleiro();
void verificarLinhas();
void verificarColunas();
void verificarDiagoPri();
void verificarDiagoSec();
void venceu(int carac, int tipoCar, int tipo, int pos);
void printarTabuleiro();
void printarCarac(int carac, int tipoCar);
void printarSequencia(int tipo ,int pos);

int tabuleiro[16];
int flag = 1;
int jogadas = 0;

int main(int argc, char *argv[]){
	inicializarTabuleiro();
	while(flag){
		if(jogadas > 15){
			printarTabuleiro();
			printf("0\n");
			flag = 0;
		}
		int peca;
		int posicao;
		scanf("%X\n%X",&peca, &posicao);

		tabuleiro[posicao] = peca;
		verificaTabuleiro();
		jogadas++;
	}
}


void inicializarTabuleiro(){
	for(int i=0; i<16; i++){
		tabuleiro[i]=-1;
	}

}

void verificaTabuleiro(){
	verificarLinhas();
	verificarColunas();
	verificarDiagoPri();
	verificarDiagoSec();
}


void verificarLinhas(){
	//printf("Linhas Verificadas\n");
	int and;
	int or;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=0;i<4;i++){
		and = -1;
		or = 0x0;
		for(int j=0;j<4;j++){
			and &= tabuleiro[j+i*4];
			or |= tabuleiro[j+i*4];
		}
		xor = and ^ or;
		xnor = ~xor;
		tipoCar = xnor & and;
		if(flag && xnor>>4 && xor ^ 0xf && and != or){
			venceu(xnor, tipoCar, 0,i);
		}
	}
}

//11111111
//11111111
//11111111
//11111111
//
//11111111 and
//11111111 or
//
//00000000 xor
//
//11111111 xnor
//
//00000000 tipoCar

void verificarColunas(){
	//printf("Colunas Verificadas\n");
	int and;
	int or;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=0;i<4;i++){
		and = -1;
		or = 0x0;
		for(int j=0;j<4;j++){
			and &= tabuleiro[i+j*4];
			or |= tabuleiro[i+j*4];
		}
		xor = and ^ or;
		xnor= ~xor;
		tipoCar = xnor & and;
		if(flag && xnor>>4 && xor ^ 0xf && and != or){
			venceu(xnor, tipoCar, 1,i);
		}
	}
}

void verificarDiagoPri(){
	//printf("Diagonal Principal Verificada\n");
	int and = -1;
	int or = 0x0;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=0;i<4;i++){
		and &= tabuleiro[i*5];
		or |= tabuleiro[i*5];
	}
	xor = and ^ or;
	xnor= ~xor;
	tipoCar = xnor & and;
	if(flag && xnor>>4 && xor ^ 0xf && and != or){
		venceu(xnor, tipoCar, 2,0);
	}
}

void verificarDiagoSec(){
	//printf("Diagonal Secundaria Verificada\n");
	int and = -1;
	int or = 0x0;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=1;i<5;i++){
		and &= tabuleiro[i*3];
		or |= tabuleiro[i*3];
	}
	xor = and ^ or;
	xnor= ~xor;
	tipoCar = xnor & and;
	if(flag && xnor>>4 && xor ^ 0xf && and != or){
		venceu(xnor, tipoCar, 2,1);
	}
}

void printarTabuleiro(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int peca = tabuleiro[i*4+j];
			if(peca != -1){
				printf("%X",peca);
			}
			else{
				printf("-");
			}
		}
		printf("\n");
	}
}

//ehescura ehbaixa ehquadrada  ehoca
//   0        0        0         0

void venceu(int carac, int tipoCar, int tipo, int pos){
	printarTabuleiro();
	printf("%d\n",!(jogadas % 2) + 1);
	printarSequencia(tipo,pos);
	printarCarac(carac, tipoCar);
	flag = 0;
}

void printarCarac(int carac, int tipoCar){
	int mask = 0b0001;
	for(int i=3;i>=0;i--){
		int res = (mask<<i & carac)>>i;
		int tipo = (mask<<i & tipoCar)>>i;
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

void printarSequencia(int tipo ,int pos){
	switch(tipo){
		case 0:
			for(int i=0;i<4;i++){
				printf("%X",i+pos*4);
			}
			printf("\n");
			break;
		case 1:
			for(int i=0;i<4;i++){
				printf("%X",pos+i*4);
			}
			printf("\n");
			break;
		case 2:
			for(int i=pos;i<pos+4;i++){
				printf("%X",i*(!pos*5)+i*(pos*3));
			}
			printf("\n");
			break;
	}
}