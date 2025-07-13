#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};

        vector<int> freq(26, 0), currfrq(26, 0), result;
        for(auto &ch : p) freq[ch - 'a']++;

        int l = 0, r = 0, m = p.length(), n = s.length();

        while(r < n){
            currfrq[s[r] - 'a']++;
            if(r - l + 1 == m){
                if(currfrq == freq) result.push_back(l);
                currfrq[s[l] - 'a']--; l++;
            }
            r++;
        }

        return result;
    }
};

int main() {

    return 0;
}