#include <functional>
#include <iostream>

std::function<int(int &a, int &b)> r = [](int a, int b) {
  return a += b;
};

signed main(void) {
  int a = 50, b = 90;
  std::cout << r(a, b);
  std::cout << "\n" << a << " " << b;
  return 0;
}

