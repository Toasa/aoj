#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *p; 

void push(int val, int top) {
  
}

int main() {
  char *p = malloc(sizeof(char) * 1000);
  int stack[100];
  int top = 0;

  scanf("%s", p);
  while (*p != '\0') {
	if (isdigit(*p)) {
	  int val = *p++;
	  while (isdigit(*p)) {
		val += 10 * val + *p++;
	  }
	  push(val, top);
	}
  }

}
