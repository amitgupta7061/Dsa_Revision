#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for(char &ch : t) map[ch]++;

        int l = 0, r = 0, n = s.size(), cnt = t.size(), len = INT_MAX, start = -1;

        while(r < n){

            if(map.count(s[r])) cnt--;
            map[s[r]] == 1 ? map.erase(s[r]) : map[s[r]]--;

            while(cnt == 0){
                if(r - l < len){
                    len = r - l;
                    start = l;
                }
                map[s[l]]++; cnt++; l++;
            }
            r++;
        }

        return start == -1 ? "" : s.substr(start, len);
    }
};

int main() {

    return 0;
}