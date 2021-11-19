#include <iostream>
using namespace std;

const int MAXN = 1e5;
int arr[MAXN];
int tree[MAXN*4];
int add[MAXN*4];
bool upd[MAXN*4];
int n;

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = arr[l];
        return;
    }
    int m = (l+r)/2;
    build(2*v, l, m);
    build(2*v+1, m+1, r);
    tree[v] = tree[2*v]+tree[2*v+1];
}

void build() {
    build(1, 0, n-1);
}

void prop(int v, int l, int r) {
    tree[v] += (r-l+1)*add[v];
    if (r>l) {
        upd[2*v] = upd[2*v+1] = 1;
        add[2*v]   += add[v];
        add[2*v+1] += add[v];
    }
    upd[v] = 0;
    add[v] = 0;
}

int ans(int v, int l, int r, int ql, int qr) {
    if (upd[v]) {
        prop(v, l, r);
    }
    if (r<ql || l>qr) {
        return 0;
    }
    if (l>=ql && r<=qr) {
        return tree[v];
    }
    int m = (l+r)/2;
    return ans(2*v, l, m, ql, qr) + ans(2*v+1, m+1, r, ql, qr);
}

int ans(int l, int r) {
    return ans(1, 0, n-1, l, r);
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if (upd[v]) {
        prop(v, l, r);
    }
    if (r<ql || l>qr) {
        return;
    }
    if (l>=ql && r<=qr) {
        add[v] = x;
        prop(v, l, r);
        return;
    }
    int m = (l+r)/2;
    update(2*v, l, m, ql, qr, x);
    update(2*v+1, m+1, r, ql, qr, x);
    tree[v] = tree[2*v]+tree[2*v+1];
}

void update(int l, int r, int x) {
    update(1, 0, n-1, l, r, x);
}

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    build();

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        if (q == 1) {
            int l, r;
            cin >> l >> r;
            cout << ans(l,r) << "\n";
        } else if (q == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            update(l,r,x);
        }
    }
}
