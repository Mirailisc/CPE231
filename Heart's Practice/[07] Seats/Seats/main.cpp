#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct stu
{
    string name;
    int score;
    int priority;
} stu;

void selection_sort_stu(vector<stu> &unsort, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int con = i;
        for (int j = i + 1; j < n; j++)
        {
            if (unsort[j].score > unsort[con].score)
            {
                con = j;
            }
            else if (unsort[j].score == unsort[con].score)
            {
                if (unsort[j].priority < unsort[con].priority)
                    con = j;
            }
        }
        swap(unsort[i], unsort[con]); // required <algorithm>
    }
}

int main()
{
    int n;
    cin >> n;

    vector<stu> student_list(n);

    for (int i = 0; i < n; i++)
    {
        cin >> student_list[i].name >> student_list[i].score;
        student_list[i].priority = i;
    }

    selection_sort_stu(student_list, n);

    for (auto s : student_list) // Printing the sorted list
        cout << s.name << endl;

    return 0;
}
