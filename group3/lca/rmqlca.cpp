#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;

vector<int> red;
int tree[4 * MAX_N];
int arr[MAX_N];
vector<int> g[MAX_N];
int d[MAX_N];

void upd(int curr, int l, int r, int ind, int val) {
    if(l == r && l == ind) {
        tree[curr] = val;
        return;
    } else if(ind > r || ind < l) {
        return;
    }
    int m = (l + r) / 2;
    upd(curr * 2, l, m, ind, val);
    upd(curr * 2 + 1, m + 1, r, ind, val);
    if(d[tree[curr * 2]] < d[tree[curr * 2 + 1]]) {
        tree[curr] = tree[curr * 2];
    } else {
        tree[curr] = tree[curr * 2 + 1];
    }
}

int mn(int curr, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) {
        return MAX_N - 1;
    } else if(ql <= l && r <= qr) {
        return tree[curr];
    }
    int m = (l + r) / 2;
    int tmpl = mn(curr * 2, l, m, ql, qr);
    int tmpr = mn(curr * 2 + 1, m + 1, r, ql, qr);
    if(d[tmpl] < d[tmpr]) {
        return tmpl;
    } else {
        return tmpr; 
    }
}

int in[MAX_N], tme = 0;

int n, q;

void dfs(int x, int p) {
    d[x] = d[p] + 1;
    in[x] = red.size();//tme = red.size() - 1;
    upd(1, 0, 2 * n - 2, red.size(), x);
    red.push_back(x);//tme = red.size() - 1;
    cout << x << " ";
    for(auto it : g[x]) {
        if(it == p) {continue;}
        dfs(it, x);
        upd(1, 0, 2 * n - 2, red.size(), x);
        red.push_back(x);
        cout << x << " ";
    }
}

int main() {
    d[MAX_N - 1] = 696969420;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> q;
    dfs(1, 0);    
    cout << q << endl;
    while(q --) {
        int a, b;
        cin >> a >> b;
        if(in[a] > in[b]) {swap(a, b);}
        cout << "Here " << a << " " << b << endl;
        cout << mn(1, 0, 2 * n - 2, in[a], in[b]) << endl;
    }
}
