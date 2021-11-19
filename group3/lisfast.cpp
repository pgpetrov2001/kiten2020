#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

const int maxn = 1e5;

int arr[maxn+1];
int dp[maxn+1];
int prev[maxn+1];

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    arr[n] = INT_MAX;

    fill(dp+1,dp+n+2,INT_MAX);
    dp[0] = INT_MIN;
    int lis = 0;
    for (int i=1; i<=n; i++) {
        int len = upper_bound(dp,dp+i,arr[i-1])-dp;
        lis = max(lis, len);
        dp[len] = arr[i-1];
    }

    cout << lis << "\n";
}
