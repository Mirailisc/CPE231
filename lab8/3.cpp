#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    vector<bool> order(x + 1, false);
    order[0] = true;

    for (int i = 0; i < n; ++i)
    {
        for (int j = p[i]; j <= x; ++j)
        {
            if (order[j - p[i]])
            {
                order[j] = true;
            }
        }
    }

    int largestUnOrder = -1;
    for (int i = x; i >= 0; --i)
    {
        if (!order[i])
        {
            largestUnOrder = i;
            break;
        }
    }

    cout << largestUnOrder << endl;
    return 0;
}
