#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;
const int N = 200005;
int n, res, home[N];
struct Data{
    int x, y, z;
    bool operator <  (Data &p) { return y < p.y || y == p.y && x > p.x; }
} a[N];
set<pii> Q;
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        set<pii>::iterator p = Q.upper_bound(make_pair(a[i].x, 0));
        if (p == Q.begin()) {
            home[a[i].z] = ++res;
            Q.insert(make_pair(a[i].y, home[a[i].z]));
        }
        else {
            --p;
            home[a[i].z] = p->second;
            Q.erase(p);
            Q.insert(make_pair(a[i].y, home[a[i].z]));
        }
    }
    cout << res << '\n';
    for(int i=1; i<=n; ++i) cout << home[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
