#include <iostream>
using namespace std;
const int N = 800005;
int n, q, n_arr = 1, a[N];
typedef struct Data{
    Data *L, *R;
    long long sum;
} *node;
node ver[N];
 
void build(node &root, int l, int r) {
    root = new Data;
    if (l == r) {
        root->sum = a[l];
        return;
    }
    int mid = (l+r) / 2;
    build(root->L, l, mid);
    build(root->R, mid+1, r);
    root->sum = root->L->sum + root->R->sum;
}
 
void update(node &new_root, node root, int l, int r, int x, int val) {
    new_root = new Data;
    if (l == r) {
        new_root->sum = val;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) {
        update(new_root->L, root->L, l, mid, x, val);
        new_root->R = root->R;
    }
    else {
        new_root->L = root->L;
        update(new_root->R, root->R, mid+1, r, x, val);
    }
    new_root->sum = new_root->L->sum + new_root->R->sum;
}
 
long long query(node root, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return root->sum;
    int mid = (l+r) / 2;
    return query(root->L, l, mid, x, y) + query(root->R, mid+1, r, x, y);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int type, arr, x, y, val;
    for(int i=1; i<=n; ++i) cin >> a[i];
    build(ver[1], 1, n);
    for(int i=1; i<=q; ++i) {
        cin >> type >> arr;
        if (type == 1) {
            cin >> x >> val;
            node old_root = ver[arr];
            update(ver[arr], old_root, 1, n, x, val);
        }
        else if (type == 2) {
            cin >> x >> y;
            cout << query(ver[arr], 1, n, x, y) << '\n';
        }
        else if (type == 3) {
            ver[++n_arr] = ver[arr];
        }
    }
}
