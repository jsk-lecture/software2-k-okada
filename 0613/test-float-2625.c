#include <stdio.h>

int print_bit (float f) {
  int i;
  unsigned int *j = ((unsigned int *)&f);
  unsigned int s = *j;
  for (i = 0; i < 32; i++) {
    printf("%c", ((0x80000000)&s)?'1':'0');
    if ( (i == 0) || (i == 8) ) printf(" ");
    s = s << 1;
  }
  printf("\n");
}

int main (int argc, char* argv[]) {
  float f; // 32bit, 4byte

  f = 2.625;
  printf("f = %-12f : ", f);
  print_bit(f);

  float g;
  g = 2625000.0;
  printf("g = %-12f : ", g);
  print_bit(g);

  float h = f + g;
  printf("h = %-12f : ", h);
  print_bit(h);
}
