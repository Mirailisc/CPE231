#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxLuxuryValue(int n, vector<pair<int, int>> &items, int p)
{
    vector<int> val(p + 1, 0);

    for (const auto &item : items)
    {
        int clutter = item.first;
        int luxury = item.second;
        for (int j = p; j >= clutter; --j)
        {
            val[j] = max(val[j], val[j - clutter] + luxury);
        }
    }

    return val[p];
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i)
    {
        int clutter, luxury;
        cin >> clutter >> luxury;
        items[i] = make_pair(clutter, luxury);
    }

    int p;
    cin >> p;

    cout << findMaxLuxuryValue(n, items, p) << endl;

    return 0;
}
