#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(3);
  v[0] = 1;
  v[1] =99;
  v[2] = 4;
  for (int i=0; i < 3; i++)
	cout << v[i] << endl;
}
