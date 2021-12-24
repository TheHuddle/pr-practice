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
#define INCREMENT(X) X++

extern uint_fast16_t memory OPEN_SQUARE 256 CLOSE_SQUARE SEMICOLON
extern uint_fast16_t reg0 COMMA
					regA COMMA
					regB COMMA
					regC COMMA
					regProg COMMA
					regInt COMMA
					regData SEMICOLON

extern void initialize_machine OPEN_PAREN CLOSE_PAREN SEMICOLON
extern uint_fast16_t STAR get_register OPEN_PAREN uint_fast16_t reg CLOSE_PAREN SEMICOLON

/* SET
	000 RRR DDDDDDDD
	Sets the data in register RRR*/
extern void set_data_on_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t data CLOSE_PAREN SEMICOLON

/* ADD
	001 AAA BBB -----
	Adds register BBB into register AAA*/
extern void add_registers OPEN_PAREN uint_fast16_t STAR regA COMMA uint_fast16_t STAR regB CLOSE_PAREN SEMICOLON

/* ADDI
	010 RRR --------
	Adds a value to register RRR */
extern void add_value OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t data CLOSE_PAREN SEMICOLON

/* STORE Register
	011 RRR AAAAAAAA
	Stores the value of a register in address AAAAAAAA */
extern void store_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t address CLOSE_PAREN SEMICOLON

/* LOAD Register
	100 RRR AAAAAAAA */
extern void load_register OPEN_PAREN uint_fast16_t STAR reg COMMA uint_fast16_t address CLOSE_PAREN SEMICOLON

/* Call Interrupt 
	101 RRR AAAAAAAA */
extern void interrupt OPEN_PAREN CLOSE_PAREN SEMICOLON
extern void printerrupt OPEN_PAREN uint_fast16_t address CLOSE_PAREN SEMICOLON
extern void printerrupt OPEN_PAREN uint_fast16_t address CLOSE_PAREN SEMICOLON

/* JMP
	110 --- AAAAAAAA 
	Moves program pointer to AAAAAAAA*/
extern void jmp OPEN_PAREN uint_fast16_t address CLOSE_PAREN SEMICOLON

/* HALT
	111 --- -------- */


/* ========================================== */
extern void run_program OPEN_PAREN CLOSE_PAREN;
