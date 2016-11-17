#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define SEPARATOR '$'
#define SEP_TRANS '&'
#define BLANK 254

#define MAX_VARIABLE 64

#define bool int
#define true 1
#define false 0

/* -- Codification:
		- 0 to 00
		- 1 to 01
		- $ to 10
		- & to 11
		
		-- Example
			- 10$01
			- 01 00 10 00 01
    -- Mapping
    	- a to 00001
    	- b to 00010
    	- c to 00011
    	- d to 00100
    	- e to 00101
    	- f to 00110
    	- g to 00111
    	- h to 01000
    	- i to 01001
    	- j to 0
    	- l to 00000
    	- m to 00000
    	- n to 00000
    	- o to 00000
    	- p to 00000
    	- q to 00000
    	- r to 00000
    	- s to 00000
    	- a to 00000
    	- a to 00000
		
	-- Tape form
		- Transition: EstadoAtual&Entrada&EstadoDest&Escreve&Direcao
			-- Direction:
				- <:  00;
				- >:  01;
				- H:  11;
		- TM Config: Estados$Alfabeto

*/
struct transition {
	int EstAtual;
	char IAtual;
	char Escr;
	int ProxState;
	char Dir;
};
typedef struct transition Transition;

int Codification (char * c);

int main(int argc, char *argv[]) {

	FILE * turing = fopen("TM/turing.txt","r");
	FILE * transition = fopen("TM/transitions.txt","r");
	FILE * transition2 = fopen("TM/transitions.txt", "r");
	
	//Variable
	char states[MAX_VARIABLE];
	char alfa[MAX_VARIABLE];
	char alfaFita[MAX_VARIABLE];
	Transition trans[MAX_VARIABLE];
	
	int i;
	
	
	
	
	
	TuringMachine * t = Create();
	char c;
	while((c = fgetc(turing)) != EOF) {
		MoveWriteHeadRight(t,c);
	}
	MoveWriteHeadRight(t,SEPARATOR);
	ResetHead(t);
	
	
	
	while(Read(t) != SEPARATOR) {
		MoveHeadRight(t);
	}
	MoveHeadRight(t);
	
	
	while(Read(t) != SEPARATOR) {
		MoveHeadRight(t);
	}
	MoveHeadRight(t);
	
	i = 0;
	while(Read(t) != SEPARATOR) {
		alfaFita[i] = Read(t);
		MoveHeadRight(t);
		i++;
	}
	alfaFita[i] = '\0';
	
	
	
	//Aloca na variavel as transições
	i = 0;
	char buffer[MAX_VARIABLE], a1, a2, a3, a4, a5, aa[5];
	while(fgets(buffer,sizeof(buffer),transition2) != NULL ) {
		
		//sscanf(buffer, "%[^'&']&%[^'&']&%[^'&']&%[^'&']&%c\n",&a1,&a2,&a3,&a4,&a5); //0&s&d&1&>
		
		char * token = strtok(buffer,"&");
		a1 = token[0];
		token = strtok(NULL, "&");
		a2 = token[0];
		token = strtok(NULL, "&");
		a3 = token[0];
		token = strtok(NULL, "&");
		a4 = token[0];
		token = strtok(NULL, "&");
		a5 = token[0];
		
		/*int js = 0;
		while(token != NULL) {
			aa[js] = token[0];
			token = strtok(NULL, "&");
			js++;
		}*/
				
		//printf("1%s 2%c 3%s 4%c 5%c\n", a1,a2,a3,a4,a5);
		//printf("1-|%c| 2-|%c| 3-|%c| 4-|%c| 5-|%c|\n",a1, a2,a3,a4,a5);
		//printf("%c\n", a1);
		
	//	printf("8(q%d, %c) = (q%d, %c, %c);\n", trans[i].EstAtual);
		
		int EstAtual = a1 - '0';
		trans[i].EstAtual = EstAtual;
		
		char InAtual = a2 == '#' ? BLANK : a2;
		trans[i].IAtual = InAtual;
		
		int ProxEst = a3 - '0';
		trans[i].ProxState = ProxEst;
		
		int Escr = a4 == '#' ? BLANK : a4;
		trans[i].Escr = Escr;
		
		trans[i].Dir = a5;
		
		//printf("8(q%d, %c) = (q%d, %c, %c);\n",trans[i].EstAtual,trans[i].IAtual,trans[i].ProxState, trans[i].Escr, trans[i].Dir);
		
		
		
		//trans[i].Escr = a4 == '#' ? BLANK : a4;
		i++;
		//PrintTransition(trans[i]);
		//printf("8(q%d, %c) = (q%d, %c, %c);\n", trans[i].EstAtual,trans[i].IAtual,trans[i].ProxState,trans[i].Escr,trans[i].Dir);
		
	}
	int qtdTransition = i;
	
	
	//Aloca na maquina de turing
	while((c = fgetc(transition)) != EOF) {
		if(c == '\n') {
			MoveWriteHeadRight(t,SEP_TRANS);
			MoveWriteHeadRight(t,SEP_TRANS);
		} else {
			MoveWriteHeadRight(t,c);
		}
		
	}
	MoveWriteHeadRight(t,SEPARATOR);

	
	
	//Processar input
	printf("Digite um INPUT de acordo com o alfabeto configurado (%s): \n",alfaFita);
	
	char input[MAX_VARIABLE];
	
	scanf("%s",input);
	
	bool valid = true;
	int n;
	for(i = 0; i < strlen(input); i++) {
		char car = input[i];
		bool validCar = false;
		for(n = 0; n < strlen(alfaFita); n++) {
			if(alfaFita[n] == car) {
				validCar = true;
			}
		}
		if(validCar == false) {
			valid = false;
		}
		break;
		
	}
	
	if(valid == false) {
		system("cls");
		printf("Input diferente com alfabeto da fita configurado!");
		printf("\nAlfabeto atual: %s", alfaFita);
		return 1;
	}
	
	for(i = 0; i < strlen(input); i++) {
		MoveWriteHeadRight(t,input[i]);
	}
	MoveWriteHeadRight(t,SEPARATOR);
	
	
	
	
	
	//Reset Head
	ResetHead(t);
	
	while (Read(t) != SEPARATOR) {
		//states[i] = Read(t);
		MoveHeadRight(t);
		//i++;
	}
	//Divide info
	
	
	//States
	
	//i = 0;
	
/*	while (Read(t) != SEPARATOR) {
		states[i] = Read(t);
		MoveHeadRight(t);
		i++;
	}
	states[i] = '\0';
	*/
	//printf("%s",states);
	MoveHeadRight(t);
	
	//Divide alfa
	
	i = 0;
	while (Read(t) != SEP_TRANS) {
		alfa[i] = Read(t);
		MoveHeadRight(t);
		i++;
	}
	alfa[i] = '\0';
	
	while(Read(t) != SEPARATOR) {
		MoveHeadRight(t);
	}
	
	while(Read(t) != SEPARATOR) {
		MoveHeadRight(t);
	}
	
	for (i = 0; i < strlen(input); i++) {
		MoveHeadRight(t);
	}
	
	MoveHeadRight(t);
	
	//Leitura de transições
	TuringMachine * t2 = Create();
	
	//Logica de maquina de turing
	
	LoadData(t2, input);
	
	bool termina = false;
	bool func = false;
	
	int state = getState(t2);
	
	//Debug(t2);
	
	//printf("%d", !termina);
	/*
	i = 0;
	for(i  = 0; i <  qtdTransition; i++) {
		PrintTransition(trans[i]);
	}
	*/
	
	Transition * atual = NULL;
	while(!termina){
		i = 0;
		atual = NULL;
		//Pesquisar transacao
		for (i = 0; i < qtdTransition; i++) {
			//Percorre todas as transações
			if(trans[i].EstAtual == state) {
				//Estado atual encontrado
				
				if(trans[i].IAtual == Read(t2)) {
					//Input atual encontrado
					atual = &trans[i];
				} 
			}
		}
		
		//PrintTransition(*atual);
		//getch();
		//Imprimir transicao atual
		//Processamento do estado atual
		
		if(atual == NULL) {
			//Não encontrou transição para situação atual
			//Maquina quebrou
			
			printf("Nao foi encontrado funcao de transicao para estado q%d e \"input\" %c ou foi processado um input que não existe no alfabeto da fita.", state, Read(t2));
			getch();
			termina = true;
			func = false;
			
		} else {
			system("cls");
			PrintTape(t);
			PrintTape(t2);
			Write(t2, atual->Escr);
			printf("\nEstado atual: |%d|\n", state);
			printf("\nEscreve atual: |%c|\n",atual->Escr);
			setState(t2, atual->ProxState);
			state = getState(t2);
			
			
			printf("Proximo estado: |%d|\n", state);
			
			PrintTransition(*atual);
			
			getch();
			
			//Direção
			switch(atual->Dir) {
				case '>':
					MoveHeadRight(t2);
					break;
				case '<':
					MoveHeadLeft(t2);
					break;
				case 'H':
					//Maquina entrou em HALT
					termina = true;
					func = true;
					getch();
					break;
			}
			
		}
			
	}
	system("cls");
	if(func == true) {
		
		//PrintTape(t2);
		MoveHeadLeft(t2);
		while(Read(t2) != (char)BLANK) {
			PrintTape(t);
			PrintTape(t2);
			MoveHeadLeft(t2);
			
			
			getch();
			system("cls");
		}
		
		MoveHeadRight(t2);
		MoveHeadRight(t);
		while(Read(t2) != (char) BLANK) {
			
			MoveWriteHeadRight(t,(char)Read(t2));
			PrintTape(t);
			PrintTape(t2);
			MoveHeadRight(t2);
			getch();
			system("cls");
		}
	}
	
	Debug(t);
	
	  
	
	getchar();
	
	return 0;
}

void Debug (TuringMachine * tm) {
	//Debug
	
	char binary[MAX_VARIABLE];
	int decimal;
	
	//printf("%s",GetTape(tm));
	
	while(1) {
		char d;
		PrintTape(tm);
		itoa(Codification(GetTape(tm)),binary,2);
		//printf("\nNumero da fita (decimal): %s\n",  binary);
		printf("Numero da fita (decimal): %d\n",Codification(GetTape(tm)));
		
		
		scanf("%c",&d);
		if(d == '>')
			MoveHeadRight(tm);
		else if (d == '<')
			MoveHeadLeft(tm);
		
		system("cls");
	}
	
}

void PrintTransition(Transition t) {
	//printf("8(q%d, %c) = (q%d, %c, %c);\n", t.EstAtual, t.IAtual, t.ProxState,  t.Escr, t.Dir);
	printf("8(q%d, %c) = (q%d, %c, %c);\n",t.EstAtual,t.IAtual,t.ProxState, t.Escr, t.Dir);
	/*
	int EstAtual;
	char IAtual;
	char Escr;
	int ProxState;
	char Dir;
	*/
	
}

int Codification (char * c) {
	
	int soma = 0;
	
	int i = 0, ca = 0, b;
	
	//Mapping
	int mapping[256], a = 'a', z = 'z';
	
	for(i = 0; i < 256; i++) {
		mapping[i] = -1;
	}
	
	for(i = a; i <= z; i++) {
		mapping[i] = i - a;
		
	}
	
	mapping['0'] = i - a;
	mapping['1'] = i - a + 1;
	mapping['2'] = i - a + 2;
	mapping['3'] = i - a + 3;
	mapping['4'] = i - a + 4;
	mapping['5'] = i - a + 5;
	mapping['6'] = i - a + 6;
	mapping['7'] = i - a + 7;
	mapping['8'] = i - a + 8;
	mapping['9'] = i - a + 9;
	
	mapping[SEPARATOR] = i - a + 10;
	mapping[SEP_TRANS] = i - a + 11;
	mapping['H'] = i - a + 12;
	
	while(*(c + i) != '\0') {
	
		char buf = *(c+i);
		int number = mapping[buf];
		if(number != -1) {
			
			/*char binnary[256];
			itoa(number,binnary,2);
			
			for(b = 0; binnary[b] != '\0'; b++) {
				code[ca++] = binnary[b];
			}
			*/
			soma += number;
			
		} else {
			return -1;
		}
		i++;
		
	}
	//code[ca] = '\0';
	return soma;
	
}

















