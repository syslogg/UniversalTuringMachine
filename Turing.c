#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define TAM_MAX 500
#define RANGE_TAPE 10
#define BLANK 254

struct machineturing {
	int tape[TAM_MAX];
	int head;
};
/*----------- Create -----------*/
TuringMachine * Create() {
	TuringMachine * tm = (TuringMachine *) malloc(sizeof(TuringMachine));
	tm->head = TAM_MAX/2;
	
	int i;
	for(i = 0; i < TAM_MAX; i++) {
		tm->tape[i] = BLANK;
	}
	
	return tm;
}

/*----------- Comands -----------*/
void LoadData(TuringMachine * tm, int * data, int data_size) {
	int head = tm->head, i, lenght = data_size/sizeof(int);
	ClearTape(tm);
	
	for(i = 0; i < lenght; i++){
		tm->tape[head++] = data[i];
	}
}

void ResetHead(TuringMachine * tm) {
	tm->head = TAM_MAX/2;
}

void ClearTape (TuringMachine * tm) {
	int i;
	for(i = 0; i < TAM_MAX; i++) {
		tm->tape[i] = BLANK;
	}
	ResetHead(tm);
}

/*----------- Moving -----------*/
void MoveHeadLeft (TuringMachine *  tm) {
	tm->head--;
}

void MoveHeadRight (TuringMachine *  tm) {
	tm->head++;
}


void MoveWriteHeadLeft (TuringMachine * tm, int value) {
	tm->tape[tm->head--] = value;
}

void MoveWriteHeadRight (TuringMachine * tm, int value) {
	tm->tape[tm->head++] = value;
}

/*----------- Operations -----------*/
int Read(TuringMachine * tm) {
	return tm->tape[tm->head];
}

void Write(TuringMachine * tm, int value) {
	tm->tape[tm->head] = (value != 1 && value != 0 && value != BLANK ? tm->tape[tm->head] : value);
}

void PrintTape(TuringMachine * tm) {
	
	int i;
	printf("\n[ ");
	for (i = tm->head-RANGE_TAPE; i <= tm->head+RANGE_TAPE; i++) {
		
		if(tm->tape[i] != BLANK) {
			if(tm->head != i)
				printf("%d ", tm->tape[i]);
			else
				printf("|%d| ",tm->tape[i]);
		} else {
			if(tm->head != i)
				printf("%c ", tm->tape[i]);
			else
				printf("|%c| ",tm->tape[i]);
		}
		
	}
	printf("]\n\n");
	
}
