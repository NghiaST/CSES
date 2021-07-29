#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
pair<int,int> a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a+1, a+n+1);
    for(int i=1, r=n; i<=n; ++i) {
        while (r > i && a[i].first + a[r].first > k) --r;
        if (i == r) break;
        if (a[i].first + a[r].first < k) continue;
        else {
            cout << a[i].second << ' ' << a[r].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
