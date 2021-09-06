#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long llong;
const int N = 100005;
int n, cntx, cnty;
set<llong> D[N * 4];
llong resx, resy, *b[N], Fx[N], Fy[N];
 
struct point{ llong x, y; } P[N], P2[N];
 
void Enter() {
    char ch, ch2 = '@';
    int w;
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> ch >> w;
        if (ch == 'U' && ch2 == 'D' || ch == 'D' && ch2 == 'U') {
            n = i-1;
            break;
        }
        if (ch == 'L' && ch2 == 'R' || ch == 'R' && ch2 == 'L') {
            n = i-1;
            break;
        }
        if (ch == 'U') P[i] = {P[i-1].x, P[i-1].y + w};
        if (ch == 'D') P[i] = {P[i-1].x, P[i-1].y - w};
        if (ch == 'L') P[i] = {P[i-1].x - w, P[i-1].y};
        if (ch == 'R') P[i] = {P[i-1].x + w, P[i-1].y};
        ch2 = ch;
        P2[i] = P[i];
    }
}
 
void Compress() {
    for(int i=0; i<=n; ++i) b[i] = &P[i].x;
    sort(b, b+n+1, [] (llong *A, llong *B) { return *A < *B; });
    for(int i=0; i<=n; ++i) {
        if (i==0 || *b[i] != Fx[cntx]) Fx[++cntx] = *b[i];
        *b[i] = cntx;
    }
 
    for(int i=0; i<=n; ++i) b[i] = &P[i].y;
    sort(b, b+n+1, [] (llong *A, llong *B) { return *A < *B; });
    for(int i=0; i<=n; ++i) {
        if (i==0 || *b[i] != Fy[cnty]) Fy[++cnty] = *b[i];
        *b[i] = cnty;
    }
}
 
void update(int l, int r, int pos, int x, int y, llong val) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        D[pos].insert(val);
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, pos*2, x, y, val);
    update(mid+1, r, pos*2+1, x, y, val);
}
 
llong queryMin(int l, int r, int pos, int x, llong val) {
    llong ans = 1e18;
    if (l > x || r < x) return ans;
    set<llong>::iterator it = D[pos].upper_bound(val);
    if (it != D[pos].end()) ans = *it;
    if (l != r) {
        int mid = (l+r) / 2;
        ans = min(ans, queryMin(l, mid, pos*2, x, val));
        ans = min(ans, queryMin(mid+1, r, pos*2+1, x, val));
    }
    return ans;
}
 
llong queryMax(int l, int r, int pos, int x, llong val) {
    llong ans = -1e18;
    if (l > x || r < x) return ans;
    set<llong>::iterator it = D[pos].lower_bound(val);
    if (it != D[pos].begin()) ans = *(--it);
    if (l != r) {
        int mid = (l+r) / 2;
        ans = max(ans, queryMax(l, mid, pos*2, x, val));
        ans = max(ans, queryMax(mid+1, r, pos*2+1, x, val));
    }
    return ans;
}
 
void Process() {
    update(1, cntx, 1, P[0].x, P[0].x, P2[0].y);
    for(int i=1; i<=n; ++i) {
        if (P[i].x != P[i-1].x) {
            update(1, cntx, 1, min(P[i].x, P[i-1].x), max(P[i].x, P[i-1].x), P2[i].y);
            resx += abs(P2[i].x - P2[i-1].x);
        }
        else {
            if (P[i-1].y < P[i].y) {
                llong pos_min = queryMin(1, cntx, 1, P[i].x, P2[i-1].y);
                if (pos_min > P2[i].y) resx += P2[i].y - P2[i-1].y;
                else {
                    resx += pos_min - P2[i-1].y;
                    break;
                }
            }
            else {
                llong pos_max = queryMax(1, cntx, 1, P[i].x, P2[i-1].y);
                if (pos_max < P2[i].y) resx += P2[i-1].y - P2[i].y;
                else {
                    resx += P2[i-1].y - pos_max;
                    break;
                }
            }
            update(1, cntx, 1, P[i].x, P[i].x, P2[i-1].y);
            update(1, cntx, 1, P[i].x, P[i].x, P2[i].y);
        }
    }
    for(int i=1; i<=cntx*4; ++i) D[i].clear();
 
    update(1, cnty, 1, P[0].y, P[0].y, P2[0].x);
    for(int i=1; i<=n; ++i) {
        if (P[i].y != P[i-1].y) {
            update(1, cnty, 1, min(P[i].y, P[i-1].y), max(P[i].y, P[i-1].y), P2[i].x);
            resy += abs(P2[i].y - P2[i-1].y);
        }
        else {
            if (P[i-1].x < P[i].x) {
                llong pos_min = queryMin(1, cnty, 1, P[i].y, P2[i-1].x);
                if (pos_min > P2[i].x) resy += P2[i].x - P2[i-1].x;
                else {
                    resy += pos_min - P2[i-1].x;
                    break;
                }
            }
            else {
                llong pos_max = queryMax(1, cnty, 1, P[i].y, P2[i-1].x);
                if (pos_max < P2[i].x) resy += P2[i-1].x - P2[i].x;
                else {
                    resy += P2[i-1].x - pos_max;
                    break;
                }
            }
            update(1, cnty, 1, P[i].y, P[i].y, P2[i-1].x);
            update(1, cnty, 1, P[i].y, P[i].y, P2[i].x);
        }
    }
    cout << min(resx, resy);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Compress();
    Process();
}
