#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        int opened = 0;
        for (char ch : s) {
            if (ch == '(') opened++;
            else if (ch == ')') opened--;
            if (opened < 0) return false;
        }
        return true;
    }

    pair<int, int> getLeftAndRightCounts(const string& s) {
        int l = 0, r = 0;

        for (char ch : s){
            if (ch == '(') l++;
            else if (ch == ')') l == 0 ? r++ : l--;
        }   

        return {l, r};
    }

    void dfs(const string& s, int start, int l, int r, vector<string>& result) {
        if (l == 0 && r == 0 && isValid(s)) {
            result.push_back(s); return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (l > 0 && s[i] == '(')
                dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, result);
            if (r > 0 && s[i] == ')')
                dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, result);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        auto [l, r] = getLeftAndRightCounts(s);
        dfs(s, 0, l, r, result);
        return result;
    }
};



int main() {

    return 0;
}