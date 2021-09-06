#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, x, r;
pair<int,int> L[200005];
vector<pair<int,int>> Ans;
priority_queue<pair<int,int>> Q;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        if (x > 0) Q.push({x, i});
    }
    while (!Q.empty()) {
        pair<int,int> w = Q.top(); Q.pop();
        while (!Q.empty() && w.first--) {
            L[++r] = Q.top(); Q.pop();
            --L[r].first;
            Ans.emplace_back(w.second, L[r].second);
        }
        if (w.first > 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        while (r) {
            if (L[r].first) Q.push(L[r]);
            --r;
        }
    }
    cout << Ans.size() << '\n';
    for(pair<int,int> v : Ans) cout << v.first << ' ' << v.second << '\n';
}
