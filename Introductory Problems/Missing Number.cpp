#include <iostream>
#include <bitset>
using namespace std;
int n, x;
bitset<200005> ok;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (--n) cin >> x, ok[x] = 1;
    while (++n, ok[n]);
    cout << n;
}
