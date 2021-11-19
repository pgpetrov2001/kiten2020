#include <iostream>
#include <vector>
#include <stack>

using std::cin; using std::cout; using std::endl; using std::vector;
using std::stack; using std::min;

const int MAXN = 2e5;
vector<int> adj[MAXN+1];
int LRA[MAXN+1];
bool visited[MAXN+1];
int parent[MAXN+1];
int depth[MAXN+1];
int component[MAXN+1];
stack<int> s;

void dfs(int u) {
    s.push(u);
    visited[u] = true;
    LRA[u] = depth[u];

    for (int v : adj[u]) {
        if (v == parent[u]) {
            continue;
        }

        if (visited[v]) {
            LRA[u] = min(LRA[u], depth[v]);
            printf("rebro1 %d->%d updating LRA[%d]=%d\n", u,v,u,LRA[u]);
        } else {
            depth[v] = depth[u]+1;
            parent[v] = u;
            dfs(v);
            LRA[u] = min(LRA[u], LRA[v]);
            printf("rebro2 %d->%d updating LRA[%d]=%d\n", u,v,u,LRA[u]);
        }
    }

    if (LRA[u] == depth[u]) {
        printf("component %d: ", u);
        while (s.top() != u) {
            cout << s.top() << " ";
            component[s.top()] = u;
            s.pop();
        }
        cout << s.top() << endl;
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

    puts("articulation edges:");

    for (int u=1; u<=n; u++)
        for (int v : adj[u])
            if (v>u && component[u] != component[v]) {
                printf("%d->%d\n", u, v);
            }
}
