#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 205;
int n, pos, res;
char s[N], Ans[1005][N];
 
void Enter() {
    cin >> n >> s + 1;
}
 
bool Giao(int xa, int ya, int xb, int yb) {
    return !(xa > yb || xb > ya);
}
 
void build(int x) {
    if (Giao(x, x+1, pos, pos+1) || x < 1 || x >= n*2) {
        cout << -1;
        exit(0);
    }
    swap(s[x], s[pos]);
    swap(s[x + 1], s[pos + 1]);
    pos = x;
    copy(s + 1, s + n*2 + 1, Ans[++res] + 1);
}
 
void Process() {
    FOR(i, 1, n*2) if (s[i] == '.') pos = i - 1;
    int End = 0;
    FOR(i, 1, n*2) {
        if (s[i] != 'A') continue;
        int id = i;
        i = ++End;
        if (id == End) continue;
        if (id == n*2) {
            if (pos == n*2 - 2) build(pos - 2);
            id = pos + 1;
            build(n*2 - 1);
        }
 
        if (pos == End) {
            build(id);
            continue;
        }
        else if (pos == End + 1) {
            int tmp = End + 3;
            build(tmp);
            if (Giao(tmp, tmp + 1, id, id)) id -= 2;
        }
        if (id == End) continue;
        if (id != End + 1) {
            build(End);
            build(id);
            continue;
        }
        else {
            if (pos == n*2 - 1) build(pos - 2);
            int tmp = pos;
            build(End);
            build(tmp + 1);
            continue;
        }
    }
}
 
void Print() {
    cout << res << '\n';
    FOR(i, 1, res) cout << Ans[i] + 1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
    Print();
}
