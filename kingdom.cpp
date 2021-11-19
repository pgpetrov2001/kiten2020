#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e5;

vector<int> adj1[maxn+1];
vector<int> adj[maxn+1];

void dfs1(int u, int p=0) {
    for (int v : adj1[u]) {
        if (v != p) {
            adj[u].push_back(v);
            dfs1(v, u);
        }
    }
}

//dp[i][x] - za decata na vurha do tova s index i vuv spisuka mu na susedite,
//po kolko nachina mojem da gi ocvetim taka che da supportvat vurha(x=1) ili da ne supportvat vurha(x=0)
ll dp[maxn][2];

ll dfs(int u, bool supported) {
    if (adj[u].size() == 0) {
        return 1;
    }

    dp[0][0] = dfs(adj[u][0], 0);
    dp[0][1] = dfs(adj[u][0], 1);
    for (int i=1; i<adj[u].size(); i++) {
        ll ways0 = dfs(adj[u][i],1), ways1 = dfs(adj[u][i],0); 
        dp[i][0] = (dp[i-1][0]*ways0)%mod;
        dp[i][1] = (dp[i-1][0]*ways1)%mod;
        dp[i][1] += (dp[i-1][1]*(ways0+ways1)%mod)%mod;
        dp[i][1] %= mod;
    }
    ll ans = dp[adj[u].size()-1][1];
    if (supported) {
        ans += dp[adj[u].size()-1][0];
        ans %= mod;
    } 
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    dfs1(1);
    cout << 2*dfs(1,0) << "\n";
}
