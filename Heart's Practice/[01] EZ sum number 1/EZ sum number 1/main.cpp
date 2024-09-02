#include <iostream>
#include <vector>

using namespace std;

// it very brute force O(2^n * n) it crazy!!!
vector<int> arth(int number)
{
    vector<int> set;
    for (int i = 1; i <= number; i++)
    {
        set.push_back(i);
    }
    return set;
}

vector<int> binary(int dec, int len)
{
    int i = dec;
    vector<int> bin;
    while (i > 0)
    {
        bin.push_back(i % 2);
        i /= 2;
    }
    for (int i = (int)bin.size(); i < len; i++)
        bin.push_back(0);
    return bin;
}

vector<int> EzSumX(int n, int want_n)
{ // brute force all possible
    vector<int> set_item = arth(n);
    vector<int> O_E(2, 0);
    int o, e;
    int sum;
    int count = 0;
    for (int i = 1; i < pow(2, n); i++)
    {
        sum = 0;
        o = 0;
        e = 0;
        vector<int> selector = binary(i, pow(2, n));
        for (int j = 0; j < n; j++)
        {
            if (selector[j])
            {
                sum += set_item.at(j);
                if (set_item.at(j) % 2 == 0)
                    e++;
                else
                    o++;
            }
        }
        if (sum == want_n)
        {
            count++;
            O_E[0] += o;
            O_E[1] += e;
        }
    }
    return O_E;
}

int main()
{
    int n, want_n;
    cin >> n >> want_n;
    vector<int> CurrentComb;
    pair<int, int> O_E = {0, 0};
    EzSumX(n, want_n);
    cout << O_E.first << endl
         << O_E.second << endl;

    return 0;
}
