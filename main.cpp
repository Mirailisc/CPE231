#include <iostream>
#include <vector>

using namespace std;

void sortDescending(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void sortAscending(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> treeHeight(n);
  vector<int> treePotHeight(n);
  vector<int> treeSum(n);

  for (int i = 0; i < n; i++)
  {
    cin >> treeHeight[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> treePotHeight[i];
  }

  sortDescending(treeHeight);
  sortAscending(treePotHeight);

  cout << "Sorted data: " << endl;

  // Print sorted data
  for (int i = 0; i < n; i++)
  {
    cout << treeHeight[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << treePotHeight[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    treeSum[i] = treeHeight[i] + treePotHeight[i];
  }

  int minSum = treeSum[0];
  int maxSum = treeSum[0];
  for (int i = 1; i < n; i++)
  {
    if (treeSum[i] < minSum)
    {
      minSum = treeSum[i];
    }
    if (treeSum[i] > maxSum)
    {
      maxSum = treeSum[i];
    }
  }

  int minDiff = maxSum - minSum;

  cout << minDiff << endl;

  return 0;
}
