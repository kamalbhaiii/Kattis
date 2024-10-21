// Problem name: Knitpicking
// Solved by: Kamal

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6005+5;
typedef pair<int,int> PII;
const int Max = 0x3f3f3f3f3f3f3f3f;
const int Min = -0x3f3f3f3f3f3f3f3f;
int n, m, k;
int T;
unordered_map<string, int>mp;
int v[N][3];
int cnt = 0;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        string s1, s2;
        int x;
        cin >> s1 >> s2 >> x;
        if(mp[s1]==0) mp[s1] = ++cnt;
        int tt = mp[s1];
        if(s2=="any") v[tt][0] = x;
        else if(s2=="left") v[tt][1] = x;
        else v[tt][2] = x;
    }
    int f = 0;
    for(int i = 1; i <= cnt; i ++)
    {
        if(v[i][0]>=2||(v[i][0]&&(v[i][1]||v[i][2]))||(v[i][1]&&v[i][2]))
        {
            f = 1;
            break;
        }
    }
    if(f==0)
    {
        cout << "impossible\n";
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= cnt; i ++)
    {
        if(v[i][0]&&!v[i][1]&&!v[i][2])
        {
            ans ++;
        }
        else if(v[i][1]||v[i][2])
        {
            ans += max(v[i][1], v[i][2]);
        }
    }
    cout << ans + 1 << '\n';
    return 0;
}
