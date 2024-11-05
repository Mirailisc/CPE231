#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void RemoveDuplicatesAndPrint(vector<int> &A)
{
    sort(A.begin(), A.end());

    cout << A[0] << " ";
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] != A[i - 1])
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    RemoveDuplicatesAndPrint(A);
}
