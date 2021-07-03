#include <iostream>
using namespace std;
long long n, sum, ok[1000005], res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    long long sum = n*(n+1) / 2;
    if (sum&1) cout << "NO";
    else {
        cout << "YES\n";
        sum /= 2;
        for(int i=n; i; --i) if (sum >= i) sum -= i, ok[i] = 1, ++res;
        cout << res << '\n';
        for(int i=1; i<=n; ++i) if (ok[i]) cout << i << ' ';
        cout << '\n' << n - res << '\n';
        for(int i=1; i<=n; ++i) if (!ok[i]) cout << i << ' ';
    }
}
