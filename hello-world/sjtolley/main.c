#include <stdio.h>

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

int main OPEN_PAREN int argc COMMA char STAR STAR argv CLOSE_PAREN OPEN_BRACKET
	char phrase OPEN_SQUARE CLOSE_SQUARE ASSIGN OPEN_BRACKET 'h' COMMA 'e' COMMA 'l' COMMA 'l' COMMA
		'o' COMMA ',' COMMA ' ' COMMA 'w' COMMA 'o' COMMA 'r' COMMA 'l' COMMA 'd' COMMA '.' COMMA 0 CLOSE_BRACKET SEMICOLON
	char STAR word ASSIGN phrase SEMICOLON
	puts OPEN_PAREN word CLOSE_PAREN SEMICOLON
	return ZERO;
CLOSE_BRACKET
