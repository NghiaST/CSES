#include <iostream>
#include <queue>
using namespace std;
const int N = 105;
int n, cnt, res, a[N][N], nxt[N], prv[N], avail[N], pL[N], pR[N];
queue<int> Q;
string s;
 
bool Match(int u) {
    for(int v=1; v<=n; ++v) if (a[u][v] && !prv[v]) {
        nxt[u] = v;
        prv[v] = u;
        return true;
    }
    for(int v=1; v<=n; ++v) if (a[u][v] && avail[v] != cnt) {
        avail[v] = cnt;
        if (Match(prv[v])) {
            nxt[u] = v;
            prv[v] = u;
            return true;
        }
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> s;
        for(int j=0; j<n; ++j) a[i+1][j+1] = (s[j] == 'o');
    }
    for(int i=1; i<=n; ++i) ++cnt, Match(i);
    for(int i=1; i<=n; ++i) {
        if (!nxt[i]) Q.push(i), pL[i] = -1;
        if (!prv[i]) Q.push(-i), pR[i] = -1;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u > 0) {
            for(int v=1; v<=n; ++v) if (a[u][v] && !pR[v]) {
                pR[v] = u;
                if (prv[v] && !pL[prv[v]]) {
                    pL[prv[v]] = -1;
                    Q.push(prv[v]);
                }
            }
        }
        else {
            u = -u;
            for(int v=1; v<=n; ++v) if (a[v][u] && !pL[v]) {
                pL[v] = u;
                if (nxt[v] && !pR[nxt[v]]) {
                    pR[nxt[v]] = -1;
                    Q.push(-nxt[v]);
                }
            }
        }
    }
    for(int i=1; i<=n; ++i) if (!pL[i]) {
        pL[i] = nxt[i];
        pR[nxt[i]] = -1;
    }
    for(int i=1; i<=n; ++i) {
        if (pL[i] > 0) ++res;
        if (pR[i] > 0) ++res;
    }
    cout << res << '\n';
 
    for(int i=1; i<=n; ++i) {
        if (pL[i] > 0) cout << 1 << ' ' << i << '\n';
        if (pR[i] > 0) cout << 2 << ' ' << i << '\n';
    }
}
