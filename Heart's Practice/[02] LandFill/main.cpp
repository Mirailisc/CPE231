#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int rough(vector<int> land)
{
    int sum = 0;
    for (int i = 0; i < land.size() - 1; i++)
        sum += abs(land[i] - land[i + 1]);
    return sum;
}

vector<int> lmr_expand(vector<int> lmr)
{
    vector<int> land;
    for (int i = lmr[0]; i <= lmr[1]; i++)
        land.push_back(i);
    for (int i = lmr[1] - 1; i >= lmr[2]; i--)
        land.push_back(i);
    return land;
}

bool isCheck_Not_OverBoundaries(int fill_at_begin_of_lmr, vector<int> lmr_expand, vector<int> land_fill)
{ // beginPos 0 to n-1
    return fill_at_begin_of_lmr <= (land_fill.size() - lmr_expand.size()) ? true : false;
}

vector<int> bin(int dec, int n)
{
    vector<int> a;
    int B = dec;
    int j = 0;
    while (B > 0)
    {
        a.insert(a.begin(), B % 2);
        B /= 2;
        j++;
    }
    for (; j < n; j++)
        a.insert(a.begin(), 0);
    return a;
}

vector<int> MergeLand(int fill_at_begin_of_lmr, vector<int> lmr_expand, vector<int> land_fill)
{
    vector<int> new_land_fill = land_fill;
    // if (isCheck_Not_OverBoundaries(fill_at_begin_of_lmr,lmr_expand,land_fill)){
    for (int i = 0; i < lmr_expand.size(); i++)
        new_land_fill[fill_at_begin_of_lmr + i] += lmr_expand[i];
    return new_land_fill;
    //}
    // return {};
}

int MinimumRoughLandFill(vector<int> unadj_land, vector<int> lmr_expand)
{
    int bound = unadj_land.size() - lmr_expand.size() + 1;
    int possible = pow(2, bound);
    int minimizer = INT_MAX;
    for (int i = 0; i < possible; i++)
    {
        vector<int> allow = bin(i, bound);
        vector<int> done_land_fill = unadj_land;
        for (int j = 0; j < bound; j++)
        {
            if (allow[j])
                done_land_fill = MergeLand(j, lmr_expand, done_land_fill);
        }
        int rough_done = rough(done_land_fill);
        if (rough_done < minimizer)
            minimizer = rough_done;
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
