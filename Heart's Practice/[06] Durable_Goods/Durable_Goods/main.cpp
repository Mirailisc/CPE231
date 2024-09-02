#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// try_assign = 1 2 3 4
// 4! ways (by using next_permutation(try_assign.begin(), try_assign.end()))
 
float highest_profit(vector<vector<float>> list_cost, int n)
{
    vector<int> try_assign;

    for (int i = 0; i < n; i++)
        try_assign.push_back(i);

    float maxi_cost = 0;

    do
    {
        float cost = 0;
        int i = 0;

        for (auto item : try_assign)
        {
            cost += list_cost[i++][item];
        }

        if (cost > maxi_cost)
            maxi_cost = cost;
    } while (next_permutation(try_assign.begin(), try_assign.end()));

    return maxi_cost;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<float>> list_cost(n, vector<float>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> list_cost[i][j];

    // cout << "size : " << list_cost.size() << endl;
    cout << highest_profit(list_cost, n) << endl;

    return 0;
}
