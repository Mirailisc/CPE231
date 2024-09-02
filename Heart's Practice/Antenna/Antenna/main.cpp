#include <iostream>
#include <cmath>
#include <numeric>
#include <limits>

using namespace std;

//first = a , second = b
//mean
float eff(pair<float,float> p1,pair<float,float> p2){
    return abs(p1.first-p2.first)/(abs(p1.first)+abs(p2.first)) + abs(p1.second-p2.second)/(abs(p1.second)+abs(p2.second));
}

float mean(vector<float> eff_list){
    if (eff_list.empty())
        return 0.0;//accumulate(eff_list.begin(),eff_list.end(),0.0)
    return (accumulate(eff_list.begin(),eff_list.end(),0.0)); // / eff_list.size()
}

/* it wrong!!
pair<int,int> Highest_eff_pair(vector<pair<int,int>> p_list){
    int n = p_list.size();
    int h_eff = -1;
    pair<int,int> highest = {-1,-1};
    for (int i=0;i<n-1;i++){
        highest = p_list[i];
        for (int j=1;j<n;j++){
            int test_eff = eff(highest,p_list[j]);
            if (test_eff > h_eff){
                highest = p_list[j];
                h_eff = test_eff;
            }
        }
    }
    return highest;
}*/

pair<int,int> Highest_eff_pair(vector<pair<int,int>> p_list){
    int n = p_list.size();
    float low_mean = numeric_limits<float>::max();
    vector<float> eff_list;
    pair<int,int> highest = {-1,-1};
    for (int i=0;i<n;i++){
        eff_list = {};
        for (int j=0;j<n;j++)
            eff_list.push_back(eff(p_list[i],p_list[j]));
        int eff_mean = mean(eff_list);
        //cout << eff_mean << endl;
        if (low_mean >= eff_mean){
            highest = p_list[i];
            low_mean = eff_mean;
        }
    }
    return highest;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> p_list(n);
    for (int i=0;i<n;i++)
        cin >> p_list[i].first >> p_list[i].second;
    pair<int,int> highest = Highest_eff_pair(p_list);
    cout << highest.first << " " << highest.second << endl;
    return 0;
}
