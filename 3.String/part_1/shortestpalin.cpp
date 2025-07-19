#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        vector<int> lps(combined.size(), 0);

        for (int i = 1; i < combined.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len])
                len = lps[len - 1];
            if (combined[i] == combined[len]) len++;
            lps[i] = len;
        }

        int palindromeLen = lps.back();
        string add = s.substr(palindromeLen);
        reverse(add.begin(), add.end());

        return add + s;
    }
};

class Solution {
public:
    bool ispalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        for(int i = s.length() - 1; i >= 0; i--){
            if(ispalindrome(s, 0, i)){
                string suffix = s.substr(i + 1);
                reverse(suffix.begin(), suffix.end());
                return suffix + s;
            }
        }
        return s + s;
    }
};

    
int main() {

    return 0;
}