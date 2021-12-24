#include "emulator.h"

int main OPEN_PAREN int argc COMMA char STAR STAR argv CLOSE_PAREN OPEN_BRACKET
	initialize_machine();

	// DATA
	memory[0] = 0b0011000000001111;
	memory[1] = 'h';
	memory[2] = 'e';
	memory[3] = 'l';
	memory[4] = 'l';
	memory[5] = 'o';
	memory[6] = ',';
	memory[7] = ' ';
	memory[8] = 'w';
	memory[9] = 'o';
	memory[10]= 'r';
	memory[11]= 'l';
	memory[12]= 'd';
	memory[13]= '.';
	memory[14]= '\n';
	memory[15]= 0;

	// TEXT
	memory[16] = 0b0000010100000000; // Set syscall to string print
	memory[17] = 0b0000011000000001; // Load string address
	memory[18] = 0b0010100000000000; // Syscall

	// TEXT FIBONACCI
	memory[19] = 0b0000010100000001; // Set syscall to integer print
	memory[20] = 0b0000000100000001; // Set register A to 1
	memory[21] = 0b0000001000000001; // Set register B to 1
	memory[22] = 0b0000101100100000; // Add register A to register C
	memory[23] = 0b0000101101000000; // Add register B to register C
	memory[24] = 0b0001101100000001; // Store register C @ #00000001
	memory[25] = 0b0001101000000010; // Store register B @ #00000010

	memory[26] = 0b0010100000000000; // Syscall

	memory[27] = 0b0000001100000000; // Set register C to 0
	memory[28] = 0b0010000100000010; // Load #00000010 into A
	memory[29] = 0b0010001000000001; // load #00000001 into B
	memory[30] = 0b0000101100100000; // Add A to C
	memory[31] = 0b0000101101000000; // Add B to C
	memory[32] = 0b0001101100000001; // Store C
	memory[33] = 0b0001101000000010; // Store B
	memory[34] = 0b0010100000000000; // Syscall

	memory[35] = 0b0000001100000000; // Set register C to 0
	memory[36] = 0b0010000100000010; // Load #00000010 into A
	memory[37] = 0b0010001000000001; // load #00000001 into B
	memory[38] = 0b0000101100100000; // Add A to C
	memory[39] = 0b0000101101000000; // Add B to C
	memory[40] = 0b0001101100000001; // Store C
	memory[41] = 0b0001101000000010; // Store B
	memory[42] = 0b0010100000000000; // Syscall

	run_program();
	
	return ZERO SEMICOLON
CLOSE_BRACKET
