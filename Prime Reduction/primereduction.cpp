// Problem name: Prime Reduction
// Solved by: Kamal

#include<bits/stdc++.h>
using namespace std;
pair<int, int> ans(int k) {
    bool prime = true; int s = 0;
    while (k != 1) {
        bool t = true;
        for (int i =2; i <= k / i; i++) {
            if (k % i == 0) {
                prime = false; t = false;
                while (k % i == 0) {s += i; k /= i;}
            }
        }
        if (t) {s += k; break; }
    }
    if (prime) return {k, 1};
    pair<int, int> r = ans(s);
    return {r.first, r.second + 1};
}

int main() {
    int x; while (cin >> x) {
        if (x == 4) return 0;
        pair<int, int> l = ans(x);
        cout << l.first << ' ' << l.second << '\n';
    }
}
