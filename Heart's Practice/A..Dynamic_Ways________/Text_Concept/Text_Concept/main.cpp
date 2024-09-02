#include <iostream>
#include <vector>

using namespace std;


int countWaysToBuy(int m, vector<int>& prices) {
    vector<int> dp(m + 1, 0);
    dp[0] = 1;  // มี 1 วิธีในการรวมเป็น 0 บาท (คือการไม่ซื้ออะไรเลย)

    for (int price : prices) {
        for (int j = price; j <= m; ++j) {
            dp[j] += dp[j - price];
        }
    }

    return dp[m];
}

int countWaysToBuy2(int m, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // ไม่มีสินค้าเลยก็มี 1 วิธีในการรวมเป็น 0 บาท
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1]) {
                dp[i][j] += dp[i][j - prices[i - 1]];
            }
        }
    }

    return dp[n][m];
}

int MaxGP_B(int n,vector<int> G){
    int ways = 0;
    int c1 = n/G[0];
    int c2 = n/G[1];
    int c3 = n/G[2];
    int c4 = n/G[3];
    for (int a=0;a<=c1;a++){
        for (int b=0;b<=c2;b++){
            for (int c=0;c<=c3;c++){
                for (int d=0;d<=c4;d++){
                    int sum = G[0]*a + G[1]*b + G[2]*c + G[3]*d;
                    if (sum == n){
                        ways++;
                    }
                }
            }
        }
    }
    return ways;
}

int main() {
    vector<int> prices(4);
    int m;

    //cout << "Enter the prices of 4 items: ";
    for (int i = 0; i < 4; ++i) {
        cin >> prices[i];
    }

    //cout << "Enter the maximum amount of money you have: ";
    cin >> m;

    int ways = countWaysToBuy(m, prices);
    cout << "Number of ways to buy with " << m << " baht: " << ways << endl;
    ways = countWaysToBuy2(m,prices);
    cout << "Number of ways to buy with " << m << " baht: " << ways << endl;

    return 0;
}
