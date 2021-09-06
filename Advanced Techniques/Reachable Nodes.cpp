#include <iostream>
#include <vector>
using namespace std;
const int N = 50005;
int n, m, block, vs[N];
unsigned long long f[N][790];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v; --u, --v;
        S[u].push_back(v);
    }
}
 
void visit(int u) {
    f[u][u >> 6] = 1LL << (u % 64);
    vs[u] = true;
    for(int v : S[u]) {
        if (!vs[v]) visit(v);
        for(int i=0; i<block; ++i) f[u][i] |= f[v][i];
    }
}
 
void Process() {
    block = (n + 63) >> 6;
    for(int i=0; i<n; ++i) if (!vs[i]) visit(i);
    for(int i=0; i<n; ++i) {
        int w = 0;
        for(int j=0; j<block; ++j) w += __builtin_popcountll(f[i][j]);
        cout << w << ' ';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
