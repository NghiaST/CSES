#include <iostream>
using namespace std;
int n, a[2][100005];
long long res, f0, f1;
 
int main()
{
    cin >> n;
    for(int i=0; i<2; ++i)
    for(int j=0; j<n; ++j) cin >> a[i][j];
    for(int i=0; i<n; ++i) {
        res += abs(f0) + abs(f1);
        f0 += a[0][i] - 1;
        f1 += a[1][i] - 1;
        if (f0 > 0 && f1 < 0) {
            int w = min(f0, -f1);
            f0 -= w;
            f1 += w;
            res += w;
        }
        if (f0 < 0 && f1 > 0) {
            int w = min(-f0, f1);
            f0 += w;
            f1 -= w;
            res += w;
        }
    }
    cout << res;
}
