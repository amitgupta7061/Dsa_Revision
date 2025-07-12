#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             { 0, -1}, { 0, 0}, { 0, 1},
                                             { 1, -1}, { 1, 0}, { 1, 1}};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum = 0, count = 0;

                for(auto [dx, dy] : directions) {
                    int ni = i + dx, nj = j + dy;

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        count++;
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};


int main() {

    return 0;
}