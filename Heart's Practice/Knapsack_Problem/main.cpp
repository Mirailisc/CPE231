#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int> &weights, const vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // dp[n][W]
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5};
    vector<int> values = {1, 2, 3, 4, 5};
    int W = 11;
    int n = weights.size();
    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;
    return 0;
}
