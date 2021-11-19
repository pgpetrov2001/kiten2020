#include <iostream>
using namespace std;

typedef long long ll;

ll dp[1001][1001];

int main() {
    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int speed=1; speed<=n; speed++) {
        for (int groups=1; groups<=speed; groups++) {
            dp[speed][groups] += dp[speed-1][groups-1];
            dp[speed][groups] += dp[speed-1][groups] * (speed-1);
            cout << dp[speed][groups] << " ";
        }
        cout << "\n";
    }
    
}
