#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200005];
 
int cmp(int x, int y) { return x==y; }
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    cout << unique(&a[1], &a[n+1]) - &a[1];
}
