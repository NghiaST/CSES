#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int n, a[200005];
vector<pair<int,int>> Q;
typedef struct node {
    node *P, *L, *R;
    int key, cnt, rev, pri;
    node(int key, int cnt) : key(key), cnt(cnt), rev(0), P(NULL), L(NULL), R(NULL), pri(rand()) {};
} *TNode;
TNode root, P1, P2, P3, pNode[200005];
 
void Build(TNode &x, int l, int r) {
    int mid = (l+r) / 2;
    pNode[a[mid]] = x = new node(a[mid], r - l + 1);
    if (l < mid) Build(x->L, l, mid-1), x->L->P = x;
    if (mid < r) Build(x->R, mid+1, r), x->R->P = x;
}
 
void Reverse(TNode &x) {
    if (x == NULL) return;
    if (x->rev) {
        x->rev = 0;
        swap(x->L, x->R);
        if (x->L != NULL) x->L->rev ^= 1;
        if (x->R != NULL) x->R->rev ^= 1;
    }
}
 
int getsz(TNode x) {
    if (x == NULL) return 0;
    return x->cnt;
}
 
int get_pos(TNode x) {
    int num = getsz(x->L) + 1;
    if (x->rev) num = x->cnt - num + 1;
    while (x != root) {
        TNode y = x->P;
        if (y->R == x) num += getsz(y->L) + 1;
        if (y->rev) num = y->cnt - num + 1;
        x = y;
    }
    return num;
}
 
void update(TNode &x) {
    if (x == NULL) return;
    x->cnt = getsz(x->L) + getsz(x->R) + 1;
    if (x->L != NULL) x->L->P = x;
    if (x->R != NULL) x->R->P = x;
}
 
void Split(TNode x, TNode &A, TNode &B, int pos) {
    Reverse(x);
    if (x == NULL) {
        A = B = NULL;
        return;
    }
    if (getsz(x->L) + 1 < pos) {
        A = x;
        Split(x->R, A->R, B, pos - getsz(x->L) - 1);
        update(A);
    }
    else {
        B = x;
        Split(x->L, A, B->L, pos);
        update(B);
    }
}
 
void Merge(TNode &x, TNode A, TNode B) {
    Reverse(A);
    Reverse(B);
    if (A == NULL && B == NULL) {
        x = NULL;
        return;
    }
    if (A == NULL) x = B;
    else if (B == NULL) x = A;
    else if (A->pri < B->pri) {
        x = A;
        Merge(x->R, A->R, B);
    }
    else {
        x = B;
        Merge(x->L, A, B->L);
    }
    update(x);
}
 
void setL(TNode &x, TNode &y) {
    if (x != NULL) x->L = y;
    if (y != NULL) y->P = x;
}
 
void Remove_Left(TNode &x) {
    Reverse(x);
    --x->cnt;
    if (x->L != NULL) Remove_Left(x->L);
    else {
        setL(x->P, x->R);
        if (x == root) root = x->R;
    }
}
 
void Solve(int i, int j) {
    if (j != 1) {
        Q.emplace_back(i, i + j - 1);
        Split(root, P1, P2, j + 1);
        if (P1 != NULL) P1->P = NULL;
        if (P2 != NULL) P2->P = NULL;
        P1->rev ^= 1;
        Merge(root, P1, P2);
    }
    Remove_Left(root);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    srand(time(NULL));
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    Build(root, 1, n);
    for(int i=1, j; i<n; ++i) {
        j = get_pos(pNode[i]);
        Solve(i, j);
    }
    cout << Q.size() << '\n';
    for(auto [u,v] : Q) cout << u << ' ' << v << '\n';
}
