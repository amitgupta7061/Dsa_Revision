#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int originalCol = image[sr][sc], m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(q.size()){
            auto [row, col] = q.front(); q.pop();
            for(auto it : direction){
                int nrow = row + it.first, ncol = col + it.second;
                if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n 
                    || image[nrow][ncol] != originalCol) continue;
                q.push({nrow, ncol});
                image[nrow][ncol] = color;
            }
        }
        return image;
    }
};

int main() {

    return 0;
}