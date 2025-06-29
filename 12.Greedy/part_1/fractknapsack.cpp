#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (double)a.first / a.second > (double)b.first / b.second;
}

class Solution{
public:
    double fractionalKnapsack(vector<pair<int, int>> &knapsack, int capacity){
        sort(knapsack.begin(), knapsack.end(), cmp);
        double result = 0;
        for(auto it : knapsack){
            if(it.second <= capacity){
                result += it.first;
                capacity -= it.second;
            } else{
                result += (double(it.first) / it.second) * capacity;
                break;
            }
        }
        return result;
    } 
};

int main() {
    Solution sol;
    vector<pair<int, int>> knapsack = {{10, 5}, {20, 10}, {30, 15}};
    cout << fixed << setprecision(4) << sol.fractionalKnapsack(knapsack, 50);
    return 0;
}
