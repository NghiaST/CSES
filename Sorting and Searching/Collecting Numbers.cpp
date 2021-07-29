#include <iostream>
#include <algorithm>
using namespace std;
int n, x, res, a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x; a[x] = i;
    }
    for(int i=2; i<=n; ++i) if (a[i] < a[i-1]) ++res;
    cout << res + 1;
}
