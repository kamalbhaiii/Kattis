// Problem name: NOP
// Solved by: Kamal

#include <bits/stdc++.h>

using namespace std;

void nop() {
  string s;
  cin >> s;
  int i = 0, ans = 0;

  while (i < s.size()) {
    int j = i + 1;

    while (j < s.size() && 'a' <= s[j] && s[j] <= 'z') {j++;}

    if (j != s.size() && (j - i) % 4 != 0) {
      ans += 4 - ((j - i) %  4);
    }

    i = j;
  }

  cout << ans;

}

int main() {
  ios::sync_with_stdio(false);
  nop();
  return 0;
}
