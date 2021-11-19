#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1e5;

struct Edge {
    int v;
    ll w;
};

vector<Edge> g[MAXN+1];
ll sumPaths[MAXN+1], cntPaths[MAXN+1];

ll dfs(int u, int p=0) {
    ll sum = 0;
    ll cntPathsRest = 0;
    ll sumPathsRest = 0;

    for (auto e : g[u]) {
        if (e.v == p) continue;
        sum += dfs(e.v, u);
        cntPathsRest += cntPaths[e.v];
        sumPaths[e.v] += e.w*cntPaths[e.v];
        sumPathsRest += sumPaths[e.v];
    }

    sum += sumPaths[u] = sumPathsRest;
    cntPaths[u] = cntPathsRest+1;

    for (auto e : g[u]) {
        if (e.v == p) continue;
        cntPathsRest -= cntPaths[e.v];
        sumPathsRest -= sumPaths[e.v];
        sum += cntPaths[e.v]*sumPathsRest + sumPaths[e.v]*cntPathsRest;
    }

    //1-2-3-4-5
    //10 + 6 + 3 + 1 = 20

    return sum;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    cout << dfs(1) << endl;
}
