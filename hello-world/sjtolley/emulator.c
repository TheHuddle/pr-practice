#include "emulator.h"

uint_fast16_t memory[256];

uint_fast16_t reg0, regA, regB, regC, regProg, regInt, regData;

uint_fast16_t* get_register(uint_fast16_t reg) {
	switch (reg) {
		case 0:
			return &reg0;
		case 1:
			return &regA;
		case 2:
			return &regB;
		case 3:
			return &regC;
		case 4:
			return &regProg;
		case 5:
			return &regInt;
		case 6:
			return &regData;
	}
}

void initialize_machine() {
	reg0 = regA = regB = regC = regProg = regInt = regData= 0;

	for (int i = 0; i < 256; i++) {
		memory[i] = 0;
	}
}

void set_data_on_register(uint_fast16_t *reg, uint_fast16_t data) {
	*reg = data;
}

void add_registers(uint_fast16_t *regA, uint_fast16_t *regB) {
	*regA += *regB;
}

void add_value(uint_fast16_t *reg, uint_fast16_t data) {
	*reg += data;
}

void store_register(uint_fast16_t *reg, uint_fast16_t address) {
	memory[address] = *reg;
}

void load_register(uint_fast16_t *reg, uint_fast16_t address) {
	*reg = memory[address];
}

void printerrupt(uint_fast16_t address) {
	uint_fast16_t *p = &memory[address];
	while (*p != 0) {
		printf("%c", *p);
		p++;
	}
}

void jmp(uint_fast16_t address) {
	regProg = address;
}

void run_program() {
//	while (regProg < 256) {
		uint_fast16_t command = memory[regProg];
		uint_fast16_t opcode = command & 0b0011100000000000;
		opcode = opcode >> 11;
		uint_fast16_t reg1 = command & 0b0000011100000000;
		reg1 = reg1 >> 8;
		uint_fast16_t reg2 = command & 0b0000000011100000;
		reg2 = reg2 >> 5;
		uint_fast16_t data = command & 0b0000000011111111;
		switch (opcode) {
			case 0:
				printf("OPCODE 0 on (%d) with #%d\n", reg1, data);
				set_data_on_register(get_register(reg1), data);				
				break;
			case 1:
				printf("OPCODE 1");
				add_registers(get_register(reg1), get_register(reg2));
				break;
			case 2:
				printf("OPCODE 2");
				add_value(get_register(reg1), data);
				break;
			case 3:
				printf("OPCODE 3");
				store_register(get_register(reg1), data);
				break;
			case 4:
				printf("OPCODE 4 : Load");
				load_register(get_register(reg1), data);
				break;
		}
//	}
}
