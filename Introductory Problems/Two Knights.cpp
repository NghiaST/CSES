#include <iostream>
using namespace std;
int n;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(long long i=1; i<=n; ++i) {
        cout << i*i * (i*i-1) / 2 - 8 * (i-1) * (i-2) / 2 << '\n';
    }
}
