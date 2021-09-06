#include <iostream>
#include <vector>
using namespace std;
int n, a[200005], deg[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n-2; ++i) cin >> a[i], ++deg[a[i]];
    int w = 1;
    while (deg[w]) ++w;
    int now = w;
    for(int i=1; i<=n-2; ++i) {
        cout << now << ' ' << a[i] << '\n';
        if (--deg[a[i]] == 0 && a[i] < w) now = a[i];
        else {
            ++w;
            while (deg[w]) ++w;
            now = w;
        }
    }
    cout << now << ' ' << n;
}
