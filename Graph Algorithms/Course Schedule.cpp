#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, avail[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        S[v].push_back(u);
    }
}
 
void visit(int u) {
    avail[u] = 1;
    for(int v : S[u]) {
        if (!avail[v]) visit(v);
        else if (avail[v] == 1) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
    avail[u] = 2;
}
 
void Print(int u) {
    if (!avail[u]) return;
    avail[u] = 0;
    for(int v : S[u]) Print(v);
    cout << u << ' ';
}
 
void Process() {
    for(int i=1; i<=n; ++i)
        if (!avail[i]) visit(i);
    for(int i=1; i<=n; ++i) Print(i);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
