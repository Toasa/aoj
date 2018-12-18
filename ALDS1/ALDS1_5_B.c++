#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

void Merge(vector<int> &A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1 + 1);
  vector<int> R(n2 + 1);
  for (int i = 0; i < n1; i++) {
	L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
	R[i] = A[mid + i];
  }
  L[n1] = 99999;
  R[n2] = 99999;
  int i = 0;
  int j = 0;

  for (int k = left; k < right - 1; k++) {
	if (L[i] <= R[j]) {
	  A[k] = L[i];
	  i++;
	} else {
	  A[k] = R[j];
	  j++;
	}
  }
}


void Merge_Sort(vector<int> &A, int left, int right) {
  if (left + 1 < right) {
	int mid = (left + right) / 2;
	Merge_Sort(A, left, mid);
	Merge_Sort(A, mid, right);
	Merge(A, left, mid, right);
  }
}
 
int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (int i = 0; i < n; i++) {
	cin >> A[i];
  }

  Merge_Sort(A, 0, n);

  for (int i = 0; i < n; i++) {
	cout << A[i] << endl;
  }
}
