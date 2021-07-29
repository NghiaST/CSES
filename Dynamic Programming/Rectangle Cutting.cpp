#include <iostream>
#include <cstring>
using namespace std;
const int N = 505;
int n, m, c[N][N];
 
void Enter() {
    cin >> n >> m;
}
 
void Process() {
    if (m < n) swap(m, n);
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=i && j<=n; ++j) {
            if (i % j == 0) c[i][j] = i / j;
            else {
                c[i][j] = i*j;
                for(int w=1; w<=j/2; ++w)
                    if (c[i][j] > c[i][w] + c[i][j-w])
                        c[i][j] = c[i][w] + c[i][j-w];
                for(int w=1; w<=i/2 && w<=(int)(j*1.2); ++w)
                    if (c[i][j] > c[j][w] + c[j][i-w])
                        c[i][j] = c[j][w] + c[j][i-w];
            }
            c[j][i] = c[i][j];
        }
    }
    cout << c[m][n] - 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
