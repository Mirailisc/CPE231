#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int p = arr[l];
    int i = l - 1;
    int j = r + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < p);

        do
        {
            j--;
        } while (arr[j] > p);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quicksort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int s = partition(arr, l, r);
        quicksort(arr, l, s);
        quicksort(arr, s + 1, r);
    }
}

int main()
{
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
