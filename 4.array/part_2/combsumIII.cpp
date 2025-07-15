#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<vector<int>> &result, vector<int> &temp, int k, int n, int ind){
        if(temp.size() == k && n == 0){
            result.push_back(temp);
            return;
        }

        for(int i = ind; i <= 9; i++){
            if(i > n) break;
            temp.push_back(i);
            f(result, temp, k, n - i, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        f(result, temp, k, n, 1);
        return result;
    }
};


int main() {

    return 0;
}