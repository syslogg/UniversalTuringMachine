//Type def
typedef struct machineturing TuringMachine;

//Create
TuringMachine * Create();

//Commands
void LoadData(TuringMachine * tm, int * data, int data_size);
void ResetHead(TuringMachine * tm);
void ClearTape(TuringMachine * tm);

//Moving
void MoveHeadLeft (TuringMachine *  tm);
void MoveHeadRight (TuringMachine *  tm);
void MoveWriteHeadLeft(TuringMachine * tm, int value);
void MoveWriteHeadRight(TuringMachine * tm, int value);

//Operation
int Read(TuringMachine * tm);
void Write(TuringMachine * tm, int value);

//Print
void PrintTape(TuringMachine * tm);
