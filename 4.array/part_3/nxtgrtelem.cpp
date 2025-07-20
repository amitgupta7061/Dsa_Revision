#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        map[nums2.back()] = -1;
        stack<int> st; st.push(nums2.back());

        for(int i = nums2.size() - 2; i >= 0; i--){
            while(st.size() and st.top() >= nums2[i]) st.pop();

            if(st.size()){
                map[nums2[i]] = st.top();
            } else {
                map[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        for(auto &it : nums1){
            it = map[it];
        }

        return nums1;
    }
};

int main() {

    return 0;
}