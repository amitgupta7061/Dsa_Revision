#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        long long ans = 1;
        vector<int> result;
        result.push_back(ans);
        for(int i = 0; i < rowIndex; i++){
            ans = ans * (rowIndex - i);
            ans = ans / (i + 1);
            result.push_back(ans);
        }
        return result;
        
    }
};

int main() {

    return 0;
}