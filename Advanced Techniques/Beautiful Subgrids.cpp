#include <iostream>
#pragma GCC target("popcnt")
int n, k, block;
unsigned long long a[3005][50], res;
using namespace std;
char s[3005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    scanf("%d\n", &n); block = (n+63) >> 6;
    for(int i=1; i<=n; ++i) {
        gets(s);
        for(int j=0; j<n; ++j) if (s[j] == '1') a[i][j>>6] |= 1ll << (j % 64);
    }
    for(int i=1; i<=n; ++i)
    for(int j=i+1; j<=n; ++j) {
        int cnt = 0;
        for(int w=0; w<block; ++w)
            cnt += __builtin_popcountll(a[i][w] & a[j][w]);
        res += cnt * (cnt - 1) / 2;
    }
    cout << res;
}
