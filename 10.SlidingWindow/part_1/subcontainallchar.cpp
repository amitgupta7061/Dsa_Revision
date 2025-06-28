#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0, l = 0, r = 0, result = 0, n = s.length();
        while(r < n){
            s[r] == 'a' ? a++ : s[r] == 'b' ? b++ : c++;
            while(a > 1 and b > 1 and c > 1){
                result += n - r;
                s[l] == 'a' ? a-- : s[l] == 'b' ? b-- : c--; l++;
            }
            r++;
        }
        return result;
    }
};

int main() {

    return 0;
}