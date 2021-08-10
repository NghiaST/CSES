#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7, N = 1005, M = 105;
int n, m, kmp[M], nxt[M][26], f[M], f2[M];
char s[N];
 
int main()
{
    cin >> n >> s + 1;
    m = strlen(s + 1);
    kmp[0] = -1;
    nxt[0][s[1] - 'A'] = 1;
    for(int i=2; i<=m; ++i) {
        for(int j=0; j<26; ++j) {
            char p = j + 'A';
            for(int w=kmp[i-1]; w!=-1; w=kmp[w]) {
                if (s[w+1] == p) {
                    nxt[i-1][j] = w + 1;
                    break;
                }
            }
        }
        nxt[i-1][s[i] - 'A'] = i;
        for(int w=kmp[i-1]; w!=-1; w=kmp[w]) {
            if (s[w + 1] == s[i]) {
                kmp[i] = w + 1;
                break;
            }
        }
    }
    f[0] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<m; ++j) f2[j] = f[j], f[j] = 0;
        for(int j=0; j<m; ++j) {
            for(int w=0; w<26; ++w) {
                (f[nxt[j][w]] += f2[j]) %= MOD;
            }
        }
    }
    long long res = 1;
    for(int i=1; i<=n; ++i) res = res * 26 % MOD;
    for(int i=0; i<m; ++i) res = (res - f[i] + MOD) % MOD;
    cout << res;
}
