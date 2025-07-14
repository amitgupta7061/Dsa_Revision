#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
    bool isNumber(string s) {
        trim(s);
        if(s.empty()) return false;

        bool seen_num = false, seen_dot = false, seen_e = false;

        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '.':
                    if(seen_dot or seen_e) return false;
                    seen_dot = true; break;
                case 'e':
                case 'E':
                    if(seen_e or !seen_num) return false;
                    seen_e = true; break;
                case '+':
                case '-':
                    if(i > 0 and s[i-1] != 'e' and s[i-1] != 'E') return false;
                    break;
                default:
                    if(!isdigit(s[i])) return false;
                    seen_num = true;
            }
        }
        return seen_num;
    }
};

int main() {

    return 0;
}   