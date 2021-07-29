#include <iostream>
#include <cstring>
using namespace std;
const int N = 5005;
int n, m, f[N][N];
char s1[N], s2[N];
 
void Enter() {
    scanf("%s%s", s1+1, s2+1);
    n = strlen(s1+1); m = strlen(s2+1);
}
 
void Process() {
    for(int i=1; i<=m; ++i) f[0][i] = i;
    for(int i=1; i<=n; ++i) f[i][0] = i;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) {
        f[i][j] = min(min(f[i-1][j] + 1, f[i][j-1] + 1), f[i-1][j-1] + 1);
        if (s1[i] == s2[j]) f[i][j] = min(f[i][j], f[i-1][j-1]);
    }
    cout << f[n][m];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
