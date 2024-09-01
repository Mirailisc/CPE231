// 66070501040 Phubordin Poolnai

#include <iostream>
#include <string>

using namespace std;

int countValidSubstrings(const string &bead, char a, char b, int p)
{
  int n = bead.length();
  int count = 0;

  for (int start = 0; start < n; ++start)
  {
    if (bead[start] == a)
    {
      for (int end = start + p - 1; end < n; ++end)
      {
        if (bead[end] == b)
        {
          if (end - start + 1 >= p)
          {
            count++;
          }
        }
      }
    }
  }

  return count;
}

int main()
{
  string bead;
  char a, b;
  int p;

  cin >> bead;
  cin >> a >> b;
  cin >> p;

  cout << countValidSubstrings(bead, a, b, p) << endl;

  return 0;
}
