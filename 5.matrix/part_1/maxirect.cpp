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
      
        for (int i = 0; i < n; ++i) {
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
      
        return result;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
      
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxi = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < n; j++) {
                if (row[j] == '1') heights[j]++; 
                else heights[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};

int main() {

    return 0;
}