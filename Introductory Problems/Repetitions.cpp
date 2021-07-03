#include <iostream>
using namespace std;
int res, cnt;
 
int main()
{
    char c = getchar(), oldchar = 'W';
    while (c != ' ' && c != '\0' && c != '\n') {
        if (oldchar == c) ++cnt; else res = max(res, cnt), cnt = 1, oldchar = c;
        c = getchar();
    }
    res = max(res, cnt);
    cout << res;
}
