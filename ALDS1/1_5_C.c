#include <stdio.h>

static int *A;

int merge(int *A, int left, int mid, int right) {
  static int count = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++)
	L[i] = A[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[mid + i];

  L[n1] = 999999999;
  R[n2] = 999999999;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
	  A[k] = L[i];
	  i++;
	} else {
	  A[k] = R[j];
	  j++;
	}
	count++;
  }
  return count;
}
	
int merge_sort(int *A, int left, int right){
  int count;
  if (left + 1 < right) {
	int mid = (left + right)/2;
	merge_sort(A, left, mid);
	merge_sort(A, mid, right);
	count = merge(A, left, mid, right);
  }
  return count;
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++) {
	printf((i != n - 1 ? "%d " : "%d\n"), *(A + i));
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
	scanf("%d", A + i);
  }

  int count = merge_sort(A, 0, n);

  print(A, n);
  printf("%d\n", count);

  return 0;
}
