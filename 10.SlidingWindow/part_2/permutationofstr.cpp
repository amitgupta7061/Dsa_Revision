#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> freq(26, 0), currfrq(26, 0);
        for(auto &ch : s1) freq[ch - 'a']++;

        int l = 0, r = 0, m = s1.length(), n = s2.length();

        while(r < n){
            currfrq[s2[r] - 'a']++;
            if(r - l + 1 == m){
                if(currfrq == freq) return true;
                currfrq[s2[l] - 'a']--; l++;
            }
            r++;
        }

        return false;
    }
};

int main() {

    return 0;
}