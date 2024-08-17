#include <iostream>
#include <vector>

int operationCount = 0;

using namespace std;

int factorial(int n, int sum)
{
  if (n <= 1)
  {
    return sum;
  }
  sum *= n;
  operationCount++; // Increment for multiplication
  return factorial(n - 1, sum);
}

int main()
{
  int n, v, p, facTotal = 1, facExclude = 1;
  cin >> n;
  cin >> v;

  vector<int> total(n);
  operationCount += n; // For filling the vector

  for (int i = 0; i < n; i++)
  {
    cin >> total[i];
  }
  cin >> p;

  vector<int> exclude(p);
  operationCount += p; // For filling the vector

  for (int i = 0; i < p; i++)
  {
    cin >> exclude[i];
  }

  facTotal = factorial(n, facTotal);
  facExclude = factorial(n - 1, facExclude);

  int result;
  result = facTotal - (p * facExclude);
  operationCount++; // For multiplication in result calculation
  operationCount++; // For subtraction in result calculation

  cout << result << endl;
  cout << "Operation Count: " << operationCount << endl;

  // FINAL TIME COMPLEXITY: factorial called 2 times = O(2n) = O(n)
  return 0;
}
