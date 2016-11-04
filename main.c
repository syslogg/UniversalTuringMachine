#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define SEPARATOR '$'

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* -- Codification:
		- 0 to 00
		- 1 to 01
		- $ to 10
		
		-- Example
			- 10$01
			- 01 00 10 00 01
		
	
*/

int main(int argc, char *argv[]) {
	
	printf("Teste");
	
	/*
	TuringMachine * t = Create();
	
	char ta[5];
	
	ta[0] = '1';
	ta[1] = '0';
	ta[2] = SEPARATOR;
	ta[3] = '0';
	ta[4] = '1';
	
	
	WriteTapeToCoded(t,ta,sizeof(ta));

	while(1) {
		char d;
		PrintTape(t);
		printf("\n\n%d\n\n",ReadCoded(t));
		scanf("%c",&d);
		if(d == '>')
			DoubleRight(t);
		else if (d == '<')
			DoubleLeft(t);
		
		system("cls");
	}
	

	
	
	getchar();
	*/
	return 0;
}

void WriteTapeToCoded (TuringMachine * tm, char * numbers, int size) {
	int i;
	
	for(i = 0; i < size; i++) {
		if(numbers[i] == '0'){
			MoveWriteHeadRight(tm,0);
			MoveWriteHeadRight(tm,0);
		} else if (numbers[i] == '1') {
			MoveWriteHeadRight(tm,0);
			MoveWriteHeadRight(tm,1);
		} else if (numbers[i] == SEPARATOR){
			MoveWriteHeadRight(tm,1);
			MoveWriteHeadRight(tm,0);
		}
		
	}
}

int ReadCoded(TuringMachine * tm) {
	int bits[2];
	
	bits[0] = Read(tm);
	MoveHeadRight(tm);
	
	bits[1] = Read(tm);
	MoveHeadLeft(tm);
	
	if(bits[0] == 0) {
		if(bits[1] == 1) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if(bits[1] == 0) {
			return SEPARATOR;
		}
	}
	
}

void DoubleLeft (TuringMachine *  tm) {
	MoveHeadLeft(tm);
	MoveHeadLeft(tm);
}

void DoubleRight (TuringMachine *  tm) {
	MoveHeadRight(tm);
	MoveHeadRight(tm);
}


















