#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    int even,odd;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    vector<vector<vector<int>>> paths(x + 1);
    paths[0].push_back({});
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= i; --j) {
            if (dp[j - i] > 0) {
                for (auto path : paths[j - i]) {
                    path.push_back(i);
                    paths[j].push_back(path);
                }
            }
            dp[j] += dp[j - i];
        }
    }
    even = 0;
    odd = 0;
    for (auto path : paths[x]) {
        for (int num : path) {
            if (num % 2 == 1){
                odd+=1;
            }else if (num % 2 == 0){
                even+=1;
            }
        }
    }
    cout<<odd<<endl;
    cout<<even;
    return 0;
}
