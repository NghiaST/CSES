#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, dem;
char s[10];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    n = strlen(s);
    sort(s, s + n);
    while (++dem, next_permutation(s, s + n));
    cout << dem << '\n';
    while (dem--) {
        cout << s << '\n';
        next_permutation(s, s + n);
    }
}
