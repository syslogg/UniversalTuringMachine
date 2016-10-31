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
	
	
	TuringMachine * t = Create();
	
	char ta[6];
	
	ta[0] = '1';
	ta[1] = '0';
	ta[2] = SEPARATOR;
	ta[3] = '0';
	ta[4] = '1';
	ta[5] = SEP_TRANS;
	
	
	LoadData(t,ta,sizeof(ta));
	printf("%d",sizeof(ta));
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
	
	return 0;
}





















