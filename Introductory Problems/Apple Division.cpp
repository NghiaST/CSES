#include <iostream>
using namespace std;
int n, a[25];
long long res, sum;
 
void dp(int x, long long s2) {
    if (x == n) return (void) (res = min(res, abs(sum - s2*2)));
    dp(x+1, s2);
    dp(x+1, s2 + a[x]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], sum += a[i];
    res = 3e13;
    dp(0, 0);
    cout << res;
}
