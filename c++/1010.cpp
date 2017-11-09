#include <bits/stdc++.h>
using namespace std;
bool flower(int n) {
  if (n < 100 || n > 999) return false;
  int a = n / 100;
  int b = n % 100 / 10;
  int c = n % 10;
  return a * a * a + b * b * b + c * c * c == n;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << flower(n) << endl;
  return 0;
}