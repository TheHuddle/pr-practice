#include "emulator.h"

int main OPEN_PAREN int argc COMMA char STAR STAR argv CLOSE_PAREN OPEN_BRACKET
	char phrase OPEN_SQUARE CLOSE_SQUARE ASSIGN OPEN_BRACKET 'h' COMMA 'e' COMMA 'l' COMMA 'l' COMMA
		'o' COMMA ',' COMMA ' ' COMMA 'w' COMMA 'o' COMMA 'r' COMMA 'l' COMMA 'd' COMMA '.' COMMA 0 CLOSE_BRACKET SEMICOLON
	char STAR word ASSIGN phrase SEMICOLON
	puts OPEN_PAREN word CLOSE_PAREN SEMICOLON

	initialize_machine();

	set_data_on_register(&regA, 43);
	set_data_on_register(&regB, 34);
	add_registers(&regA, &regB);
	add_value(&regA, 11);
	store_register(&regA, 0);
	load_register(&regC, 0);
	printerrupt(0);

	memory[0] = 0b0001000100000100;
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
