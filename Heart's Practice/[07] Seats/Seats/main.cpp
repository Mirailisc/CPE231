#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef struct stu
{
    string name;
    int score;
    int priority;
} stu;

void selection_sort_stu(vector<stu> unsort, int n)
{
    for (int i = 0; i < n - 2; i++) // Selection Sort
    {
        int con = i;
        for (int j = i + 1; j < n - 1; j++)
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
    // return unsort;
}

int main()
{
    int n;
    cin >> n;
    
    vector<stu> student_list(n), sort_score_student(n);
    
    // map<int, int> priority; // priority[key] = 0
    
    for (int i = 0; i < n; i++)
    {
        cin >> student_list[i].name >> student_list[i].score;
        student_list[i].priority = i;
        // student_list[i].priority = priority[student_list[i].score]++;
        // 1040 70 (0)
        // ... (...)
        // 3441 70 (1)
    }
    
    selection_sort_stu(student_list, n);
    
    for (auto s : sort_score_student)
        cout << s.name << endl;
    
    return 0;
}
