#pragma once
#include <stdio.h>
#include <stdint.h>

#define OPEN_BRACKET {
#define CLOSE_BRACKET }
#define OPEN_PAREN (
#define CLOSE_PAREN )
#define OPEN_SQUARE [
#define CLOSE_SQUARE ]
#define STAR *
#define ASSIGN =
#define SEMICOLON ;
#define COMMENT(ignore)
#define ZERO 0
#define COMMA ,

extern uint_fast16_t memory[256];
extern uint_fast16_t reg0,
					regA,
					regB,
					regC,
					regProg,
					regInt,
					regData;

extern void initialize_machine();
extern uint_fast16_t* get_register(uint_fast16_t reg);

/* SET
	000 RRR DDDDDDDD
	Sets the data in register RRR*/
extern void set_data_on_register(uint_fast16_t *reg, uint_fast16_t data);

/* ADD
	001 AAA BBB -----
	Adds register BBB into register AAA*/
extern void add_registers(uint_fast16_t *regA, uint_fast16_t *regB);

/* ADDI
	010 RRR --------
	Adds a value to register RRR */
extern void add_value(uint_fast16_t *reg, uint_fast16_t data);
/* STORE Register
	011 RRR AAAAAAAA
	Stores the value of a register in address AAAAAAAA */
extern void store_register(uint_fast16_t *reg, uint_fast16_t address);
/* LOAD Register
	100 RRR AAAAAAAA */
extern void load_register(uint_fast16_t *reg, uint_fast16_t address);
/* Call Interrupt 
	101 RRR AAAAAAAA */
extern void interrupt();
extern void printerrupt(uint_fast16_t address);
/* JMP
	110 --- AAAAAAAA 
	Moves program pointer to AAAAAAAA*/
extern void jmp(uint_fast16_t address);
/* HALT
	111 --- -------- */


/* ========================================== */
extern void run_program();
