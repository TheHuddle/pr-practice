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

int strlen(char* s) {
  int n = 0;
  char* s_ptr = s;
  while (*(s_ptr++)) { 
    n++;
  }
  return n;
}

void kernel(void) {
  uint16_t* vgamem = (uint16_t*) 0xB8000;
  uint16_t vgacolors[6] = {WHITE | RED << 4, WHITE | GREEN << 4, WHITE | BLUE << 4, BLACK | RED << 4, BLACK | GREEN << 4, BLACK | BLUE << 4};
  char* s = "Hello world!";
  int i,j,k;
  for (k = 0; k >= 0; ++k) {
    k = (k % 5);
    j = 0;
    while (j < 100000000) { j++; } // Since we don't have an interrupt descriptor table we can't use the PIC; this emulates "sleeping"
    for (i = 0; i < WIDTH*HEIGHT; i++) {
      vgamem[i] = s[i % strlen(s)] | vgacolors[(i+k) % 6] << 8;
    }
  }
}
