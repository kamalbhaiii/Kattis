// Problem name: Code Guessing
// Solved by: Kamal


#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define akemi_homura std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

#define int long long

const double pi = acos(-1);

const int mod = 1e9 + 7;

const int MOD = 998244353;

const int M = 1e5 + 5;

const int N = 20 + 5;

int n, m;

string s;

void _solve()

{

cin >> n >> m;

cin >> s;
if (n == 2 && m == 4 && s == "BABA"){
cout << "1 3" << endl;
return;

}



else if (n == 6 && m == 8 && s == "ABAB") {
cout << "7 9" << endl;
return;

}

else if (n == 2 && m == 8 && s == "BAAB")

{

cout << "1 9" << endl;
return;

}



else if (n == 3 && s == "BBAA") {
cout << "1 2" << endl;
return;

}



else if (m == 7 && s == "AABB"){
cout << "8 9" << endl;
return;

}

else if (s == "ABBA")

{



if (n == m - 3) {
    cout << n + 1 << ' ' << n + 2 << endl;
    return;
}

}


cout << -1 << endl;
return;



}


signed main()

{

akemi_homura;

int Case = 1;


while (Case--)

{

_solve();

}
return 0;
}