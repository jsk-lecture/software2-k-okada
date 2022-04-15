#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

int Debug = FALSE;

int fact (int x) {
  if (x > 0) {
    if ( Debug ) {
      printf("x = %d\n", x);
    }
    return ( x * fact (x - 1) );
  } else {
    if ( Debug ) {
      printf("x = %d, return 1\n", x);
    }
    return 1;
  }
}

int main (int argc, char *argv[]) {
  int c, x, ret;
  while ((c = getopt(argc, argv, "d")) != -1) {
    switch (c)
    {
      case 'd':
        Debug = TRUE;
        break;
      default:
        break;
    }
  }
  x = atoi(argv[optind]);
  ret = fact(x);
  printf("ret = %d\n", ret);
}
