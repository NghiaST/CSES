#include <iostream>
using namespace std;
int n;
string s, ans;
int main()
{
    cin >> n;
    for(int i=0; i*2<n; ++i) {
        int x = i, y = n - i;
        s.clear();
        while (x > 0 || y > 0) {
            if (x == y) break;
            if (x > y) s += '0', x -= y+1;
            else s += '1', y -= x+1;
        }
        if (i==0 || x==0 && y==0 && s.length() < ans.length()) ans = s;
    }
    cout << ans;
}
