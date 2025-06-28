#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, result = 0, maxfreq = 0, n = s.size();
        vector<int> freqmap(26, 0);        

        while(r < n){
            freqmap[s[r] - 'A']++;
            maxfreq = max(maxfreq, freqmap[s[r] - 'A']);
            if((r - l + 1) - maxfreq > k){
                freqmap[s[l] - 'A']--; l++;
            }
            if((r - l + 1) - maxfreq <= k){
                result = max(result, r -l + 1);
            }
            r++;
        }
        return result;
    }
};

int main() {

    return 0;
}