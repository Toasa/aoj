#include <stdio.h>

static int *A;

void print(int *A, int n) {
  for (int i = 0; i < n; i++)
	printf((i == n - 1 ? "%d\n" : "%d "), *(A + i));
}

void insertion_sort(int *A, int n) {
  for (int i = 1; i < n; i++) {
	int val = A[i];
	int j = i - 1;
	while (0 <= j && val < A[j]) {
	  A[j + 1] = A[j];
	  j--;
	}
	A[j + 1] = val;
	print(A, n);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++)
	scanf("%d", A + i);

  print(A, n);
  insertion_sort(A, n);

  return 0;
}
