#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for(auto card : hand) freq[card]++;

        for(auto [card, cnt] : freq){
            if(cnt > 0){
                for(int i = 0; i < groupSize; i++){
                    if(freq[card + i] < cnt){
                        return false;
                    }
                    freq[card + i] -= cnt;
                }
            }
        }
        return true;
    }
};


int main() {

    return 0;
}