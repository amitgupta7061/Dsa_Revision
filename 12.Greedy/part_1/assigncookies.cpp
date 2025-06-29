#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0, l = 0, r = 0;
        while(l < g.size() and r < s.size()){
            if(g[l] <= s[r]){
                l++; r++; cnt++;
            }
            else if(g[l] > s[r]) r++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}