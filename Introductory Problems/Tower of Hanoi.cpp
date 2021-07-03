#include <iostream>
#include <vector>
using namespace std;
vector<string> ans;
int n;
 
void tranform(int x, int y, int z, int p) {
    if (p == 1) {
        cout << x << ' ' << z << '\n';
        return;
    }
    tranform(x, z, y, p-1);
    cout << x << ' ' << z << '\n';
    tranform(y, x, z, p-1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    tranform(1, 2, 3, n);
}
