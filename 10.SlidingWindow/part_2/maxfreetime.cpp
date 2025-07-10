#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;
        int n = startTime.size();
        freetime.push_back(startTime[0]);
        for(int i = 1; i < n; i++){
            freetime.push_back(startTime[i] - endTime[i-1]);
        }
        freetime.push_back(eventTime - endTime[n-1]);

        for(auto it : freetime) cout<<it<<" ";

        int maxi = 0, currsum = 0, l = 0, r = 0;
        while(r < freetime.size()){
            currsum += freetime[r];
            if(r - l + 1 > k+1){
                currsum -= freetime[l++];
            }
            maxi = max(maxi, currsum);
            r++;
        }
        return maxi;
    }
};

int main() {

    return 0;
}