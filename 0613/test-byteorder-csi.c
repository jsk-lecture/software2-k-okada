// test-byteorder.c
#include <stdio.h>

int print_byte_32 (unsigned int s) {
  int i;
  unsigned char *p;
  p = (unsigned char*)&s;
  for (i=0;i<sizeof(unsigned int);i++) {
    printf("%02x", *p);
    p++;
  }
  printf("\n");
}

int print_byte_16 (unsigned short s) {
  int i;
  unsigned char *p;
  p = (unsigned char*)&s;
  for (i=0;i<sizeof(unsigned short);i++) {
    printf("%02x", *p);
    p++;
  }
  printf("\n");
}

int print_byte_8 (unsigned char s) {
  int i;
  unsigned char *p;
  p = (unsigned char*)&s;
  for (i=0;i<sizeof(unsigned char);i++) {
    printf("%02x", *p);
    p++;
  }
  printf("\n");
}

int main (int argc, char* argv[]) {
  unsigned int   u1; // 32bit, 4byte
  unsigned short v1; // 16bit, 2byte
  unsigned char  w1; // 8bit, 1byte

  printf("sizeof(int)   = %ld\n", sizeof(int));
  printf("sizeof(short) = %ld\n", sizeof(short));
  printf("sizeof(char)  = %ld\n", sizeof(char));

  u1 = 0x1234abcd;
  printf("u1 = %x : ", u1);
  print_byte_32(u1);

  v1 = 0x12ab;
  printf("v1 = %x : ", v1);
  print_byte_16(v1);

  w1 = 0x1a;
  printf("w1 = %x : ", w1);
  print_byte_8(w1);
}
