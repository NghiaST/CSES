#include <iostream>
using namespace std;
int n, q, x, y, ans, p[1000005][21];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        cin >> x >> y;
        p[y][0] = max(p[y][0], x);
    }
 
    for(int i=1; i<=1000000; ++i) p[i][0] = max(p[i][0], p[i-1][0]);
    for(int j=1; j<=20; ++j)
        for(int i=1; i<=1000000; ++i)
            p[i][j] = p[p[i][j-1]][j-1];
 
    while (q--) {
        ans = 0;
        cin >> x >> y;
        for(int i=20; i>=0; --i) if (p[y][i] >= x) {
            ans += 1<<i;
            y = p[y][i];
        }
        cout << ans << '\n';
    }
}
