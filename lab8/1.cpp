#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    vector<int> dp_true(n, 1), dp_false(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (x[i] > x[j])
            {
                dp_true[i] = max(dp_true[i], dp_false[j] + 1);
            }
            else if (x[i] < x[j])
            {
                dp_false[i] = max(dp_false[i], dp_true[j] + 1);
            }
        }
    }

    for (int i : dp_true)
        cout << i << " ";
    cout << endl;

    for (int i : dp_false)
        cout << i << " ";
    cout << endl;

    return 0;
}
