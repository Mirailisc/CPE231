// Practice 3 : FakeBeads

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int totalBeads;
    vector<int> beads;
    vector<int> result;

    cin >> totalBeads;

    for (int i = 0; i < totalBeads; i++)
    {
        int bead;
        cin >> bead;
        beads.push_back(bead);
    }

    for (int i = 0; i < totalBeads; i++)
    {
        int diff = beads[i] - i - 1;

        result.push_back(diff);
    }

    for (int i = 0; i < totalBeads; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}