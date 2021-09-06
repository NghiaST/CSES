#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000005;
int n, k, a[105], f[N];
 
int main()
{
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> a[i];
    sort(a+1, a+k+1);
    for(int i=1; i<=n; ++i) {
        f[i] = 0;
        for(int j=1; j<=k && a[j]<=i; ++j)
        if (!f[i-a[j]]) {
            f[i] = 1;
            break;
        }
        cout << (f[i] ? 'W' : 'L');
    }
}
