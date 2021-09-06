#include <iostream>
#include <deque>
using namespace std;
const int N = 105;
int n, m, h[N], s[N], k[N], f[N][100005];
deque<int> Q;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> h[i];
    for(int i=1; i<=n; ++i) cin >> s[i];
    for(int i=1; i<=n; ++i) cin >> k[i];
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<h[i]; ++j) {
            while (!Q.empty()) Q.pop_back();
            for(int w=j; w<=m; w+=h[i]) {
                while (!Q.empty() && f[i-1][Q.back()] + (w - Q.back()) / h[i] * s[i] < f[i-1][w]) Q.pop_back();
                while (!Q.empty() && (w - Q.front()) / h[i] > k[i]) Q.pop_front();
                Q.push_back(w);
                int v = Q.front();
                f[i][w] = f[i-1][Q.front()] + (w - Q.front()) / h[i] * s[i];
            }
        }
    }
    cout << f[n][m];
}
