#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int numTilings(int n) {
        long tilingWays[4] = {1, 0, 0, 0};
        for (int i = 1; i <= n; ++i) {
            long newTilingWays[4] = {0, 0, 0, 0};
            newTilingWays[0] = (tilingWays[0] + tilingWays[1] + tilingWays[2] + tilingWays[3]) % MOD;
            newTilingWays[1] = (tilingWays[2] + tilingWays[3]) % MOD;
            newTilingWays[2] = (tilingWays[1] + tilingWays[3]) % MOD;
            newTilingWays[3] = tilingWays[0];
            memcpy(tilingWays, newTilingWays, sizeof(newTilingWays));
        }
        return tilingWays[0];
    }
};

int main() {

    return 0;
}