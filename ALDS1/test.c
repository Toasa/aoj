#include <stdio.h>
#include <stdlib.h>

static int a;

void print() {
  printf("%d\n", a);
}

int main() {
  a = 5;
  print();
} 
