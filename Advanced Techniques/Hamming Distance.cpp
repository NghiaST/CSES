#include <iostream>
#include <algorithm>
int n, k, res = 100;
using namespace std;
int a[20005];
string s;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {
        cin >> s;
        int w = 0;
        for(int j=0; j<k; ++j) w = w*2 + s[j] - '0';
        a[i] = w;
    }
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            res = min(res, (int) __builtin_popcount(a[i] ^ a[j]));
    cout << res;
}
