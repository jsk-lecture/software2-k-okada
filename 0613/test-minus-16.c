/* test-minus.c */
#include <stdio.h>

int print_bit_8 (unsigned char s) {
  int i;
  printf("0x%02x : ", s);
  for (i = 0; i < 8; i++) {
    printf("%c", ((0x80)&s)?'1':'0');
    s = s << 1;
  }
  printf("\n");
}

int print_bit_16 (unsigned short s) {
  int i;
  printf("0x%04x : ", s);
  for (i = 0; i < 16; i++) {
    printf("%c", ((0x8000)&s)?'1':'0');
    s = s << 1;
  }
  printf("\n");
}

int main (int argc, char* argv[]) {
  int i;
  unsigned char u1, u2, u3;
  u1 = 36;
  printf("u1 = "); print_bit_8(u1);
  printf("u1 = %d\n", u1);
  // 2's complement
  u2 = (0xff ^ u1) + 0x01;
  printf("u2 = "); print_bit_8(u2);
  printf("u2 = %d\n", u2);
  printf("u2 = %d\n", (char)u2);
  u3 = u1 + u2;
  printf("u3 = ");  print_bit_8(u3);

  unsigned short v1, v2, v3;
  v1 = 3636;
  printf("v1 = "); print_bit_16(v1);
  printf("v1 = %d\n", v1);
  // 2's complement
  v2 = (0xffff ^ v1) + 0x01;
  printf("v2 = "); print_bit_16(v2);
  printf("v2 = %d\n", v2);
  printf("v2 = %d\n", (short)v2);
  v3 = v1 + v2;
  printf("v3 = ");  print_bit_16(v3);
}
