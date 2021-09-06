#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, u, v, res, dad[100005];
 
int DAD(int u) {
    if (dad[u]) return dad[u] = DAD(dad[u]);
    return u;
}
 
bool Union(int u, int v) {
    u = DAD(u);
    v = DAD(v);
    if (u == v) return 0;
    dad[u] = v;
    return 1;
}
 
int main()
{
    cin >> n >> m;
    res = 1;
    while (m--) {
        cin >> u >> v;
        if (!Union(u, v)) (res *= 2) %= MOD;
    }
    cout << res;
}
