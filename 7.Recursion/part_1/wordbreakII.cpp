#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(string &s, int ind, string curr, unordered_set<string> &dict,
                                             vector<string> &result){
        if(ind == s.length()){
            curr.pop_back(); result.push_back(curr); return;
        }
        for(int len = 0; len + ind <= s.size(); len++){
            string word = s.substr(ind, len);
            if(dict.count(word)){
                f(s, ind+len, curr+word+" ", dict, result);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        f(s, 0, "", dict, result);
        return result;
    }
};

int main() {

    return 0;
}