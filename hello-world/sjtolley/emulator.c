#include "emulator.h"

uint_fast16_t memory OPEN_SQUARE 256 CLOSE_SQUARE SEMICOLON

uint_fast16_t reg0 COMMA
			regA COMMA
			regB COMMA
			regC COMMA
			regProg COMMA
			regInt COMMA
			regData SEMICOLON

uint_fast16_t STAR get_register OPEN_PAREN uint_fast16_t reg CLOSE_PAREN OPEN_BRACKET
	switch OPEN_PAREN reg CLOSE_PAREN OPEN_BRACKET
		case 0:
			return &reg0 SEMICOLON
		case 1:
			return &regA SEMICOLON
		case 2:
			return &regB SEMICOLON
		case 3:
			return &regC SEMICOLON
		case 4:
			return &regProg SEMICOLON
		case 5:
			return &regInt SEMICOLON
		case 6:
			return &regData SEMICOLON
	CLOSE_BRACKET
	return &regData SEMICOLON
CLOSE_BRACKET

void initialize_machine OPEN_PAREN CLOSE_PAREN OPEN_BRACKET
	reg0 = regA = regB = regC = regProg = regInt = regData = ZERO SEMICOLON

	for OPEN_PAREN int i ASSIGN 0 SEMICOLON i < 256 SEMICOLON INCREMENT(i) CLOSE_PAREN OPEN_BRACKET
		memory OPEN_SQUARE i CLOSE_SQUARE ASSIGN ZERO SEMICOLON
	CLOSE_BRACKET
CLOSE_BRACKET

void set_data_on_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t data CLOSE_PAREN OPEN_BRACKET
	STAR reg ASSIGN data SEMICOLON
CLOSE_BRACKET

void add_registers OPEN_PAREN uint_fast16_t STAR regA COMMA uint_fast16_t STAR regB CLOSE_PAREN OPEN_BRACKET
	STAR regA += STAR regB SEMICOLON
CLOSE_BRACKET

void add_value OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t data CLOSE_PAREN OPEN_BRACKET
	STAR reg += data SEMICOLON
CLOSE_BRACKET

void store_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t address CLOSE_PAREN OPEN_BRACKET
	memory OPEN_SQUARE address CLOSE_SQUARE ASSIGN STAR reg SEMICOLON
CLOSE_BRACKET

void load_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t address CLOSE_PAREN OPEN_BRACKET
	STAR reg ASSIGN memory OPEN_SQUARE address CLOSE_SQUARE SEMICOLON
CLOSE_BRACKET

void printerrupt OPEN_PAREN uint_fast16_t address CLOSE_PAREN OPEN_BRACKET
	uint_fast16_t STAR p ASSIGN &memory OPEN_SQUARE address CLOSE_SQUARE SEMICOLON
	while OPEN_PAREN STAR p != ZERO CLOSE_PAREN OPEN_BRACKET
		printf OPEN_PAREN "%c" COMMA OPEN_PAREN int CLOSE_PAREN STAR p CLOSE_PAREN SEMICOLON
		INCREMENT(p) SEMICOLON
	CLOSE_BRACKET
CLOSE_BRACKET

void integerrupt OPEN_PAREN uint_fast16_t address CLOSE_PAREN OPEN_BRACKET
	printf OPEN_PAREN "%d\n" COMMA OPEN_PAREN int CLOSE_PAREN memory OPEN_SQUARE address CLOSE_SQUARE CLOSE_PAREN SEMICOLON
CLOSE_BRACKET

void jmp OPEN_PAREN uint_fast16_t address CLOSE_PAREN OPEN_BRACKET
	regProg ASSIGN address SEMICOLON
CLOSE_BRACKET

void run_program OPEN_PAREN CLOSE_PAREN OPEN_BRACKET
	while OPEN_PAREN regProg < 256 CLOSE_PAREN OPEN_BRACKET
		uint_fast16_t command ASSIGN memory OPEN_SQUARE regProg CLOSE_SQUARE SEMICOLON

		uint_fast16_t opcode ASSIGN command & 0b0011100000000000 SEMICOLON
		opcode ASSIGN opcode >> 11 SEMICOLON

		uint_fast16_t reg1 ASSIGN command & 0b0000011100000000 SEMICOLON
		reg1 ASSIGN reg1 >> 8 SEMICOLON

		uint_fast16_t reg2 ASSIGN command & 0b0000000011100000 SEMICOLON
		reg2 ASSIGN reg2 >> 5 SEMICOLON

		uint_fast16_t data ASSIGN command & 0b0000000011111111 SEMICOLON

		switch OPEN_PAREN opcode CLOSE_PAREN OPEN_BRACKET
			case 0:
				set_data_on_register OPEN_PAREN get_register OPEN_PAREN reg1 CLOSE_PAREN COMMA data CLOSE_PAREN SEMICOLON				
				break SEMICOLON
			case 1:
				add_registers OPEN_PAREN get_register OPEN_PAREN reg1 CLOSE_PAREN COMMA get_register OPEN_PAREN reg2 CLOSE_PAREN CLOSE_PAREN SEMICOLON
				break SEMICOLON
			case 2:
				add_value OPEN_PAREN get_register OPEN_PAREN reg1 CLOSE_PAREN COMMA data CLOSE_PAREN SEMICOLON
				break SEMICOLON
			case 3:
				store_register OPEN_PAREN get_register OPEN_PAREN reg1 CLOSE_PAREN COMMA data CLOSE_PAREN SEMICOLON
				break SEMICOLON
			case 4:
				load_register OPEN_PAREN get_register OPEN_PAREN reg1 CLOSE_PAREN COMMA data CLOSE_PAREN SEMICOLON
				break SEMICOLON
			case 5:
				switch OPEN_PAREN regInt CLOSE_PAREN OPEN_BRACKET
					case 0:
						printerrupt OPEN_PAREN regData CLOSE_PAREN SEMICOLON
						break SEMICOLON
					case 1:
						integerrupt OPEN_PAREN regData CLOSE_PAREN SEMICOLON
						break SEMICOLON
				CLOSE_BRACKET
				break SEMICOLON
			case 6:
				jmp OPEN_PAREN data CLOSE_PAREN SEMICOLON
				break SEMICOLON
			case 7:
				return SEMICOLON
		CLOSE_BRACKET
		if OPEN_PAREN opcode != 6 CLOSE_PAREN OPEN_BRACKET
			INCREMENT(regProg) SEMICOLON
		CLOSE_BRACKET
	CLOSE_BRACKET
CLOSE_BRACKET
