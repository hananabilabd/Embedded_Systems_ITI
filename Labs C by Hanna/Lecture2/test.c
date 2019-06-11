#include <stdio.h>

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

int main(void) {
  unsigned char f ;
  f = -1;
  printf("f= %d\n", f);
  if (f == -1){
    printf("hello\n");}

}
