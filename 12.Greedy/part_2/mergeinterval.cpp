#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), lstendTime = intervals[0][1]; 
        vector<vector<int>> result; result.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            if(lstendTime >= intervals[i][0]){
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
            lstendTime = result.back()[1];
        }

        return result;
    }
};

int main() {

    return 0;
}