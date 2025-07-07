#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> premat;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        premat.resize(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int top = (r > 0) ? premat[r - 1][c] : 0;
                int left = (c > 0) ? premat[r][c - 1] : 0;
                int diag = (r > 0 && c > 0) ? premat[r - 1][c - 1] : 0;

                premat[r][c] = matrix[r][c] + top + left - diag;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = premat[row2][col2];
        int up = (row1 > 0) ? premat[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? premat[row2][col1 - 1] : 0;
        int diag = (row1 > 0 && col1 > 0) ? premat[row1 - 1][col1 - 1] : 0;

        return total - up - left + diag;
    }
};


int main() {

    return 0;
}