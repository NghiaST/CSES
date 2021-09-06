#include <iostream>
#include <algorithm>
using namespace std;
int n, k, a[55], b[55], *c[55], *d[55];
char ans[55][55];
 
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j) ans[i][j] = '.';
 
    for(int i=0; i<n; ++i) c[i] = &a[i], d[i] = &b[i];
    sort(c, c+n, [] (int *A, int *B) { return *A > *B; });
    for(int i=0; i<n; ++i) {
        sort(d, d+n, [] (int *A, int *B) { return *A > *B; });
        for(int j=0; j<*c[i]; ++j) ans[c[i] - a][d[j] - b] = 'X', --*d[j];
    }
    for(int i=0; i<n; ++i) if (b[i] != 0) {
        cout << -1;
        return 0;
    }
    for(int i=0; i<n; ++i) cout << ans[i] << '\n';
}
