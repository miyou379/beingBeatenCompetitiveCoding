#pragma GCC optimize(3)
#include <iostream>
#include <string>
#define endl "\n"
using str = std::basic_string<int>;
#define input(x) do{std::cin.get();for(int i=0;i<n;++i){char tmp;std::cin>>tmp;x+=tmp-'0';}}while(0)
#define output(x) for(int i=0;i<n;++i){std::cout<<x[i]<<" ";}

void Solution() {
  int n;
  std::cin >> n;
  str a, b;
  input(a);
  input(b);
  if (a == b) { std::cout << "Yes" << endl; return; }
  int i = 0, j = 0;
  while (i < n && !a[i]) ++i;
  while (j < n && !b[j]) ++j;
  if (i <= j) std::cout << "Yes" << endl;
  else std::cout << "No" << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  while (_T--) {
    Solution();
  }
  return 0;
}
