#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> result, lis;

        for (int i = 0; i < obstacles.size(); i++) {

            int ind = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();

            if (ind == lis.size()) lis.push_back(obstacles[i]);
            else lis[ind] = obstacles[i];
            

            result.push_back(ind + 1);
        }

        return result;
    }
};


int main() {

    return 0;
}