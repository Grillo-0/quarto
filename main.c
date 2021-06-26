#include <stdio.h>

void inicializarTabuleiro();
void verficaTabuleiro();
void verificarLinhas();
void verificarColunas();
void verificarDiagoPri();
void verificarDiagoSec();
void venceu(int carac, int tipoCar, int tipo, int pos);
void printarTabuleiro();
void printarCarac(int carac, int tipoCar);


int tabuleiro[16];
int flag = 0;
int jogadas = 0;

int main(int argc, char *argv[]){
	inicializarTabuleiro();
	while(!flag){
		int peca;
		int posicao;
		scanf("%X\n%X",&peca, &posicao);

		tabuleiro[posicao] = peca;
		verficaTabuleiro();
		jogadas++;
	}
}


void inicializarTabuleiro(){
	for(int i=0; i<16; i++){
		tabuleiro[i]=-1;
	}

}

void verficaTabuleiro(){
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
		if(xnor>>4 && xor){
			venceu(xnor, tipoCar, 0,i);
		}
	}
}


void verificarColunas(){
	//printf("Colunas Verificadas\n");
	int and;
	int or;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			and &= tabuleiro[i+j*4];
			or |= tabuleiro[i+j*4];
		}
		xor = and ^ or;
		xnor= ~xor;
		tipoCar = xnor & and;
		if(xnor>>4 && xor){
			venceu(xnor, tipoCar, 1,i);
		}
	}
}

void verificarDiagoPri(){
	//printf("Diagonal Principal Verificada\n");
	int and;
	int or;
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
	if(xnor>>4 && xor){
		venceu(xnor, tipoCar, 2,1);
	}
}

void verificarDiagoSec(){
	//printf("Diagonal Secundaria Verificada\n");
	int and;
	int or;
	int xor;
	int xnor;
	int tipoCar;
	for(int i=0;i<4;i++){
		and &= tabuleiro[i*3];
		or |= tabuleiro[i*3];
	}
	xor = and ^ or;
	xnor= ~xor;
	tipoCar = xnor & and;
	if(xnor>>4 && xor){
		venceu(xnor, tipoCar, 2,2);
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
	//printarSequencia(tipo,pos);
	printarCarac(carac, tipoCar);
	flag = 1;
}

void printarCarac(int carac, int tipoCar){
	int mask = 0b0001;
	for(int i=0;i<4;i++){
		int res = (mask<<i & carac)>>i;
		int tipo = (mask<<i & tipoCar)>>i;
		if(res){
			if(tipo){
				switch(i){
					case 0:
						printf("oca\n");
						break;
					case 1:
						printf("quadrada\n");
						break;
					case 2:
						printf("pequena\n");
						break;
					case 3:
						printf("escura\n");
						break;
				}
			}
			else{
				switch(i){
					case 0:
						printf("solida\n");
						break;
					case 1:
						printf("circular\n");
						break;
					case 2:
						printf("grande\n");
						break;
					case 3:
						printf("branca\n");
						break;
				}
			}
		}
	}
}

//void printarSequencia(int tipo ,int pos){
	
//}
//0001	0100
//0011	1110
//0001	0110
//1001	1100
//
//0001	0100
//1011	1110
//
//1010	1010
//
//0101	0101
//0001	0100

