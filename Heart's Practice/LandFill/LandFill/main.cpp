#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int rough(vector<int> land){
    int sum = 0;
    for (int i=0;i<land.size()-1;i++)
        sum += abs(land[i]-land[i+1]);
    return sum;
}

vector<int> lmr_expand(vector<int> lmr){
    vector<int> land;
    for (int i=lmr[0];i<=lmr[1];i++)
        land.push_back(i);
    for (int i=lmr[1]-1;i>=lmr[2];i--)
        land.push_back(i);
    return land;
}

bool isCheck_Not_OverBoundaries(int fill_at_begin_of_lmr, vector<int> lmr_expand, vector<int> land_fill){ //beginPos 0 to n-1
    return fill_at_begin_of_lmr<=(land_fill.size()-lmr_expand.size())?true:false;
}

vector<int> bin(int dec,int n){
    vector<int> a;
    int B = dec;
    int j = 0;
    while (B>0){
        a.insert(a.begin(), B%2);
        B /= 2;
        j++;
    }
    for (;j<n;j++)
        a.insert(a.begin(), 0);
    return a;
}

vector<int> MergeLand(int fill_at_begin_of_lmr, vector<int> lmr_expand, vector<int> land_fill){
    vector<int> new_land_fill = land_fill;
    //if (isCheck_Not_OverBoundaries(fill_at_begin_of_lmr,lmr_expand,land_fill)){
    for (int i=0; i < lmr_expand.size();i++)
        new_land_fill[fill_at_begin_of_lmr+i] += lmr_expand[i];
    return new_land_fill;
    //}
    //return {};
}

int MinimumRoughLandFill(vector<int> unadj_land, vector<int> lmr_expand){
    int bound = unadj_land.size() - lmr_expand.size()+1;
    int possible = pow(2,bound);
    int minimizer = INT_MAX;
    for (int i=0;i<possible;i++){
        vector<int> allow = bin(i,bound);
        vector<int> done_land_fill = unadj_land;
        for (int j=0;j<bound;j++){
            if (allow[j])
                done_land_fill = MergeLand(j,lmr_expand,done_land_fill);
        }
        int rough_done = rough(done_land_fill);
        if (rough_done < minimizer)
            minimizer = rough_done;
    }
    return minimizer;
}

// Knapsack-like DP solution to minimize roughness ??? have problem
int MinimumRoughLandFill_knapsack(vector<int> unadj_land, vector<int> lmr_expand) {
    int n = unadj_land.size();
    int m = lmr_expand.size();
    int bound = n - m + 1;
    
    vector<vector<int>> dp(bound + 1, vector<int>(bound + 1, INT_MAX));
    
    dp[0][0] = rough(unadj_land);
    
    for (int i = 1; i <= bound; i++) {
        for (int j = 0; j <= i; j++) {
            // If we don't place lmr_expand at this position
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            
            // If we place lmr_expand at this position
            if (j > 0) {
                vector<int> new_land_fill = MergeLand(i - 1, lmr_expand, unadj_land);
                dp[i][j] = min(dp[i][j], rough(new_land_fill));
            }
        }
    }
    
    int minimizer = INT_MAX;
    for (int j = 0; j <= bound; j++) {
        minimizer = min(minimizer, dp[bound][j]);
    }
    
    return minimizer;
}


int main(){
    int n;
    cin >> n;
    vector<int> unadj_land(n);
    vector<int> lmr(3);
    for (int i=0;i<n;i++)
        cin >> unadj_land[i];
    for (int i=0;i<3;i++)
        cin >> lmr[i];
    vector<int> lmr_add = lmr_expand(lmr);
    /*for (auto j : lmr_add){
        cout << j << " ";
    }
    cout << endl;
    
    vector<int> newX = MergeLand(0,lmr_add,unadj_land);
    for (auto j : newX){
        cout << j << " ";
    }
    cout << endl;
    
    newX = MergeLand(0,lmr_add,newX);
    for (auto j : newX){
        cout << j << " ";
    }
    cout << endl;*/
    
    cout << MinimumRoughLandFill(unadj_land,lmr_add) << endl;
    return 0;
}
