#include <iostream>
#include <vector>
#include <stack>

using std::cout;using std::cin;using std::flush;using std::min;using std::vector;using std::stack;using std::endl;


const int MAXN = 2e5;
vector<int> adj[MAXN+1];
int lra[MAXN+1];
bool visited[MAXN+1];
int parent[MAXN+1];
int depth[MAXN+1];
int component[MAXN+1];
stack<int> s;

void dfs(int u) {
    s.push(u);
    visited[u] = true;
    lra[u] = depth[u];

    for (int v : adj[u]) {
        if (v == parent[u]) {
            continue;
        }
        if (!visited[v]) {
            depth[v] = depth[u]+1;
            parent[v] = u;
            dfs(v);
            lra[u] = min(lra[u], lra[v]);
            printf("rebro1 %d->%d, updating lra[%d]=%d\n",u,v,u,lra[u]);
        } else {
            lra[u] = min(lra[u], depth[v]);
            printf("rebro2 %d->%d, updating lra[%d]=%d\n",u,v,u,lra[u]);
        }
    }

    if (lra[u] == depth[u]) {
        printf("component %d: ", u);
        while (s.top() != u) {
            component[s.top()] = u;
            cout << s.top() << " ";
            s.pop();
        }
        cout << u << endl;
        component[u] = u;
        s.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    printf("articulation edges:\n");
    for (int u=1; u<=n; u++)
        for (int v : adj[u])
            if (v>u && component[u] != component[v]) {
                cout << u << "->" << v << endl;
            }
}
