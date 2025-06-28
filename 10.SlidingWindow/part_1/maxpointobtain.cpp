#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), result = -1;
        int l = 0, r = n - 1, lsum = 0, rsum = 0;

        for(l = 0; l < k; l++) lsum += cardPoints[l];
        result = max(result, lsum + rsum);

        l--;
        while(l >= 0){
            lsum -= cardPoints[l--];
            rsum += cardPoints[r--];
            result = max(result, lsum + rsum);
        }
        return result;
    }
};

int main() {

    return 0;
}