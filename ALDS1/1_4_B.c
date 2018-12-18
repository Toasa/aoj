#include <stdio.h>

int bi_search(int *S, int val, int min, int max) {
  while (min < max) {
	int mid = (min + max) / 2;
	if (S[mid] == val)
	  return 1;
	else if (val < S[mid])
	  max = mid;
	else
	  min = mid + 1;
  }
  return 0;
}

int main() {
  int n, q;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; i++) {
	scanf("%d", S + i);
  }

  scanf("%d", &q);
  int T[q];
  int count = 0;
  for (int i = 0; i < q; i++) {
	scanf("%d", T + i);
  }

  for (int i = 0; i < q; i++) {
	if (bi_search(S, T[i], 0, n))
	  //if (bi_search(S, T[i], 0, n - 1))
	  count++;
  }

  printf("%d\n", count);
}
