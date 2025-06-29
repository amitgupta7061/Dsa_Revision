#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinimumCoins(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int cnt = 0;
        for(int coin : coins){
            if(coin <= amount){
                int take = amount / coin;
                cnt += take;
                amount -= take * coin;
            }
        }
        return amount == 0 ? cnt : -1;
    }
};


int main() {

    return 0;
}