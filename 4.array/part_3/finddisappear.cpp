#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> visited(nums.size()+1, false);

        for(auto it : nums) visited[it] = true;

        vector<int> result;
        for(int i = 1; i <= nums.size(); i++){
            if(!visited[i]) result.push_back(i);
        }

        return result;
    }
};

int main() {

    return 0;
}