#include <iostream>
#include <vector>

using namespace std;
/*
int GP(vector<int> item,int max){
    bool dp[max];
    memset(dp,false,sizeof(dp));
    vector<int> GP_item_all_possible;
    for (auto i : item){
        int j=1;
        while (j*i<=max){
            cout << j*i << endl;
            if (!dp[j*i]){
                GP_item_all_possible.push_back(j*i);
                dp[j*i] = true;
            }
            j++;
        }
    }
    
    bool exist[max+1];
    for (int i=0;i<GP_item_all_possible.size();i++){
        for (int j=0;j<GP_item_all_possible.size();j++){
            int sum = GP_item_all_possible[i]+GP_item_all_possible[j];
            if (sum <= max){
                exist[sum] = true;
            }
        }
    }
    
    for (int i=max;i>=0;i--){
        if (!exist[i])
            return i;
    }
    return 0;
}*/

int GP(vector<int> item,int max){
    vector<bool> exist(max+1,false);
    exist[0] = true;
    for (int i=0;i<4;i++){
        for (int j=item[i];j<=max;j++){
            if (exist[j-item[i]])
                exist[j] = true;
        }
    }
    
    for (int i=max;i>=0;i--){
        if (!exist[i])
            return i;
    }
    return 0;
}

int main(){
    int max;
    vector<int> item(4);
    for (int i=0;i<4;i++)
        cin >> item[i];
    cin >> max;
    cout << GP(item,max) << endl;
    return 0;
}
