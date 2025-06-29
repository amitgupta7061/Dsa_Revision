#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecnt = 0, tencnt = 0;
        for(auto it : bills){
            if(it == 5) fivecnt++;
            else if(it == 10){
                if(fivecnt) fivecnt--;
                else return false;
            } else{
                if(tencnt and fivecnt){
                    tencnt--; fivecnt--;
                } else if(fivecnt >= 3) fivecnt -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}