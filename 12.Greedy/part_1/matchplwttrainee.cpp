#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int cnt = 0, l = 0, r = 0;
        while(l < players.size() and r < trainers.size()){
            if(players[l] <= trainers[r]){
                l++; r++; cnt++;
            }
            else if(players[l] > trainers[r]) r++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}