#include <iostream>
#include <vector>

using namespace std;

int GP(vector<int> item, int max)
{
    vector<bool> exist(max + 1, false);
    exist[0] = true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = item[i]; j <= max; j++)
        {
            if (exist[j - item[i]])
                exist[j] = true;
        }
    }

    for (int i = max; i >= 0; i--)
    {
        if (!exist[i])
            return i;
    }
    return 0;
}

int main()
{
    int max;
    vector<int> item(4);
    for (int i = 0; i < 4; i++)
        cin >> item[i];
    cin >> max;
    cout << GP(item, max) << endl;
    return 0;
}
