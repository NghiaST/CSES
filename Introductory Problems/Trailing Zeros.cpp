#include <iostream>
using namespace std;
int n, res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n) res += n/=5;
    cout << res;
}
