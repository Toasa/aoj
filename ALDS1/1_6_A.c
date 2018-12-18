#include <stdio.h>

static int *A;

void counting_sort(A, B, k){
  for (int i = 0; i < k; i++)
	C[i] = 0;
  for (int j = 1; j < strlen(A); j++)
	C[A[j]] = C[A[j]] + 1;

  /* C[i] now contains the number of elements equal to i */
  for (int i = 1; i < k; i++) 
	C[i] = C[i] + C[i - 1];
  /* C[i] now contains the number of elements less than or equal to i */
  for (int j = strlen(A); 0 < j; j--) {
	B[C[A[j]]] = A[j];
	C[A[j]] = C[A[j]] - 1;
  }
}

int main() {
  counting_sort(A, B, 10000);
