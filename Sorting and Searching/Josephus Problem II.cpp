#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, k, p, c[800005];
 
void Init(int l, int r, int pos) {
    c[pos] = r - l + 1;
    if (l == r) return;
    int mid = (l+r) / 2;
    Init(l, mid, pos*2);
    Init(mid+1, r, pos*2+1);
}
 
int query(int l, int r, int cnt, int pos) {
    --c[pos];
    if (l == r) return l;
    int mid = (l+r) / 2;
    if (cnt <= c[pos*2]) return query(l, mid, cnt, pos*2);
    else return query(mid+1, r, cnt - c[pos*2], pos*2+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k; ++k;
    Init(1, n, 1);
    p = 1;
    for(int i=n; i; --i) {
        p = (p + k - 2) % i + 1;
        cout << query(1, n, p, 1) << ' ';
    }
}
