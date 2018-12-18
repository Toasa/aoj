#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
using namespace std;

void make_koch(double ans[10], double p1[2], double p2[2]) {
  double a_x, a_y, b_x, b_y, c_x, c_y;
  double div3_x = abs((p2[0] - p1[0])) / 3;
  double div3_y = abs((p2[1] - p1[1])) / 3;

  a_x = p1[0] + div3_x;
  a_y = p1[1] + div3_y;
  c_x = p1[0] + div3_x * 2;
  c_y = p1[1] + div3_y * 2;
  // divide root 3 _ x, y
  double dr3_x, dr3_y;
  dr3_x = p1[0] + (div3_x * sqrt(3));
  dr3_y = p1[1] + (div3_y * sqrt(3));
  b_x = ((dr3_x * sqrt(3)) - dr3_y) / 2;
  b_y = (dr3_x + (sqrt(3) * dr3_y)) / 2;

  ans[0] = p1[0], ans[1] = p1[1];
  ans[2] = a_x, ans[3] = a_y;
  ans[4] = b_x, ans[5] = b_y;
  ans[6] = c_x, ans[7] = c_y;
  ans[8] = p2[0], ans[9] = p2[1];
}

void disp(double ans[10]) {
  cout << fixed;
  for (int i = 0; i < 10; i += 2) {
	cout << setprecision(8) << ans[i] << " " << ans[i + 1] << endl;
  }
}

void solve(double p1[2], double p2[2], int n) {
  double ans[10];
  make_koch(ans, p1, p2);
  if (n > 1) {
	n--;
	for (int i = 0; i < 8; i += 2) {
	  double s1[2];
	  double s2[2];
	  s1[0] = ans[i], s1[1] = ans[i + 1];
	  s2[0] = ans[i + 2], s2[1] = ans[i + 3];
	  solve(s1, s2, n);
	}
  } else if (n == 1) {
	disp(ans);
  }
}

int main() {
  int n;
  cin >> n;

  double p1[2] = {0, 0};
  double p2[2] = {100, 0};
  if (n == 0) {
	cout << fixed;
	cout << setprecision(8) << p1[0] << " " << p1[1] << endl;
	cout << setprecision(8) << p2[0] << " " << p2[1] << endl;
	return 0;
  }

  // solve(p1, p2, n);

  double s1[2] = {33.33333333, 0.00000000};
  double s2[2] = {50.00000000, 28.86751346};
  double ans[10];
  make_koch(ans, s1, s2);
  disp(ans);

  return 0;
}
