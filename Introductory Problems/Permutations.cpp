#include <iostream>
using namespace std;
int n, px, x;
long long res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    if (n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        cout << n/2 + 1;
        int la = 0, lb = n/2 + 1;
        while (la < n/2) {
            cout << ' ' << ++la;
            if (lb < n) cout << ' ' << ++lb;
        }
    }
}
