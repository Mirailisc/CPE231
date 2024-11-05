#include <iostream>
#include <unordered_map>

using namespace std;

void horspool(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    unordered_map<char, int> shiftTable;

    for (int i = 0; i < m - 1; i++) {
        shiftTable[pattern[i]] = m - 1 - i;
    }
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (shiftTable.find(c) == shiftTable.end()) {
            shiftTable[c] = m;
        }
    }

    int shift = 0;
    int totalShifts = 0;

    while (shift <= n - m) {
        int j = m - 1;
        
        while (j >= 0 && text[shift + j] == pattern[j]) {
            j--;
        }
        
        if (j < 0) {
            cout << "YES " << totalShifts << " " << shift << endl;
            return;
        }

        totalShifts++;
        shift += shiftTable[text[shift + m - 1]];
    }

    cout << "NO " << totalShifts << " -1" << endl;
}

int main() {
    int m, n;
    
    cin >> m >> n;
    
    string text, pattern;
    
    cin >> text;
    cin >> pattern;

    horspool(text, pattern);
    
    return 0;
}
