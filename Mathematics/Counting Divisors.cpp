#include <iostream>
using namespace std;
int t, n, f[1000005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=1; i<=1000000; ++i)
        for(int j=i; j<=1000000; j+=i) ++f[j];
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] << '\n';
    }
}
