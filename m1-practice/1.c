// Practice 1 : Combination Odd and Even number

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

    for (int i = start; i <= lastNum; i++)
    {
        if (i > target)
            break;

        currentCombination.push_back(i);
        findCombinations(lastNum, target - i, i + 1, currentCombination, totalEvenCount, totalOddCount);
        currentCombination.pop_back();
    }
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

    cout << totalEvenCount << totalOddCount << endl;

    return 0;
}
