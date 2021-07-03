#include <iostream>
using namespace std;
int n, res, attacked[8][8];
string s[8];
 
void putQueen(int x) {
    if (x == 8) return (void) (++res);
    for(int i=0; i<8; ++i) {
        if (attacked[x][i] || s[x][i] == '*') continue;
        int w1 = i, w2 = i, w3 = i;
        for(int j=x+1; j<8; ++j) {
            --w1; ++w3;
            if (w1 >= 0) ++attacked[j][w1];
            if (w3 < 8) ++attacked[j][w3];
            ++attacked[j][w2];
        }
        putQueen(x+1);
        w1 = i, w2 = i, w3 = i;
        for(int j=x+1; j<8; ++j) {
            --w1; ++w3;
            if (w1 >= 0) --attacked[j][w1];
            if (w3 < 8) --attacked[j][w3];
            --attacked[j][w2];
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<8; ++i) cin >> s[i];
    putQueen(0);
    cout << res;
}
