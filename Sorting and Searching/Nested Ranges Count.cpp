#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, cnt, *b[N*2], bit[N*2], ans[N], ans2[N];
struct Data{
    int x, y, z;
    bool operator <  (Data &p) { return y < p.y || y == p.y && x > p.x; }
} a[N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }
}
 
void Init() {
    for(int i=1; i<=n; ++i) b[i] = &a[i].x, b[i+n] = &a[i].y;
    sort(b+1, b+n*2+1, [] (int *A, int *B) { return *A < *B; });
    for(int i=1, old; i<=n*2; ++i) {
        if (i==1 || old != *b[i]) ++cnt, old = *b[i];
        *b[i] = cnt;
    }
}
 
int getBIT(int x, bool inverse) {
    if (inverse) x = cnt - x + 1;
    int val = 0;
    for(; x<=cnt; x+=x&-x) val += bit[x];
    return val;
}
 
void update(int x, bool inverse) {
    if (inverse) x = cnt - x + 1;
    for(; x; x-=x&-x) ++bit[x];
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1, maxr = 0; i<=n; ++i) {
        ans2[a[i].z] = getBIT(a[i].x, 0);
        update(a[i].x, 0);
    }
    fill(bit, bit+cnt, 0);
    for(int i=n; i; --i) {
        ans[a[i].z] = getBIT(a[i].x, 1);
        update(a[i].x, 1);
    }
    for(int i=1; i<=n; ++i) cout << ans2[i] << ' ';
    cout << '\n';
    for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Init();
    Process();
}
