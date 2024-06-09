// Problem name: GREAT + SWERC = PORTO
// Solved by: Kamal
// Judgement Pending

#include <bits/stdc++.h>

#define P(X) cout<<"db "<<X<<endl;
#define P2(X, Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3 (X,Y,Z) cout<<"d3 "<<x<<" "<<Y<<" "<<Z<<endl;
#define SQ(x) ((x) * (x))
#define ll long long
#define pii pair<int, int>
#define bchk (n,i) (bool) (n& (1<<i))
#define bon (n,i) (n | (1<<i))
#define boff (n,i) n=n&(~(1<<i))

#define distance (a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define MAX3 (a,b,c) max (a,max(b,c))
#define MS (XX, YY) memset(XX, YY, sizeof(XX));
#define FastIO ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define eps 10e-9
#define MX 1000005
#define MD 1000000007

using namespace std;

ll m,n;
char sr[11][12];
bool av[150]={0}, fc[150]={0};
int val[150];
vector<char> chrs;
int prm[12];
ll getV(int id) {
    ll v=0;
    for (int i=0; sr[id][i]; i++) {
        v = v * 10 + val[sr[id][i]];
    }
    return v;
}

bool chk(){
    ll sum = getV (n);
    for (int i=0; i<n;i++) {
        sum-=getV(i);
        if (sum<0) return false;
    }
    return sum==0;
}

int main() {
    ll i,j,test=1,cas=0;
    ll a,b;
    #ifndef ONLINE_JUDGE
    //freopen("test.txt","r", stdin);
    #endif
    int ln;
    scanf("%lld", &n);

    for (i=0;i<n;i++) {
        scanf("%s", sr[i]);
        fc[sr[i][0]]=1;
        ln=strlen(sr[i]);
        for(j=0; sr[i][j];j++) {
            av[sr[i][j]]=1;
        }   
        //reverse(sr[i], sr[i]+ln);
    }
    n--;
    for (i='A'; i <= 'Z' ;i++) {
        if (av[i]) chrs.push_back(i);
    }

    for (i=0;i<10;i++) prm[i] = i;
    int res=0,f,cng=0;
    do {
        f=0;
        cng=0;
        for (i=0;i<chrs.size(); i++) {
            if (val [chrs[i]] != prm[i]) cng++;
            val[chrs[i]] = prm[i];
            if (fc[chrs[i]] &&val [chrs[i]]==0) {
                f=1;
                break;
            }
        }
        if(f==0&&cng!=0&&chk()) res++;
    } 
    while (next_permutation (prm, prm+10));
    printf("%d\n", res);
    return 0;
}