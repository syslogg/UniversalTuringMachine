#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define SEPARATOR '$'
#define SEP_TRANS '&'

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* -- Codification:
		- 0 to 00
		- 1 to 01
		- $ to 10
		- & to 11
		
		-- Example
			- 10$01
			- 01 00 10 00 01
		
	
*/

int main(int argc, char *argv[]) {
	
<<<<<<< HEAD
	printf("Teste");
=======
	FILE * turing = fopen("TM/turing.txt","r");
	FILE * transition = fopen("TM/transitions.txt","r");
>>>>>>> e926a44bd4b3e2ce4f7638ef2d17c06aa4a77044
	
	/*
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
	print("Digite um INPUT de acordo com o alfabeto ()");
	
	//ResetHead(t);
	
	
	
	//Debug
	//LoadData(t,ta,sizeof(ta));
	//printf("%d",sizeof(ta));
	while(1) {
		char d;
		PrintTape(t);
		
		scanf("%c",&d);
		if(d == '>')
			MoveHeadRight(t);
		else if (d == '<')
			MoveHeadLeft(t);
		
		system("cls");
	}
	

	
	
	getchar();
	*/
	return 0;
}





















