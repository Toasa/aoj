#include <iostream>

using namespace std;

void add(int &n) {
  n += 3;
}

int main() {
  int a = 7;
  add(a);
  
  cout << a << endl;
}
