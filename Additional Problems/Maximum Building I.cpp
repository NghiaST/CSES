#include <iostream>
using namespace std;
int n, m, cnt, res, f[1005], Q[1005];
char s[1005];
 
int main()
{
    scanf("%d%d\n", &n, &m);
    Q[0] = -1;
    for(int i=0; i<n; ++i) {
        gets(s);
        for(int j=0; j<m; ++j)
            if (s[j] == '*') f[j] = 0; else ++f[j];
        for(int j=0; j<m; ++j) {
            while (cnt && f[j] <= f[Q[cnt]]) {
                res = max(res, (j - Q[cnt-1] - 1) * f[Q[cnt]]);
                --cnt;
            }
            Q[++cnt] = j;
        }
        while (cnt) {
            res = max(res, (m - Q[cnt-1] - 1) * f[Q[cnt]]);
            --cnt;
        }
    }
    cout << res;
}
