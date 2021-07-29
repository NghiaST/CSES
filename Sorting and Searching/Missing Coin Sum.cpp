#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long sum;
int a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        if (sum + 1 < a[i]) break;
        sum += a[i];
    }
    cout << sum + 1;
}
