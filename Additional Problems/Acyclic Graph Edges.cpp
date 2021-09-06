#include <iostream>
using namespace std;
int n, m, u, v;
 
int main()
{
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        cout << u << ' ' << v << '\n';
    }
}
