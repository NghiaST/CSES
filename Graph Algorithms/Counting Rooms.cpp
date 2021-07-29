#include <iostream>
#include <algorithm>
#define getBIT(x,i) ((x>>(i))&1)
#define xorBIT(x,i) (x ^ (1<<(i)))
using namespace std;
const int N = 1005;
int n, m, res, vs[N][N];
char s[N][N];
 
void Enter() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> s[i];
}
 
void visit(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || vs[x][y]) return;
    vs[x][y] = true;
    visit(x-1, y);
    visit(x, y-1);
    visit(x, y+1);
    visit(x+1, y);
}
 
void Process() {
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if (!vs[i][j] && s[i][j] != '#')
                ++res, visit(i, j);
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
