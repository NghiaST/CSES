#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, a[N], b[N], *c[N], lazy[N*4], mini[N*4], maxi[N*4];
long long res;
 
void update(int val, int x, int y, int l = 1, int r = n, int pos = 1) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        lazy[pos] += val;
        mini[pos] += val;
        maxi[pos] += val;
        return;
    }
    int mid = (l+r) / 2;
    update(val, x, y, l, mid, pos*2);
    update(val, x, y, mid+1, r, pos*2+1);
    mini[pos] = min(mini[pos*2], mini[pos*2+1]) + lazy[pos];
    maxi[pos] = max(maxi[pos*2], maxi[pos*2+1]) + lazy[pos];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i] >> b[i];
        c[i] = &a[i];
        if (b[i] == 2) b[i] = -1;
    }
    sort(c+1, c+n+1, [] (int *A, int *B) { return *A < *B; });
    for(int i=1; i<=n; ++i) *c[i] = i;
    for(int i=1; i<=n; ++i) {
        update(b[i], 1, a[i]);
        if (mini[1] == 0) cout << ">\n";
        else if (maxi[1] == 0) cout << "<\n";
        else cout << "?\n";
    }
}
