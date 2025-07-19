#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int len = s.length() / 2; len >= 1; len--){
            if(s.length() % len != 0) continue;
            string pattern = s.substr(0, len), newstr = "";
            int time = s.length() / len;

            while(time--){
                newstr += pattern;
            }
            if(newstr == s) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}