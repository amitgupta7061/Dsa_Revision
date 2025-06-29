#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n); left[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]) left[i] = 1 + left[i-1];
            else left[i] = 1;
        }

        int rght = 1, curr = 1, sum = max(1, left.back());
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                curr = rght + 1; rght = curr;
            } else{
                curr = 1; rght = 1;
            }
            sum += max(left[i], curr);
        }
        return sum;
    }
};

int main() {

    return 0;
}