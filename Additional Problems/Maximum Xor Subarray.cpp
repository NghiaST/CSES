#include <iostream>
using namespace std;
int n, w, x, res;
struct node{
    node *L, *R; /// 0, 1
    node() : L(NULL), R(NULL) {};
} *root;
 
void add(node *&x, int high, int val) {
    if (x == NULL) x = new node();
    if (high < 0) return;
    if ((val >> high) & 1) add(x->R, high-1, val);
    else add(x->L, high-1, val);
}
 
void get(node *x, int high, int val) {
    if (high < 0) return (void) (res = max(res, val));
    if ((val >> high) & 1) {
        if (x->L != NULL) get(x->L, high-1, val);
        else get(x->R, high-1, val ^ (1<<high));
    }
    else {
        if (x->R != NULL) get(x->R, high-1, val^(1<<high));
        else get(x->L, high-1, val);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    root = NULL;
    add(root, 30, 0);
    cin >> n;
    while (n--) {
        cin >> x; w ^= x;
        get(root, 30, w);
        add(root, 30, w);
    }
    cout << res;
}
