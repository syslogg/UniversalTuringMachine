#include <stdio.h>
#include <stdlib.h>
#include "Turing.h"

#define TAM_MAX 5000

struct machineturing {
	int tape[TAM_MAX];
	int head;
};

TuringMachine * Create() {
	TuringMachine * tm = (TuringMachine *) malloc(sizeof(TuringMachine));
	tm->head = TAM_MAX/2;
	
	return tm;
}

