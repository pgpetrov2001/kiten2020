#include <iostream>
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN+1];
int depth[MAXN+1];
int parent[MAXN+1][18];
int n;

void precompute(int u) {
    int lev = 1;
    while (depth[parent[u][lev-1]] >= (1<<(lev-1))-1) {
        parent[u][lev] = parent[parent[u][lev-1]][lev-1];
        lev++;
    }
}

void dfs(int u) {
    for (int v : adj[u]) 
        if (v != parent[u][0]) {
            parent[v][0] = u;
            depth[v] = depth[u]+1;
            precompute(v);
            dfs(v);
        }
}

int main() {
    cin >> n;

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v);
    }
}
