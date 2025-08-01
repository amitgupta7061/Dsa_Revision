#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string& s, int start, vector<string>&& path, vector<string>& ans) {
        if (path.size() == 4 && start == s.length()) {
            ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }
        if (path.size() == 4 || start == s.length()) return;

        for (int length = 1; length <= 3; ++length) {

            if (start + length > s.length()) return;
            if (length > 1 && s[start] == '0') return; 

            string num = s.substr(start, length);
            if (stoi(num) > 255) return;

            path.push_back(num);
            dfs(s, start + length, std::move(path), ans);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string& s) {
        vector<string> result;
        dfs(s, 0, {}, result);
        return result;
    }
};

int main() {

    return 0;
}