#include "emulator.h"

int main OPEN_PAREN int argc COMMA char STAR STAR argv CLOSE_PAREN OPEN_BRACKET
	char phrase OPEN_SQUARE CLOSE_SQUARE ASSIGN OPEN_BRACKET 'h' COMMA 'e' COMMA 'l' COMMA 'l' COMMA
		'o' COMMA ',' COMMA ' ' COMMA 'w' COMMA 'o' COMMA 'r' COMMA 'l' COMMA 'd' COMMA '.' COMMA 0 CLOSE_BRACKET SEMICOLON
	char STAR word ASSIGN phrase SEMICOLON
	puts OPEN_PAREN word CLOSE_PAREN SEMICOLON

	initialize_machine();

	memory[0] = 0b0000000000000000;
	memory[1] = 0b0000000100000001;
	memory[2] = 0b0000001000000001;
	memory[3] = 0b0000001100000000;
	memory[4] = 0b0000000000000000;
	memory[5] = 0b0000101100100000;
	memory[6] = 0b0000101101000000;
	run_program();

	int i = 0;

	while (*word) {
		memory[i] = *word;
		word++;
		i++;
	}

	printerrupt(0);

	return ZERO;
CLOSE_BRACKET
