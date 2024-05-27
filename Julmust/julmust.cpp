// Problem name: Julmust
// Solved by: Kamal

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define el "\n"
#define nl cout << "\n"
#define stp setprecision
#define fixed_stp fixed << setprecision
#define vec_print(v) for (auto itr:v) cout << itr << " "; nl;
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pi 2 * acos(0.0)
#define all(a) a.begin(), a.end()
ll const Mod = 1e18;
const ll N = 1000000000 + 7;

int main() {
    fio;
    int t = 1;
    while (t--) {

        string s;
        ll low = 1, high, day = 0;

        cin >> high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            day++;

            cout << mid * day << el << std::flush;

            cin >> s;

            if (s == "less") high = mid - 1;
            else if (s == "more") low = mid + 1;
            else return 0;
        }
    }

    return 0;
}