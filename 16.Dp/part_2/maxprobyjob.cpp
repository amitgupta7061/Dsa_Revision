#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i = 0; i < n; ++i){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1, 0);

        vector<int> startTimes(n);
        for(int i = 0; i < n; ++i) startTimes[i] = jobs[i][0];

        for(int i = n - 1; i >= 0; --i){
            int nextJobIndex = lower_bound(startTimes.begin(), startTimes.end(), jobs[i][1]) - startTimes.begin();
            int take = jobs[i][2] + dp[nextJobIndex];
            int notTake = dp[i + 1];
            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};


int main() {

    return 0;
}