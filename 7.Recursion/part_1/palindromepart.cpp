#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool ispalindrom(string &str, int l, int r){
        while(l <= r){
            if(str[l] != str[r]) return false;
            else {
                l++; r--;
            }
        }
        return true;
    }
    void f(string &s, int ind, vector<string> &curr, vector<vector<string>> &result){
        if(ind == s.size()){
            result.push_back(curr); return;
        }
        for(int i = ind; i < s.size(); i++){
            if(ispalindrom(s, ind, i)){
                curr.push_back(s.substr(ind, i-ind+1));
                f(s, i+1, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        f(s, 0, curr, result);
        return result;
    }
};

int main() {

    return 0;
}