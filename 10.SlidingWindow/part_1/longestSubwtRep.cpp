#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0, r = 0, n = s.length(), result = 0;
        while(r < n){
            if(map.count(s[r]) and map[s[r]] >= l){
                l = map[s[r]] + 1;
            }
            result = max(result, r - l + 1);
            map[s[r]] = r;
            r++;
        }
        return result;
    }
};

int main() {

    return 0;
}