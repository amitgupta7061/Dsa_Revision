#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int lowr = 0, highr = n-1, lowc = 0, highc = n-1;
        int num = 1;
        while(num <= n*n){
            // top row
            for(int i = lowc; i <= highc; i++){
                result[lowr][i] = num;
                num++;
            }
            if(num <= n*n) return result;
            lowr++;
            //right col
            for(int i = lowr; i <= highr; i++){
                result[i][highc] = num;
                num++;
            }
            if(num <= n*n) return result;
            highc--;
            // bottom row
            for(int i = highc; i >= lowc; i--){
                result[highr][i] = num;
                num++;
            }
            if(num <= n*n) return result;
            highr--;
            // left col
            for(int i = highr; i >= lowr; i--){
                result[i][lowc] = num;
                num++;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}