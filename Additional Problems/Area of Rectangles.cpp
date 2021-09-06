#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int n, n2, cnt, *b[N * 2], trust[N * 2], it[N * 8], exist[N * 8];
long long res;
 
struct DataA{ int xa, ya, xb, yb; } a[N];
struct DataB{
    int x, ya, yb, val;
    bool operator < (DataB &p) { return x < p.x; }
} c[N * 2];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].xa >> a[i].ya >> a[i].xb >> a[i].yb;
}
 
void Init() {
    for(int i=1; i<=n; ++i) b[i] = &a[i].ya, b[i+n] = &a[i].yb;
    sort(b+1, b+n*2+1, [] (int *A, int *B) { return *A < *B; });
    for(int i=1; i<=n*2; ++i) {
        if (i==1 || *b[i] != trust[cnt]) trust[++cnt] = *b[i];
        *b[i] = cnt;
    }
    for(int i=1; i<=n; ++i) {
        ++a[i].ya;
        c[++n2] = {a[i].xa, a[i].ya, a[i].yb, 1};
        c[++n2] = {a[i].xb, a[i].ya, a[i].yb, -1};
    }
    sort(c+1, c+n2+1);
}
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (r < x || y < l) return;
    if (x <= l && r <= y) {
        exist[pos] += val;
        if (exist[pos]) it[pos] = trust[r] - trust[l-1];
        else it[pos] = it[pos*2] + it[pos*2 + 1];
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
    if (exist[pos]) it[pos] = trust[r] - trust[l-1];
    else it[pos] = it[pos*2] + it[pos*2 + 1];
}
 
void Process() {
    c[0].x = c[1].x;
    for(int i=1; i<=n2; ++i) {
        res += 1LL * it[1] * (c[i].x - c[i-1].x);
        update(1, cnt, c[i].ya, c[i].yb, c[i].val, 1);
    }
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Init();
    Process();
}
