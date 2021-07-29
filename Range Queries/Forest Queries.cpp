#include <iostream>
using namespace std;
int n, q, xa, xb, ya, yb, f[1005][1005];
string s;
 
int main()
{
    scanf("%d%d\n", &n, &q);
    for(int i=1; i<=n; ++i) {
        getline(cin, s);
        for(int j=1; j<=n; ++j) f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (s[j-1] == '*');
    }
    while (q--) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        cout << f[xb][yb] - f[xa-1][yb] - f[xb][ya-1] + f[xa-1][ya-1] << '\n';
    }
}
