//Type def
typedef struct machineturing TuringMachine;

//Create
TuringMachine * Create();

//Commands
void LoadData(TuringMachine * tm, char * data, int data_size);
void ResetHead(TuringMachine * tm);
void ClearTape(TuringMachine * tm);

//Moving
void MoveHeadLeft (TuringMachine *  tm);
void MoveHeadRight (TuringMachine *  tm);
void MoveWriteHeadLeft(TuringMachine * tm, char value);
void MoveWriteHeadRight(TuringMachine * tm, char value);

//Operation
char Read(TuringMachine * tm);
void Write(TuringMachine * tm, char value);

//Print
void PrintTape(TuringMachine * tm);
