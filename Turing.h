//Type def
typedef struct machineturing TuringMachine;

//Command
TuringMachine * Create();

//Moving
void MoveHeadLeft (TuringMachine *  tm);
void MoveHeadRight (TuringMachine *  tm);

//Operation
int Read(TuringMachine * tm);
