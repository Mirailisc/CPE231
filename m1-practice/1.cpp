#include <iostream>
#include <vector>

using namespace std;

int isEven(int n)
{
    return n % 2 == 0;
}

void findCombinations(int lastNum, int target, int start, vector<int> &currentCombination, int &totalEvenCount, int &totalOddCount)
{
    if (target == 0)
    {
        // Target met, process the combination
        for (int num : currentCombination)
        {
            if (isEven(num))
                totalEvenCount++;
            else
                totalOddCount++;
        }

        return;
    }

    // Find the combinations
    for (int i = start; i <= lastNum; i++)
    {
        if (i > target)
            break;

        currentCombination.push_back(i);

        cout << "i: " << i << endl;
        cout << "target: " << target << endl;
        cout << "start: " << start << endl;

        cout << "Combinations: " << endl;
        // Print combinations
        for (int num : currentCombination)
        {
            cout << "| " << num << " | ";
        }
        cout << endl;

        findCombinations(lastNum, target - i, i + 1, currentCombination, totalEvenCount, totalOddCount);
        currentCombination.pop_back(); // Backtracking function
    }

    cout << endl;
}

int main()
{
    int lastNum;
    int target;

    cin >> lastNum;

    cin >> target;

    vector<int> currentCombination;
    int totalEvenCount = 0;
    int totalOddCount = 0;

    findCombinations(lastNum, target, 1, currentCombination, totalEvenCount, totalOddCount);

    cout << "Answers: " << endl;
    cout << "Even: " << totalEvenCount << endl
         << "Odd: " << totalOddCount << endl;

    return 0;
}

// Given Input : 4 (lastNum) 5 (target)

// start = 1, target = 5, lastNum = 4 : 5 - 1 = 4 -> { 1 }
// start = 2, target = 4, lastNum = 4 : 4 - 2 = 2 -> { 1, 2 }
// start = 3, target = 2, lastNum = 4 : 3 > 2 -> Pop (2) -> { 1 }
// start = 3, target = 4, lastNum = 4 : 4 - 3 = 1 -> { 1, 3 }
// start = 4, target = 0, lastNum = 4 : 4 > 0 -> Pop (3) -> { 1 }
// start = 4, target = 4, lastNum = 4 : 4 - 4 = 0 -> { 1, 4 }
// หาเหึ้ยอะไรก็ออกมา

// start = 2, target = 5, lastNum = 4 : 5 - 2 = 3 -> { 2 }
// start = 3, target = 3, lastNum = 4 : 3 - 3 = 0 -> { 2, 3 }
// หาเหึ้ยอะไรก็ออกมา

// start = 3, target = 5, lastNum = 4 : 5 - 3 = 2 -> { 3 }
// start = 4, target = 1, lastNum = 4 : 1 > 1 -> Pop (3) -> { 3 }
// start = 4, target = 5, lastNum = 4 : 5 - 4 = 1 -> { 3, 4 }
// start = 5, target = 0, lastNum = 4 : 0 > 0 -> Pop (4) -> { 3 }
// start = 5, target = 5, lastNum = 4 : 5 - 5 = 0 -> { 3, 5 }
// หาเหึ้ยอะไรก็ออกมา