#include <iostream>
#include <iomanip>
using namespace std;
const long long N = 605, MOD = 1e9 + 7, INF = 0x3c3c3c3c;
int n, x, y;
long double f[N], f2[N];
 
int main()
{
    cin >> n >> x >> y;
    for(int i=0; i<=n*6; ++i) f[i] = 1e6;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=n*6; ++j) {
            f2[j] = f[j] / 6; f[j] = 0;
            if (j > 0) f[j] = f[j-1] + f2[j-1];
            if (j > 6) f[j] -= f2[j-7];
        }
    }
    cout << setprecision(6) << fixed << (f[y] - f[x-1]) / 1e6;
}
