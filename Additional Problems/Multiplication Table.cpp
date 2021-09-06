#include <iostream>
using namespace std;
long long n;
 
bool check(long long x) {
    long long w = n*n/2 + 1;
    for(int i=1; i<=n; ++i) w -= min(n, x/i);
    return w <= 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    long long l = 1, r = n*n, mid;
    while (l < r) {
        mid = (l+r) / 2;
        if (check(mid)) r = mid; else l = mid + 1;
    }
    cout << l;
}
