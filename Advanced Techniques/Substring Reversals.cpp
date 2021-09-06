#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int n, q;
string s;
 
typedef struct node{
    node *L, *R;
    int key, ran;
    int sz, rev;
    node(int key) : L(NULL), R(NULL), key(key), ran(rand() % 0x3c3c3c3c), sz(1), rev(0) {};
} *TNode;
TNode root, P1, P2, P3;
 
int getSZ(TNode x) {
    if (x == NULL) return 0;
    return x->sz;
}
 
void update(TNode &x) {
    if (x == NULL) return;
    x->sz = getSZ(x->L) + getSZ(x->R) + 1;
}
 
TNode Rotate_Left(TNode x) {
    TNode y = x->R, z = y->L;
    y->L = x; x->R = z;
    update(x);
    update(y);
    return y;
}
 
TNode Rotate_Right(TNode x) {
    TNode y = x->L, z = y->R;
    y->R = x; x->L = z;
    update(x);
    update(y);
    return y;
}
 
void Reverse(TNode &x) {
    if (x == NULL) return;
    if (x->rev) {
        swap(x->L, x->R);
        if (x->L != NULL) x->L->rev ^= 1;
        if (x->R != NULL) x->R->rev ^= 1;
        x->rev = 0;
    }
}
 
void Insert(TNode &x, int key) {
    if (x == NULL) {
        x = new node(key);
        return;
    }
    Reverse(x);
    if (key < x->key) {
        Insert(x->L, key);
        if (x->L->ran > x->ran) x = Rotate_Right(x);
    }
    else {
        Insert(x->R, key);
        if (x->R->ran < x->ran) x = Rotate_Left(x);
    }
    update(x);
}
 
void Split(TNode x, TNode &P1, TNode &P2, int pos) {
    if (x == NULL) {
        P1 = P2 = NULL;
        return;
    }
    Reverse(x);
    if (pos <= getSZ(x->L)) {
        P2 = x;
        Split(x->L, P1, P2->L, pos);
    }
    else if (pos > getSZ(x->L) + 1) {
        P1 = x;
        Split(x->R, P1->R, P2, pos - getSZ(x->L) - 1);
    }
    else {
        P2 = x;
        P1 = x->L;
        P2->L = NULL;
    }
    update(x);
}
 
void Merge(TNode &x, TNode P1, TNode P2) {
    Reverse(P1);
    Reverse(P2);
    if (P1 == P2 && P2 == NULL) {
        x = NULL;
        return;
    }
    if (P1 == NULL) x = P2;
    else if (P2 == NULL) x = P1;
    else if (P1->ran < P2->ran) {
        x = P1;
        Merge(x->R, P1->R, P2);
    }
    else {
        x = P2;
        Merge(x->L, P1, P2->L);
    }
    update(x);
}
 
void Print(TNode x) {
    if (x == NULL) return;
    Reverse(x);
    Print(x->L);
    cout << s[x->key];
    Print(x->R);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    srand(time(NULL));
    root = NULL;
    cin >> n >> q >> s;
    for(int i=0; i<n; ++i) Insert(root, i);
    int x, y;
    while (q--) {
        cin >> x >> y;
        Split(root, P2, P3, y + 1);
        Split(P2, P1, P2, x);
        P2->rev ^= 1;
        Merge(root, P1, P2);
        Merge(root, root, P3);
    }
    Print(root);
}
