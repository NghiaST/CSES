#include <iostream>
using namespace std;
int n, q, x, a[200005], it[800005];
 
void query(int l, int r, int cnt, int pos) {
    ++it[pos];
    if (l == r) {
        cout << a[l] << ' ';
        return;
    }
    int mid = (l+r) / 2;
    if (mid - l + 1 - it[pos*2] >= cnt) query(l, mid, cnt, pos*2);
    else query(mid+1, r, cnt - (mid - l + 1 - it[pos*2]), pos*2+1);
}
 
int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        cin >> x;
        query(1, n, x, 1);
    }
}
