#include <iostream>
#include <map>
using namespace std;
int n, x, lft, res;
map<int,int> a;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        lft = max(lft, a[x]);
        a[x] = i;
        res = max(res, i - lft);
    }
    cout << res;
}
