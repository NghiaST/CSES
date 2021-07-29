#include <iostream>
#include <vector>
#include <queue>
#define pii pair<long long,int>
using namespace std;
const long long N = 100005;
int n, m, k;
priority_queue<long long> f[N];
vector<pii> S[N];
vector<long long> Ans;
 
void Enter() {
    cin >> n >> m >> k;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
    }
}
 
void Process() {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.emplace(0, 1);
    f[1].push(1);
    while (!Q.empty()) {
        pii w = Q.top(); Q.pop();
        int u = w.second;
        long long cost = w.first;
        if (f[u].top() < cost) continue;
        for(pii eg : S[u]) {
            int v = eg.first;
            long long c = cost + eg.second;
            if (f[v].size() < k) {
                f[v].push(c);
                Q.emplace(c, v);
            }
            else if (f[v].top() > c) {
                f[v].pop();
                f[v].push(c);
                Q.emplace(c, v);
            }
        }
    }
    while (!f[n].empty()) {
        Ans.push_back(f[n].top());
        f[n].pop();
    }
    for(int i = k-1; i>=0; --i) cout << Ans[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
