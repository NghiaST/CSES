#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 505, M = 1005;
int n, m, k, res, label[N], f[N], trace[N], U[M], V[M], choice[M];
vector<int> S[N], S2[N], Ans;
 
void Enter() {
    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) {
        cin >> U[i] >> V[i];
        S[U[i]].push_back(i);
        S[V[i]].push_back(-i);
    }
}
 
bool FindPath() {
    fill(f+1, f+n+1, 0x3c3c3c3c);
    fill(trace+1, trace+n+1, 0);
    #define pii pair<int,int>
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    f[1] = 0;
    Q.emplace(0, 1);
    int u, v, w;
    while (!Q.empty()) {
        w = Q.top().first;
        u = Q.top().second; Q.pop();
        if (w != f[u]) continue;
        if (u == n) return true;
        for(int eg : S[u]) {
            if (eg > 0) {
                v = V[eg];
                int W = f[u] + label[u] - label[v] + 1;
                if (!choice[eg] && f[v] > W) {
                    f[v] = W;
                    trace[v] = eg;
                    Q.emplace(f[v], v);
                }
            }
            else {
                v = U[-eg];
                int W = f[u] + label[u] - label[v] - 1;
                if (choice[-eg] && f[v] > W) {
                    f[v] = W;
                    trace[v] = eg;
                    Q.emplace(f[v], v);
                }
            }
        }
    }
    return false;
}
 
void IncFlow() {
    int v = n;
    while (v != 1) {
        int eg = trace[v];
        if (eg > 0) {
            ++choice[eg];
            v = U[eg];
            ++res;
        }
        else {
            --choice[-eg];
            v = V[-eg];
            --res;
        }
    }
}
 
void Process() {
    for(int i=1; i<=k; ++i) {
        if (!FindPath()) {
            cout << -1;
            exit(0);
        }
        IncFlow();
        for(int i=1; i<=n; ++i) if (f[i] != 1e9)
            label[i] += f[i];
    }
}
 
void Print() {
    cout << res << '\n';
    for(int i=1; i<=m; ++i) if (choice[i]) S2[U[i]].push_back(V[i]);
    for(int i=1; i<=k; ++i) {
        Ans.clear();
        int u = 1, v;
        while (u != n) {
            Ans.push_back(u);
            v = S2[u].back(); S2[u].pop_back();
            u = v;
        }
        Ans.push_back(n);
        cout << Ans.size() << '\n';
        for(int v : Ans) cout << v << ' ';
        cout << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
    Print();
}
