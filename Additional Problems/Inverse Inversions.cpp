#include <iostream>
long long n, k;
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    while (k && k >= n-1) cout << n << ' ', k -= --n;
    cout << k+1 << ' ';
    for(int i=1; i<=k; ++i) cout << i << ' ';
    for(int i=k+2; i<=n; ++i) cout << i << ' ';
}
