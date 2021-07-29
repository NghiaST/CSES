#include <iostream>
#include <algorithm>
using namespace std;
int n, q, x, y, res, a[200005], pos[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        cin >> a[i]; pos[a[i]] = i;
    }
    pos[0] = n+1; pos[n+1] = n+2;
    for(int i=1; i<=n; ++i) if (pos[i] < pos[i-1]) ++res;
    while (q--) {
        cin >> x >> y;
        int wa = a[x], wb = a[y];
        if (y != pos[wa - 1] && x < pos[wa - 1]) --res;
        if (y != pos[wa + 1] && x > pos[wa + 1]) --res;
        if (y < pos[wb - 1]) --res;
        if (y > pos[wb + 1]) --res;
        swap(a[x], a[y]);
        swap(pos[wa], pos[wb]);
        swap(x, y);
        if (y != pos[wa - 1] && x < pos[wa - 1]) ++res;
        if (y != pos[wa + 1] && x > pos[wa + 1]) ++res;
        if (y < pos[wb - 1]) ++res;
        if (y > pos[wb + 1]) ++res;
        cout << res << '\n';
    }
}
