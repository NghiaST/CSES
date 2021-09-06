#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int n, q, a[200005];
 
typedef struct node{
    node *L, *R;
    int key, ran, rev, sz;
    long long sum;
} *TNode;
TNode nil, root, P1, P2, P3;
 
void Init() {
    srand(time(NULL));
    nil = new node;
    nil->L = nil->R = nil;
    nil->key = nil->rev = nil->sum = nil->sz = 0;
    nil->ran = 0x3c3c3c3c;
    root = nil;
}
 
TNode New(int pos) {
    TNode x = new node;
    x->L = x->R = nil;
    x->key = a[pos];
    x->ran = pos;
    x->rev = 0;
    x->sz = 1;
    x->sum = a[pos];
    return x;
}
 
void update(TNode &x) {
    x->sz = x->L->sz + x->R->sz + 1;
    x->sum = x->L->sum + x->R->sum + x->key;
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
    if (x == nil) return;
    if (x->rev) {
        swap(x->L, x->R);
        x->L->rev ^= 1;
        x->R->rev ^= 1;
        x->rev = 0;
    }
}
 
void Build(TNode &x, int l, int r) {
    if (l > r) return;
    int mid = (l+r) / 2;
    x = New(mid);
    Build(x->L, l, mid - 1);
    Build(x->R, mid + 1, r);
    update(x);
}
 
void Split(TNode x, TNode &P1, TNode &P2, int pos) {
    if (x == nil) {
        P1 = P2 = nil;
        return;
    }
    Reverse(x);
    if (pos <= x->L->sz) {
        P2 = x;
        Split(x->L, P1, P2->L, pos);
    }
    else if (pos > x->L->sz + 1) {
        P1 = x;
        Split(x->R, P1->R, P2, pos - x->L->sz - 1);
    }
    else {
        P2 = x;
        P1 = x->L;
        P2->L = nil;
    }
    update(x);
}
 
void Merge(TNode &x, TNode P1, TNode P2) {
    Reverse(P1);
    Reverse(P2);
    if (P1 == P2 && P2 == nil) {
        x = nil;
        return;
    }
    if (P1->ran < P2->ran) {
        x = P1;
        Merge(x->R, P1->R, P2);
    }
    else {
        x = P2;
        Merge(x->L, P1, P2->L);
    }
    update(x);
}
 
long long get(TNode x, int pos) {
    if (pos == 0) return 0;
    Reverse(x);
    if (pos <= x->L->sz) return get(x->L, pos);
    else if (pos > x->L->sz + 1) return x->L->sum + x->key + get(x->R, pos - x->L->sz - 1);
    else return x->L->sum + x->key;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    cin >> n >> q;
    int type, x, y;
    for(int i=1; i<=n; ++i) cin >> a[i];
    Build(root, 1, n);
    while (q--) {
        cin >> type >> x >> y;
        if (type == 1) {
            Split(root, P2, P3, y + 1);
            Split(P2, P1, P2, x);
            P2->rev ^= 1;
            Merge(root, P1, P2);
            Merge(root, root, P3);
        }
        else cout << get(root, y) - get(root, x-1) << '\n';
    }
}
