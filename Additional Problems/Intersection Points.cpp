#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, p1, p2, bit[2000005];
long long res;
struct Data{
    int w1, w2, w3;
    bool operator < (Data &p) { return w1 < p.w1; };
} Q1[N*2], Q2[N]; /// ngang - doc
 
void update(int x, int val) {
    for(; x<=2000000; x+=x&-x) bit[x] += val;
}
 
int getBIT(int x) {
    int val = 0;
    for(; x; x-=x&-x) val += bit[x];
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int xa, ya, xb, yb;
    for(int i=1; i<=n; ++i) {
        cin >> xa >> ya >> xb >> yb;
        ya += 1e6, yb += 1e6;
        if (xa == xb) Q2[++p2] = {xa, ya, yb};
        else {
            Q1[++p1] = {xa, ya, 1};
            Q1[++p1] = {xb+1, ya, -1};
        }
    }
    sort(Q1+1, Q1+p1+1);
    sort(Q2+1, Q2+p2+1);
    for(int i=1, j=1; i<=p1; ++i) {
        while (j<=p2 && Q2[j] < Q1[i]) {
            res += getBIT(Q2[j].w3) - getBIT(Q2[j].w2 - 1);
            ++j;
        }
        update(Q1[i].w2, Q1[i].w3);
    }
    cout << res;
}
