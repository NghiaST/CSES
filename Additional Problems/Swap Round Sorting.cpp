#include <iostream>
#include <vector>
using namespace std;
int n, a[200005], pos[200005], choice[200005];
vector<pair<int,int>> Ans1, Ans2;
 
void Hoan(int i, int j) {
    swap(a[i], a[j]);
    swap(pos[a[i]], pos[a[j]]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], pos[a[i]] = i;
    for(int i=1; i<=n; ++i) if (!choice[i]) {
        int j = i;
        while (!choice[j]) choice[j] = true, j = a[j];
        if (i != a[i] && a[i] == pos[i]) {
            Ans1.emplace_back(i, a[i]);
            Hoan(i, a[i]);
        }
        while (true) {
            int prv = pos[j], nxt = a[j];
            if (prv == nxt) break;
            Ans1.emplace_back(prv, nxt);
            Hoan(prv, nxt);
            j = prv;
        }
    }
    for(int i=1; i<=n; ++i) if (a[i] != i) {
        Ans2.emplace_back(i, a[i]);
        Hoan(i, a[i]);
    }
    if (Ans2.size()) {
        cout << 2 << '\n';
        cout << Ans1.size() << '\n';
        for(pair<int,int> w : Ans1) cout << w.first << ' ' << w.second << '\n';
        cout << Ans2.size() << '\n';
        for(pair<int,int> w : Ans2) cout << w.first << ' ' << w.second << '\n';
    }
    else if (Ans1.size()) {
        cout << 1 << '\n';
        cout << Ans1.size() << '\n';
        for(pair<int,int> w : Ans1) cout << w.first << ' ' << w.second << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}
