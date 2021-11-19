#include <iostream>
using namespace std;

int dp[1000][1000];

int main() {
    int n, k;
    cin >> n >> k;

    //n=1, k=0
    dp[1][0] = 1;

    for (int i=2; i<=n; i++) {
        dp[i][0] = 1;
        for (int j=1; j<=k; j++) {
            if (j-i>=0) {
                dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-i];
            } else {
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
