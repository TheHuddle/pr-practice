#include <stddef.h>
#include <stdint.h>

#define WIDTH 80
#define HEIGHT 25

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define RED 4
#define MAGENTA 13
#define WHITE 15

void reset(uint16_t* vgamem) {
  vgamem = (uint16_t*) 0xB8000;
}

void kernel(void) {
  uint16_t* vgamem;
  reset(vgamem);
  uint16_t* vgacolors = WHITE | BLACK << 4;
  char* s = "Hello world!";
  do {
    *(vgamem++) = *s | vgacolor << 8;
  }
  while (*(s++)); 
}
