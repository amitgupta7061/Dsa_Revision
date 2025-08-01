#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(isPrime[i]) cnt++;
        }

        return cnt;
    }
};

int main() {

    return 0;
}