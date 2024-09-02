#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int rough(const vector<int> &land)
{
    int sum = 0;
    for (int i = 0; i < land.size() - 1; i++)
        sum += abs(land[i] - land[i + 1]);
    return sum;
}

vector<int> lmr_expand(const vector<int> &lmr)
{
    vector<int> land;
    for (int i = lmr[0]; i <= lmr[1]; i++)
        land.push_back(i);
    for (int i = lmr[1] - 1; i >= lmr[2]; i--)
        land.push_back(i);
    return land;
}

int MinimumRoughLandFill(vector<int> &unadj_land, const vector<int> &lmr_expand)
{
    int n = unadj_land.size();
    int m = lmr_expand.size();
    int minimizer = rough(unadj_land);

    for (int i = 0; i <= n - m; i++)
    {
        vector<int> done_land_fill = unadj_land;
        for (int j = 0; j < m; j++)
        {
            done_land_fill[i + j] += lmr_expand[j];
        }
        minimizer = min(minimizer, rough(done_land_fill));
    }
    return minimizer;
}

int main()
{
    int n;
    cin >> n;
    vector<int> unadj_land(n);
    vector<int> lmr(3);
    for (int i = 0; i < n; i++)
        cin >> unadj_land[i];
    for (int i = 0; i < 3; i++)
        cin >> lmr[i];
    vector<int> lmr_add = lmr_expand(lmr);

    cout << MinimumRoughLandFill(unadj_land, lmr_add) << endl;
    return 0;
}
