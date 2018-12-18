#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calc(char *str, int t1, int t2) {
  double area = 0;
  int depth = 0;
  char *p = str;
  for (int i = t1; i < t2; i++) {
	if (*(p + i) == '\\') {
	  depth++;
	  area += depth - 0.5;
	} else if (*(p + i) == '/') {
	  depth--;
	  area += depth + 0.5;
	} else if (*(p + i) == '_') {
	  area += depth;
	}
  }
  return area;
}

int main() {
  int depth = 0;
  char str[20000] = {0};
  scanf("%s", str);
  char *p = str;
  int *dep_arr = malloc(strlen(str));

  int i = 0;
  int highest = 0;
  for (; *p != '\0'; i++, p++) {
	if (*p == '\\') {
	  depth++;
	  dep_arr[i] = depth;
	} else if (*p == '/') {
	  depth--;
	  dep_arr[i] = depth;
	} else if (*p == '_') {
	  dep_arr[i] = depth;
	}
	if (highest > depth) {
	  highest = depth;
	}
  }
  dep_arr[i] = '\0';

  // double area = calc(str, 0, strlen(str));
  // printf("Area: %d\n", (int)area);
  printf("hight: %d\n", highest);

  return 0;
}
