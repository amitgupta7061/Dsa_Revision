#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), maxCnt=0;

        for(int i = -n + 1; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i + j < 0) continue;
                else if(i + j >= m) break; 
                else if(nums1[i+j] == nums2[j]){
                    cnt++;;
                    maxCnt = max(maxCnt, cnt);
                }
                else cnt = 0;
            }
        }

        return maxCnt;
    }
};

int main() {

    return 0;
}