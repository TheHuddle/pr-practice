#include <stdio.h>

#define OPEN_BRACKET {
#define CLOSE_BRACKET }
#define OPEN_PAREN (
#define CLOSE_PAREN )
#define OPEN_SQUARE
#define CLOSE_SQUARE
#define STAR *
#define ASSIGN =
#define SEMICOLON ;
#define COMMENT(ignore)
#define ZERO 0
#define COMMA ,

int main OPEN_PAREN int argc COMMA char STAR STAR argv CLOSE_PAREN OPEN_BRACKET
	char STAR word = "hello, world.";
	puts(word);
	return ZERO;
CLOSE_BRACKET
