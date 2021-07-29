#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, q, cc, cnt, a[N], px[N], py[N], *b[N*3], bit[N*3];
char ch[N];
 
void Enter() {
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> ch[i] >> px[i] >> py[i];
}
 
void Compress() {
    for(int i=1; i<=n; ++i) b[++cc] = &a[i];
    for(int i=1; i<=q; ++i) {
        if (ch[i] == '?') b[++cc] = &px[i];
        b[++cc] = &py[i];
    }
    sort(b+1, b+cc+1, [] (int *A, int *B) { return *A < *B; });
    for(int i=1, old; i<=cc; ++i) {
        if (i == 1 || *b[i] != old) old = *b[i], ++cnt;
        *b[i] = cnt;
    }
}
 
void update(int x, int val) {
    for(; x<=cnt; x+=x&-x) bit[x] += val;
}
 
int query(int x) {
    int val = 0;
    for(; x; x-=x&-x) val += bit[x];
    return val;
}
 
void Process() {
    for(int i=1; i<=n; ++i) update(a[i], 1);
    for(int i=1; i<=q; ++i) {
        if (ch[i] == '!') {
            update(a[px[i]], -1);
            a[px[i]] = py[i];
            update(a[px[i]], 1);
        }
        else {
            cout << query(py[i]) - query(px[i] - 1) << '\n';
        }
    }
}
 
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Compress();
    Process();
}
