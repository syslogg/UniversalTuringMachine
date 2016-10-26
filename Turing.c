#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define TM_MAX 5000
#define BLANK 2

struct machineturing {
	int tape[TAM_MAX];
	int head;
};

TuringMachine * Create() {
	TuringMachine * tm = (TuringMachine *) malloc(sizeof(TuringMachine));
	tm->head = TAM_MAX/2;
	
	int i;
	for(i = 0; i < TAM_MAX; i++) {
		tm->tape[i] = BLANK;
	}
	
	return tm;
}

void MoveHeadLeft (TuringMachine *  tm) {
	tm->head--;
}

void MoveHeadRight (TuringMachine *  tm) {
	tm->head++;
}

int Read(TuringMachine * tm) {
	return tm->tape[tm->head];
}

void Write(TuringMachine * tm, int value) {
	tm->tape[tm->head] = (value != 1 && value != 0 && value != BLANK ? tm->tape[tm->head] : value);
}
