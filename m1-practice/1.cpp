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
        currentCombination.pop_back();
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
