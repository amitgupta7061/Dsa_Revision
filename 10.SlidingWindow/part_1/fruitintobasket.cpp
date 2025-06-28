#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalFruits(vector<int>& fruits){
        unordered_map<int, int> map;
        int l = 0, result = 0, n = fruits.size();
        for(int r = 0; r < n; r++){
            map[fruits[r]]++;
            while(map.size() > 2){
                map[fruits[l]]--;
                if(map[fruits[l]] == 0) map.erase(fruits[l]);
                l++;
            }
            result = max(result, r - l);
        }
        return result;
    }
};


int main() {

    vector<int> fruits = {};

    Solution sol;
    cout<<sol.totalFruits(fruits);

    return 0;
}