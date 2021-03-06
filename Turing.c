#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Turing.h"

#define TAM_MAX 2000
#define RANGE_TAPE 10
#define BLANK 254
#define SEPARATOR '$'
#define SEP_TRANS '&'

struct machineturing {
	int state;
	char tape[TAM_MAX];
	int head;
};
/*----------- Create -----------*/
TuringMachine * Create() {
	TuringMachine * tm = (TuringMachine *) malloc(sizeof(TuringMachine));
	tm->head = TAM_MAX/2;
	tm->state = 0;
	
	int i;
	for(i = 0; i < TAM_MAX; i++) {
		tm->tape[i] = BLANK;
	}
	
	return tm;
}

/*----------- Comands -----------*/
void LoadData(TuringMachine * tm, char * data) {
	int head = tm->head, i;
	ClearTape(tm);
	
	for(i = 0; i < strlen(data); i++){
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


void MoveWriteHeadLeft (TuringMachine * tm, char value) {
	tm->tape[tm->head--] = value;
}

void MoveWriteHeadRight (TuringMachine * tm, char value) {
	tm->tape[tm->head++] = value;
}

/*----------- Operations -----------*/
char Read(TuringMachine * tm) {
	return tm->tape[tm->head];
}

void Write(TuringMachine * tm, char value) {
	tm->tape[tm->head] = value;
}

char * GetTape(TuringMachine * tm) {
	
	int i, c = 0;
	char str[TAM_MAX];
	for (i = 0; i < TAM_MAX; i++) {
		if(tm->tape[i] != (char) BLANK) {
			str[c] = tm->tape[i];
			c++;
		}
	}
	str[c++] = '\0';
	
	return str;
	
}

void PrintTape(TuringMachine * tm) {
	
	int i;
	printf("\n[ ");
	for (i = tm->head-RANGE_TAPE; i <= tm->head+RANGE_TAPE; i++) {
		if(tm->head != i)
			printf("%c ", tm->tape[i]);
		else
			printf("|%c| ",tm->tape[i]);
	}
	printf("]\n\n");
	
}

/* ------------ Getters -------------- */

int getState(TuringMachine * tm){
	return tm->state;
}

void setState(TuringMachine * tm, int state){
	tm->state = state;
}

void Encode(TuringMachine * tm) {
	
}
