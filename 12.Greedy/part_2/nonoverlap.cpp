#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), lstTime = intervals[0][1], cnt = 0; 

        for(int i = 1; i < n; i++){
            if(lstTime >= intervals[i][0]){
                cnt++;
            }
            lstTime = max(lstTime, intervals[i][1]);
        }

        return cnt;
    }
};

int main() {

    return 0;
}