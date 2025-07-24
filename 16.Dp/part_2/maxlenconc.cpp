#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isok(string &str) {
        vector<bool> seen(26, false);
        for (char c : str) {
            if (seen[c - 'a']) return false;
            seen[c - 'a'] = true;
        }
        return true;
    }

    int f(vector<string> &arr, int ind, string str, unordered_map<string, int>& dp) {
        if (ind >= arr.size()) {
            return str.length();
        }
        string key = to_string(ind) + "_" + str;
        if(dp[key]) return dp[key];
        int nottake = f(arr, ind + 1, str, dp);

        int take = 0;
        string newStr = str + arr[ind];
        if (isok(newStr)) {
            take = f(arr, ind + 1, newStr, dp); 
        }

        return dp[key] = max(nottake, take);
    }

    int maxLength(vector<string>& arr) {
        unordered_map<string, int> dp;
        return f(arr, 0, "", dp);
    }
};

class Solution {
public:
    int getMask(string &str) {
        int mask = 0;
        for (char c : str) {
            int bit = c - 'a';
            if (mask & (1 << bit)) return -1;
            mask |= (1 << bit);
        }
        return mask;
    }

    int f(vector<string>& arr, int ind, int usedMask, unordered_map<string, int>& dp) {
        if (ind >= arr.size()) return 0;

        string key = to_string(ind) + "_" + to_string(usedMask);
        if (dp.count(key)) return dp[key];
        int nottake = f(arr, ind + 1, usedMask, dp);

        int take = 0;
        int currMask = getMask(arr[ind]);
        if (currMask != -1 && (usedMask & currMask) == 0) {
            take = arr[ind].length() + f(arr, ind + 1, usedMask | currMask, dp);
        }

        return dp[key] = max(take, nottake);
    }

    int maxLength(vector<string>& arr) {
        unordered_map<string, int> dp;
        return f(arr, 0, 0, dp);
    }
};



int main() {

    return 0;
}