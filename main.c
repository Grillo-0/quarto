#include <stdio.h>

int verificarDiagoPri();
int verificarDiagoSec();
int verificarDiagoPri();
int verificarColunas();
void venceu(int carac, int tipo, int pos);
int verificarLinhas();
int verficaTabuleiro();
void inicializarTabuleiro();
void printarTabuleiro();


int tabuleiro[16];
int flag = 0;

int main(int argc, char *argv[]){
	inicializarTabuleiro();
	while(flag){
		int peca;
		int posicao;
		scanf("%X %X",&peca, &posicao);

		tabuleiro[posicao] = peca;
		verficaTabuleiro();
	}
}


void inicializarTabuleiro(){
	for(int i=0; i<16; i++){
		tabuleiro[i]=-1;
	}
}

int verficaTabuleiro(){
	verificarDiagoSec();
	verificarDiagoPri();
	verificarColunas();
	verificarLinhas();
}


int verificarLinhas(){
	int and;
	int or;
	int xor;
	int xnor;
	for(int i=0;i<4;i++){
		and = -1;
		or = 0x0;
		for(int j=0;j<4;j++){
			and &= tabuleiro[j+i*4];
			or |= tabuleiro[j+i*4];
		}
		xor = and ^ or;
		xnor = ~xor;
		if(xnor>>4){
			venceu(xnor, 0,i);
		}
	}
}

void venceu(int carac, int tipo, int pos){
	printarTabuleiro(tabuleiro);
	printf("%d",!(jogadas % 2) + 1);
	printarSequencia(tipo,pos);
	printarCarac(carac);
	flag = 1;
}

int verificarColunas(){
	int and;
	int or;
	int xor;
	int xnor;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			and &= tabuleiro[i+j*4];
			or |= tabuleiro[i+j*4];
		}
		xor = and ^ or;
		xnor= ~xor;
		if(xnor>>4){
			venceu(xnor, 1,i);
		}
	}
	return 0;
}

int verificarDiagoPri(){
	int and;
	int or;
	int xor;
	int xnor;
	for(int i=0;i<4;i++){
		and &= tabuleiro[i*5];
		or |= tabuleiro[i*5];
	}
	xor = and ^ or;
	xnor= ~xor;
	if(xnor>>4){
		venceu(xnor, 2,1);
	}
	return 0;
}

int verificarDiagoSec(){
	int and;
	int or;
	int xor;
	int xnor;
	for(int i=0;i<4;i++){
		and &= tabuleiro[i*3];
		or |= tabuleiro[i*3];
	}
	xor = and ^ or;
	xnor= ~xor;
	if(xnor>>4){
		venceu(xnor, 2,2);
	}
	return 0;
}

void printarTabuleiro(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int peca = tabuleiro[i*4+j];
			if(peca == -1){
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

void printarCarac(int carac){
	int mask = 0b0001;
	for(int i=0;i<4;i++){
		int res = (mask<<i & carac)>>i;
		if(res){
			if(i == 0){
				printf("Oca")
			}
		}
	}
}
