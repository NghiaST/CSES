#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, avail[N];
vector<int> S[N], Q;
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
    }
}
 
void visit(int u) {
    avail[u] = 1;
    Q.push_back(u);
    for(int v : S[u]) {
        if (!avail[v]) visit(v);
        else if (avail[v] == 1) {
            int lft = Q.size() - 2;
            while (Q[lft] != v) --lft;
            cout << Q.size() - lft + 1 << '\n';
            for(; lft < Q.size(); ++lft) cout << Q[lft] << ' ';
            cout << v;
            exit(0);
        }
    }
    avail[u] = 2;
    Q.pop_back();
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        if (!avail[i]) visit(i);
    cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
