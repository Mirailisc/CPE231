#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int &x : seq)
        cin >> x;

    vector<int> up(n, 1), down(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (seq[i] > seq[j])
            {
                up[i] = max(up[i], down[j] + 1);
            }
            else if (seq[i] < seq[j])
            {
                down[i] = max(down[i], up[j] + 1);
            }
        }
    }

    for (int x : up)
        cout << x << " ";
    cout << endl;
    for (int x : down)
        cout << x << " ";
    cout << endl;

    return 0;
}