#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else {
                if(st.size() and s[st.top()] == '(') st.pop();
                else st.pop();
            }
        }

        if(st.size() == 0) return s.length();
        int maxlen = 0;
        maxlen = max(maxlen, n - st.top() - 1); // distance btwn last invalid to end

        while(st.size()){
            int f_invalidInd = st.top(); st.pop();
            if(st.size() == 0){
                st.push(f_invalidInd); break;
            }
            int s_invalidInd = st.top(); st.pop();
            maxlen = max(maxlen, f_invalidInd - s_invalidInd - 1);
            st.push(s_invalidInd);
        }

        maxlen = max(maxlen, st.top() - 0); // distance from 1st invalid to 0

        return maxlen;
    }
};

int main() {

    return 0;
}