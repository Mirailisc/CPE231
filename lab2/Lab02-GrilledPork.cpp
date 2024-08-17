#include <iostream>

using namespace std;

int grilledPork(int i, int j, int k, int l, int n, int &operationCount)
{
    int values[n];
    for (int m = 0; m < n; m++)
    {
        values[m] = 0;
        operationCount++; // Increment for array initialization
    }

    int number = 0;

    for (int a = 0; a <= n / i; a++)
    {
        for (int b = 0; b <= n / j; b++)
        {
            for (int c = 0; c <= n / k; c++)
            {
                for (int d = 0; d <= n / l; d++)
                {
                    number = a * i + b * j + c * k + d * l;
                    operationCount++; // Increment for each combination

                    if (number <= n)
                    {
                        values[number - 1] = 1;
                        operationCount++; // Increment for setting array value
                    }
                }
            }
        }
    }

    for (int m = n - 1; m >= 0; m--)
    {
        operationCount++; // Increment for each check in the loop
        if (values[m] == 0)
        {
            return m + 1;
        }
    }

    return -1;
}

int main()
{
    int i, j, k, l;
    cin >> i >> j >> k >> l;

    int n;
    cin >> n;

    int operationCount = 0;

    cout << grilledPork(i, j, k, l, n, operationCount) << endl;
    cout << "Operation Count: " << operationCount << endl;

    // FINAL TIME COMPLEXITY : O((n/i) * (n/j) * (n/k) * (n/l)) = O(n^4 / (i * j * k * l)) = O(n^4)
    return 0;
}
