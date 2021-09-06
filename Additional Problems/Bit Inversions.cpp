#include <iostream>
#include <set>
#include <queue>
#define sii set<int>::iterator
using namespace std;
string s;
int n, q, cnt[200005];
set<int> Q;
priority_queue<int> P;
 
sii nxt(sii i) { return ++i; }
sii prv(sii i) { return --i; }
 
void them(int val) {
    if (val == n) return;
    Q.insert(val);
    sii i = Q.lower_bound(val);
    sii pr = prv(i), nt = nxt(i);
    --cnt[*nt - *pr];
    if (!cnt[*i - *pr]++) P.push(*i - *pr);
    if (!cnt[*nt - *i]++) P.push(*nt - *i);
}
 
void xoa(sii i) {
    if (*i == 0 || *i == n) return;
    sii pr = prv(i), nt = nxt(i);
    --cnt[*nt - *i];
    --cnt[*i - *pr];
    if (!cnt[*nt - *pr]++) P.push(*nt - *pr);
    Q.erase(i);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    getline(cin, s); n = s.length();
    Q.insert(0);
    Q.insert(n);
    ++cnt[n];
    for(int i=1; i<n; ++i) {
        if (s[i] != s[i-1]) them(i);
    }
 
    cin >> q;
    int x;
    while (q--) {
        cin >> x;
        sii j = Q.lower_bound(x);
        sii i = prv(j);
        sii k = nxt(j);
        if (x == *j) {
            if (x - *i == 1) {
                xoa(i);
                xoa(j);
            }
            else {
                them(*j - 1);
                xoa(j);
            }
        }
        else {
            if (x - *i == 1) {
                xoa(i);
                them(x);
            }
            else {
                them(x-1);
                them(x);
            }
        }
        while (!cnt[P.top()]) P.pop();
        cout << P.top() << ' ';
    }
}
