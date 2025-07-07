#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0, n = heights.size();
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top(); 
            st.push(i);
        }
        for(auto it : left) cout<<it<<" ";
        cout<<"\n";
        for(auto it : right) cout<<it<<" ";
        for (int i = 0; i < n; ++i) {
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
      
        return result;
    }
};

int main() {

    return 0;
}