#include <iostream>

using namespace std;

//จงนับยังหมุ่ปิ้ง m ว่าทำได้ กี่วิธี จากโจทย์ GP

int WayToBuyGP(vector<int> GP,int m){
    vector<vector<int>> dp(GP.size(),vector<int>(0,m+1));
    for (int i=0;i<GP.size();i++){
        dp[i][GP[i]] += 1;
        for (int j=GP[i];j<=m;j++){
            if (dp[i][j-GP[j]]>0){
                dp[i][j] += 1;
            }
            if (i>0){
                dp[i-1][j-GP[j]] = max(dp[i-1][j], dp[i][j]);
            }
        }
    }
    return 0;
}

int main(){
    int no_item = 4;
    vector<int> GP(no_item);
    for (int i = 0;i<no_item;i++)
        cin >> GP[i];
    int m;
    cin >> m;
    cout << WayToBuyGP(GP,m) << endl;
    return 0;
}
