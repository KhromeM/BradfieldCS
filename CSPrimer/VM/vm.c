
// 123 bytes of memory
// 2 general purpose resigsters + PC + SP
// instruction set:
// add, sub, addi, subi
// branch if zero, jump, jump and call, return, halt
// each instruction 3 bytes
// Instruction set:
// Halt: 0, Store: 1, Load: 2, Move: 3,
// Jump 4, Return: 5, BZ: 6,
// Add: 7, Sub: 8, Mul: 9, Div: 10

#include <stdio.h>

int VM(unsigned char* memory,int SIZE,int MIN_STACK ){
    unsigned char PC = 0, R1 = 0, R2 = 0, SP = SIZE-1;
    
    while (PC < MIN_STACK && SP > MIN_STACK-1){
        unsigned char op = memory[PC++];
        unsigned char operand1 = memory[PC++];
        unsigned char operand2 = memory[PC++];
        printf("%d %d %d ", op, operand1, operand2);

        if (op == 0) return R1; // Halt
        else if (op == 1) { // Store
            if (operand1 == 1) {
                memory[operand2] = R1;
            } else {
                memory[operand2] = R2;
            }
        }
        else if (op == 2) { // Load
            if (operand1 == 1) {
                R1 = operand2;
            } else {
                memory[operand2];
                R2 = operand2;
            }
        }
        else if (op == 3) { // Move
            if (operand1 == 1) {
                R2 = R1;
            } else {
                memory[operand2];
                R1 = R2;
            }
        }
        else if (op == 4) { // Jump
            PC = operand1;
        }
        else if (op == 5) PC = memory[++SP]; // return
        else if (op == 6) { // Branch if zero
            if (operand1 == 1){
                if (R1 == 0) PC = operand2;
            } else{
                if (R2 == 0) PC = operand2;
            }
        }
        else if (op == 7){ // Add
            if (operand1 == 1) {
                R1 = R1 + R2;
            } else {
                R2 = R1 + R2;
            }
        }
        else if (op == 8){ // Subtract
            if (operand1 == 1) {
                R1 = R1 - R2;
            } else {
                R2 = R2 - R1;
            }
        }
        else if (op == 9){ // Muliply
            if (operand1 == 1) {
                R1 = R1 * R2;
            } else {
                R2 = R1 * R2;
            }
        }
        else if (op == 10){ // Divide
            if (operand1 == 1) {
                R1 = R1 / R2;
            } else {
                R2 = R1 / R2;
            }
        }
        else if (op == 11){ // Push
            if (operand1 == 1) {
                memory[SP--] = R1;
            } else {
                memory[SP--] = R2;
            }
        }
        else if (op == 12){ // Pop
            if (operand1 == 1) {
                R1 = memory[++SP];
            } else {
                R2 = memory[++SP];
            }
        }
        printf("R1:%d R2:%d \n", R1, R2);
        char s = getchar();

    }
    if (SP < MIN_STACK){
        printf("Stack limit exceeded!");
        return -1;
    }
    return 0;
}
void loadProgram(unsigned char* memory);

int main(){
    unsigned char memory[256] = {0};
    unsigned char MIN_STACK = 171; // 0-170 is for instructions
    loadProgram(memory);
    // for (int i = 0; i < 256; i++){
    //     printf("%d,", memory[i]);
    // }
    int result =  VM(memory,256,MIN_STACK);
    printf("result = %d", result);
    return 0;
}

void loadProgram(unsigned char* memory) {
    // load = 2 jump = 4 BZ = 6 add = 7 sub = 8 push = 11 pop = 12
    unsigned char instructions[26] = {2,2,10,6,2,24,7,1,2,11,1,0,2,1,1,8,2,1,12,1,0,4,3,0,0,0,0};
    for (int i = 0; i < 26; i++){
        memory[i] = instructions[i];
    }
}



