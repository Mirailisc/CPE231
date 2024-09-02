#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arg_beads(int n, int start_beads, int coef)
{
    vector<int> beads;
    int j = start_beads;
    beads.push_back(j);
    for (int i = start_beads + 1; i < start_beads + n; i++)
    {
        j += coef;
        beads.push_back(j);
    }
    return beads;
}

vector<int> delta_beads(vector<int> beads1, vector<int> beads2)
{
    vector<int> delta;
    for (int i = 0; i < beads1.size(); i++)
    {
        delta.push_back(abs(beads1[i] - beads2[i]));
    }
    return delta;
}

vector<int> findMinimizeDeltaMinBeads(vector<int> beads)
{
    int i = 1;
    vector<int> delta, deltaC;
    bool isFound = false;
    while (true)
    {
        delta = delta_beads(beads, arg_beads(beads.size(), beads.front(), i));
        for (int j = 0; j < delta.size() - 1; j++)
        {
            if (delta[j] > delta[j + 1] && isFound)
            {
                return deltaC;
            }
        }
        deltaC = delta;
        isFound = true;
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> beads(n);
    for (int i = 0; i < n; i++)
        cin >> beads[i];
    for (auto i : findMinimizeDeltaMinBeads(beads))
    { // findMinimizeDeltaMinBeads(beads)
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
