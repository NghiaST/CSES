#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, res, sum;
pair<int,int> a[400005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i].first >> a[i+n].first;
        a[i].second = 1, a[i+n].second = -1;
    }
    sort(a+1, a+n*2+1);
    for(int i=1; i<=n*2; ++i) res = max(res, sum += a[i].second);
    cout << res;
}
