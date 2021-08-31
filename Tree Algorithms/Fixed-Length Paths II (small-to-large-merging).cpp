/// small-to-large-merging
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int N = 200005;
int n, k1, k2;
long long res;
vector<int> S[N];
 
long long suffix(deque<long long> &a, int x) {
    if (x < 0) return a[0];
    if (x >= a.size()) return 0;
    return a[x];
}
 
void Merge(deque<long long> &a, deque<long long> &b) {
    if (a.size() < b.size()) a.swap(b);
    for(int i=0; i<b.size(); ++i) {
        long long cnt = b[i] - (i+1==b.size() ? 0 : b[i+1]);
        res += cnt * (suffix(a, k1 - i) - suffix(a, k2 - i + 1));
    }
    for(int i=0; i<b.size(); ++i) a[i] += b[i];
}
 
deque<long long> dfs(int u, int d) {
    deque<long long> cntU{1};
    for(int v : S[u]) if (v != d) {
        deque<long long> cntV = dfs(v, u);
        cntV.push_front(cntV.front());
        Merge(cntU, cntV);
    }
    return cntU;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k1 >> k2;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    dfs(1, 0);
    cout << res;
}
