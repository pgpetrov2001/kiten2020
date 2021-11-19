#include <iostream>
using namespace std;

int dp[1000][1000];

int main() {
    int n, k;
    cin >> n >> k;

    //n=1, k=0
    dp[1][0] = 1;

    for (int i=2; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            for (int l=j; l>=j-i+1; l--) {
                dp[i][j] += dp[i-1][l];
            }

            /*redove n; koloni k;
            izchisliavame za kletka 5;j
            k=j:   _x_x_x_x5 +0=j
            k=j-1: _x_x_x5x_ +1=j
            k=j-2: _x_x5x_x_ +2=j
            k=j-3: _x5x_x_x_ +3=j
            k=j-4: 5x_x_x_x_ +4=j
            dp[5][j] = dp[4][j]+dp[4][j-1]+dp[4][j-2]+dp[4][j-3]
            +dp[4][j-4];

            izchisliavame za kletka n;j
            k=j:   _x_x_x_x5 +0=j
            k=j-1: _x_x_x5x_ +1=j
            k=j-2: _x_x5x_x_ +2=j
            k=j-3: _x5x_x_x_ +3=j
            k=j-4: 5x_x_x_x_ +4=j
            dp[n][j] = dp[n-1][j]+dp[n-1][j-1]+
            dp[n-1][j-2]+dp[n-1][j-3]+dp[n-1][j-4];

            for (int l=j; l>=j-i+1; l--)



            k=5:   _x_x_x_xy +0=5
            k=5-1: _x_x_xyx_ +1=5
            k=5-2: _x_xyx_x_ +2=5
            k=5-3: _xyx_x_x_ +3=5
            k=5-4: yx_x_x_x_ +4=5

            k=2:   _x_x_x_xy +0=2
            k=2-1: _x_x_xyx_ +1=2
            k=2-2: _x_xyx_x_ +2=2
            k=2-3: _xyx_x_x_ +3=2 //bez tova
            k=2-4: yx_x_x_x_ +4=2 //bez tova*/
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
