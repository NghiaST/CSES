#include <iostream>
using namespace std;
const int N = 5005;
int n;
long long a[N], prf[N], mid[N][N], f[N][N], f2[N][N];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        prf[i] = prf[i-1] + a[i];
        mid[i][i+1] = i;
        if (i < n) f[i][i+1] = a[i] + a[i+1];
    }
    for(int i=3; i<=n; ++i)
    for(int j=i-2; j; --j) {
        int ans = mid[j][i-1];
        for(int w=mid[j][i-1]; w<=mid[j+1][i]; ++w)
        if (f[j][ans] + f[ans+1][i] > f[j][w] + f[w+1][i]) ans = w;
        mid[j][i] = ans;
        f[j][i] = prf[i] - prf[j-1] + f[j][ans] + f[ans+1][i];
    }
    cout << f[1][n] << '\n';
}
