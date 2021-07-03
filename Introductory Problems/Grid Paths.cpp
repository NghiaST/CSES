#include <iostream>
using namespace std;
char s[50];
int res;
bool avail[9][9];
 
bool only(int x, int y) {
    if (avail[x][y] || x==7 && y==1) return false;
    int k = 0;
    if (!avail[x-1][y]) ++k;
    if (!avail[x+1][y]) ++k;
    if (!avail[x][y-1]) ++k;
    if (!avail[x][y+1]) ++k;
    return k == 1;
}
 
void visit(int x, int y, int p) {
    if (x == 7 && y == 1) return (void) (res += (p==48));
    int u = avail[x-1][y];
    int d = avail[x+1][y];
    int l = avail[x][y-1];
    int r = avail[x][y+1];
    char w = s[p];
    if (u && d && !l && !r || !u && !d && l && r) return;
    avail[x][y] = true;
 
    if (only(x-1, y)) {
        if (w == '?' || w == 'U') visit(x-1, y, p+1);
        avail[x][y] = false;
        return;
    }
    if (only(x+1, y)) {
        if (w == '?' || w == 'D') visit(x+1, y, p+1);
        avail[x][y] = false;
        return;
    }
    if (only(x, y-1)) {
        if (w == '?' || w == 'L') visit(x, y-1, p+1);
        avail[x][y] = false;
        return;
    }
    if (only(x, y+1)) {
        if (w == '?' || w == 'R') visit(x, y+1, p+1);
        avail[x][y] = false;
        return;
    }
 
    if (!u && (w == '?' || w == 'U')) visit(x-1, y, p+1);
    if (!d && (w == '?' || w == 'D')) visit(x+1, y, p+1);
    if (!l && (w == '?' || w == 'L')) visit(x, y-1, p+1);
    if (!r && (w == '?' || w == 'R')) visit(x, y+1, p+1);
 
    avail[x][y] = false;
}
 
int main()
{
    cin >> s;
    for(int i=0; i<=8; ++i) avail[0][i] = avail[i][0] = avail[8][i] = avail[i][8] = true;
    visit(1, 1, 0);
    cout << res;
}
