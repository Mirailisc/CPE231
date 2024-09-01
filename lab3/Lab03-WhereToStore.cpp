// 66070501040 Phubordin Poolnai

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
    string name;
    cin >> name;
    vector<int> start, stop;

    for (int i = 0; i < name.length(); ++i) {
        for (int j = i + 1; j < name.length(); ++j) {
            if (name[i] == name[j]) {
                start.push_back(i);
                stop.push_back(j);
            }
        }
    }

    vector<string> words;

    for (int i = 0; i < start.size(); ++i) {
        words.push_back(string(1, name[start[i]]) + name[stop[i]]);
        string substring_between = name.substr(start[i] + 1, stop[i] - start[i] - 1);
        map<char, int> char_count;

        for (char c : substring_between) {
            char_count[c]++;
        }

        for (const auto& pair : char_count) {
            for (int k = 0; k < pair.second; ++k) {
                string new_word = string(1, name[start[i]]) + string(k + 1, pair.first) + name[stop[i]];
                words.push_back(new_word);

                if (i != 0) {
                    for (int l = 0; l < i; ++l) {
                        if (stop[start[l]] > stop[i] && name[start[l]] != new_word[0]) {
                            words.push_back(string(1, name[start[l]]) + new_word + name[start[l]]);
                        }
                    }
                }
            }
        }
    }

    set<string> uniqueWords(words.begin(), words.end());
    cout << uniqueWords.size() << endl;

    return 0;
}