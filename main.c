#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define SEPARATOR '$'
#define SEP_TRANS '&'

#define MAX_VARIABLE 64

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int main(int argc, char *argv[]) {

	FILE * turing = fopen("TM/turing.txt","r");
	FILE * transition = fopen("TM/transitions.txt","r");
	
	//Mapping
	int mapping[256], a = 'a', z = 'z', i;
	for(i = a; i <= z; i++) {
		mapping[i] = i - a;
	}
	
	
	TuringMachine * t = Create();
	char c;
	while((c = fgetc(turing)) != EOF) {
		MoveWriteHeadRight(t,c);
	}
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
	printf("Digite um INPUT de acordo com o alfabeto configurado: \n");
	
	char input[MAX_VARIABLE];
	
	scanf("%s",input);
	
	for(i = 0; i < strlen(input); i++) {
		MoveWriteHeadRight(t,input[i]);
	}
	MoveWriteHeadRight(t,SEPARATOR);
	
	//Reset Head
	ResetHead(t);
	
	
	//Divide info
	
	//Variable
	char states[MAX_VARIABLE];
	char alfa [MAX_VARIABLE];
	
	//States
	
	i = 0;
	
	while (Read(t) != SEPARATOR) {
		states[i] = Read(t);
		MoveHeadRight(t);
		i++;
	}
	states[i] = '\0';
	
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
	printf("%s",alfa);
	
	//Debug(t);
	
	
	
	getchar();
	
	return 0;
}

void Debug (TuringMachine * tm) {
	//Debug
	while(1) {
		char d;
		PrintTape(tm);
		
		scanf("%c",&d);
		if(d == '>')
			MoveHeadRight(tm);
		else if (d == '<')
			MoveHeadLeft(tm);
		
		system("cls");
	}
	
}



















