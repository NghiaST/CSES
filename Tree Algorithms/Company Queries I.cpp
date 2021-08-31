#include <iostream>
#include <vector>
using namespace std;
int n, q, pa[200005][20];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int u, v, x, k;
    for(int i=2; i<=n; ++i) cin >> pa[i][0];
    for(int i=1; i<20; ++i)
        for(int j=1; j<=n; ++j) pa[j][i] = pa[pa[j][i-1]][i-1];
    while (q--) {
        cin >> x >> k;
        for(int i=0; i<20; ++i) if ((k>>i)&1) x = pa[x][i];
        if (x == 0) x = -1;
        cout << x << '\n';
    }
}
