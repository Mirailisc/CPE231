#include <iostream>
#include <vector>
#include <algorithm>

/*
    Practice 3 : FakeBeads

    If I have a collection of Beads
    Ex. Given Input
    Number of beads: 10
    Beads position: 1 4 5 10 13 15 18 22 25 30

    I have to find the minimum distance to move each bead to its correct position
    So, I this case the minimum distance of each beads are 1 - 10 (index)

    And I have to move each beads to the minimum distance

    The result = Bead position (vector bead[i]) - Loop Index (i) - 1

    1 - (0) - 1
    4 - (1) - 1
    5 - (2) - 1
    10 - (3) - 1
    13 - (4) - 1
    15 - (5) - 1
    18 - (6) - 1
    22 - (7) - 1
    25 - (8) - 1
    30 - (9) - 1

    The Output should be : 0 2 2 6 8 9 11 14 16 20
*/

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

    int min_diff = beads[1] - beads[0];
    for (int i = 1; i < totalBeads - 1; i++)
    {
        min_diff = min(min_diff, beads[i + 1] - beads[i]);
    }

    int correct_position = beads[0];
    for (int i = 0; i < totalBeads; i++)
    {
        int diff = beads[i] - correct_position;
        result.push_back(diff);
        correct_position += min_diff;
    }

    for (int i = 0; i < totalBeads; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
