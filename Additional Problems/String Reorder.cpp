#include <iostream>
using namespace std;
string s;
int c[256], maxi, prv;
 
int main()
{
    getline(cin, s);
    for(char i : s) ++c[i];
    for(int i=s.length(); i; --i) {
        int maxi = 0;
        for(int j='A'; j<='Z'; ++j)
            if (j != prv && c[maxi] < c[j]) maxi = j;
        if (c[maxi] * 2 - 1 > i) {
            cout << -1;
            return 0;
        }
        if (c[maxi] * 2 > i) prv = maxi;
        else {
            for(int j='A'; j<='Z'; ++j)
            if (j != prv && c[j]) {
                prv = j;
                break;
            }
        }
        --c[prv];
        putchar(prv);
    }
}
