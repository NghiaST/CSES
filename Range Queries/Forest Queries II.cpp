#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, q, a[N][N], f[N][N], bit[N][N];
string s;
 
void update(int x, int y, int val) {
    for(int p; x<=n; x+=x&-x)
        for(p=y; p<=n; p+=p&-p) bit[x][p] += val;
}
 
int query(int x, int y) {
    int val = f[x][y];
    for(int p; x; x-=x&-x)
        for(p=y; p; p-=p&-p) val += bit[x][p];
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        cin >> s;
        for(int j=1; j<=n; ++j) {
            a[i][j] = (s[j-1] == '*' ? 1 : -1);
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (a[i][j] > 0);
        }
    }
    int type, xa, ya, xb, yb;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> xa >> ya;
            a[xa][ya] = -a[xa][ya];
            update(xa, ya, a[xa][ya]);
        }
        else {
            cin >> xa >> ya >> xb >> yb;
            cout << query(xb, yb) - query(xa-1, yb) - query(xb, ya-1) + query(xa-1, ya-1) << '\n';
        }
    }
}
