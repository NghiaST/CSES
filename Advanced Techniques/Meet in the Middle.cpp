#include <iostream>
#include <algorithm>
using namespace std;
int n, a[45], wc, wd;
long long c[1048580], d[1048580], m, res;
 
void get(int l, int r, long long sum) {
    if (l > r) {
        if (r != n) c[++wc] = sum;
        else d[++wd] = sum;
        return;
    }
    get(l+1, r, sum);
    get(l+1, r, sum + a[l]);
}
 
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    get(1, n/2, 0);
    get(n/2+1, n, 0);
    sort(c+1, c+wc+1);
    sort(d+1, d+wd+1);
    for(int i=1, l=wd, r=wd; i<=wc; ++i) {
        while (l>0 && c[i] + d[l] >= m) --l;
        while (r>0 && c[i] + d[r] > m) --r;
        res += r-l;
    }
    cout << res;
}
