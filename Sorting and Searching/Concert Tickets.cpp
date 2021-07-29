#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, k, x;
multiset<int> S;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    while (n--) cin >> x, S.insert(x);
    while (k--) {
        cin >> x;
        multiset<int>::iterator p = S.upper_bound(x);
        if (p == S.begin()) cout << "-1\n";
        else cout << *(--p) << '\n', S.erase(p);
    }
}
