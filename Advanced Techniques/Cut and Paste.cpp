#include <iostream>
using namespace std;
string s;
int n, q;
typedef struct node{
    int cnt;
    char ch;
    node *L, *R, *P;
} *TNode;
TNode root, nil;
 
void Init() {
    nil = new node;
    nil->L = nil->R = nil->P = nil;
    nil->cnt = 0;
    nil->ch = '@';
    root = nil;
}
 
void New(TNode &x) {
    x = new node;
    x->L = x->R = x->P = nil;
    x->cnt = 0;
    x->ch = '@';
}
 
void setL(TNode x, TNode y) { if (x != nil) x->L = y; if (y != nil) y->P = x; }
void setR(TNode x, TNode y) { if (x != nil) x->R = y; if (y != nil) y->P = x; }
 
TNode Build(int l, int r) {
    int mid = (l+r) / 2;
    TNode x;
    New(x);
    x->cnt = r - l + 1;
    x->ch = s[mid];
    if (l < mid) setL(x, Build(l, mid-1));
    if (mid < r) setR(x, Build(mid+1, r));
    return x;
}
 
void Rotate_Left(TNode x) {
    TNode y = x->P, z = x->L;
    if (y->P->L == y) setL(y->P, x); else setR(y->P, x);
    setL(x, y);
    setR(y, z);
    int tmp = x->cnt;
    x->cnt = y->cnt;
    y->cnt -= tmp - z->cnt;
}
 
void Rotate_Right(TNode x) {
    TNode y = x->P, z = x->R;
    if (y->P->L == y) setL(y->P, x); else setR(y->P, x);
    setR(x, y);
    setL(y, z);
    int tmp = x->cnt;
    x->cnt = y->cnt;
    y->cnt -= tmp - z->cnt;
}
 
void Update(TNode x) {
    if (x->P->L == x) Rotate_Right(x);
    else Rotate_Left(x);
}
 
void Splay(TNode x) {
    TNode y = x->P, z = y->P;
    while (y != nil) {
        if (z == nil) Update(x);
        else {
            if ((z->L == y) == (y->L == x)) Update(y);
            else Update(x);
            Update(x);
        }
        y = x->P, z = y->P;
    }
}
 
TNode Find_without_Splay(TNode x, int pos) {
    int w = x->L->cnt;
    if (pos < w + 1) return Find_without_Splay(x->L, pos);
    else if (pos > w + 1) return Find_without_Splay(x->R, pos - w - 1);
    else return x;
}
 
void Find_pos(int pos, TNode &x) {
    TNode y = Find_without_Splay(x, pos);
    Splay(y);
    x = y;
}
 
void Split(int pos, TNode &x, TNode &y) {
    if (!pos) {
        y = x;
        x = nil;
        return;
    }
    Find_pos(pos, x);
    y = x->R;
    x->cnt -= y->cnt;
    x->R = y->P = nil;
}
 
void Union(TNode &x, TNode &y) {
    if (y == nil) return;
    if (x == nil) {
        x = y;
        return;
    }
    Find_pos(x->cnt, x);
    setR(x, y);
    x->cnt += y->cnt;
}
 
void Solve(int i, int j) {
    TNode partA, partB, partC;
    partA = root;
    Split(j, partA, partC);
    Split(i-1, partA, partB);
    Union(partA, partC);
    Union(partA, partB);
    root = partA;
}
 
void Print(TNode x) {
    if (x == nil) return;
    Print(x->L);
    cout << x->ch;
    Print(x->R);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    cin >> n >> q >> s;
    root = Build(0, n-1);
    int i, j;
    while (q--) {
        cin >> i >> j;
        Solve(i, j);
    }
    Print(root);
}
