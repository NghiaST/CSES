#include <iostream>
#define avail(x,y) (0<x && x<9 && 0<y && y<9 && !a[x][y])
using namespace std;
const int Gx[8] = {-2,-1,1,2,2,1,-1,-2};
const int Gy[8] = {-1,-2,-2,-1,1,2,2,1};
int a[9][9];
 
int get(int x, int y) {
    if (!avail(x,y)) return 99;
    int w = 0;
    for(int i=0; i<8; ++i) {
        int u = x + Gx[i];
        int v = y + Gy[i];
        if (avail(u,v)) ++w;
    }
    return w;
}
 
void FindPath(int x, int y) {
    a[x][y] = 1;
    for(int i=2; i<=64; ++i) {
        int nxt = 8, uNxt = 0, vNxt = 0;
        for(int j=0; j<8; ++j) {
            int u = x + Gx[j];
            int v = y + Gy[j];
            int w = get(u, v);
            if (w < nxt) {
                nxt = w;
                uNxt = u;
                vNxt = v;
            }
        }
        x = uNxt;
        y = vNxt;
        a[x][y] = i;
    }
}
 
int main()
{
    int x, y;
    cin >> y >> x;
    FindPath(x, y);
    for(int i=1; i<=8; ++i)
        for(int j=1; j<=8; ++j)
            cout << a[i][j] << " \n"[j==8];
}
