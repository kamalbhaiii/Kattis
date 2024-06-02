// Problem name: Destination Unknown
// Solved by: Kamal

#include <bits/stdc++.h>
#define fst first
#define snd second
#define re register

using namespace std;

typedef pair<int, int> pii;
const int N = 2010, M = 1e5 + 10, K = 110, inf = 0x3f3f3f3f;
int T, n, m, p, s, ma, mb, val;
int arr[K];
int idx, h[N], ne[M], e[M], w[M];
int d[5][N];
bool vis[N];

int read() {
    int r = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        r = (r << 3) + (r << 1) + (c ^ 48);
        c = getchar();
    }
    return r * w;
}

inline void add(int a, int b, int c) {
    ne[idx] = h[a];
    e[idx] = b;
    w[idx] = c;
    h[a] = idx++;
}

inline void dijkstra(int st, int d[]) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[st] = 0;
    q.push({0, st});
    while (!q.empty()) {
        pii t = q.top();
        q.pop();
        if (vis[t.snd]) continue;
        vis[t.snd] = true;
        for (re int i = h[t.snd]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > t.fst + w[i]) {
                d[j] = t.fst + w[i];
                q.push({d[j], j});
            }
        }
    }
}

int main() {
    T = read();
    while (T--) {
        idx = 0;
        memset(h, -1, sizeof(h));
        for (int i = 0; i < 5; i++) fill(d[i], d[i] + N, inf);
        vector<int> ans;
        n = read();
        m = read();
        p = read();
        s = read();
        ma = read();
        mb = read();
        for (re int i = 1; i <= m; i++) {
            int a, b, c;
            a = read();
            b = read();
            c = read();
            if ((a == ma && b == mb) || (a == mb && b == ma)) val = c;
            add(a, b, c);
            add(b, a, c);
        }
        for (re int i = 1; i <= p; i++) arr[i] = read();
        memset(vis, false, sizeof(vis));
        dijkstra(s, d[1]);
        memset(vis, false, sizeof(vis));
        dijkstra(ma, d[2]);
        memset(vis, false, sizeof(vis));
        dijkstra(mb, d[3]);
        for (re int i = 1; i <= p; i++) {
            int f = arr[i];
            if (d[1][f] == d[1][ma] + val + d[3][f] || d[1][f] == d[1][mb] + val + d[2][f]) ans.push_back(f);
        }
        sort(ans.begin(), ans.end());
        for (auto u : ans) printf("%d ", u);
        puts("");
    }
    return 0;
}