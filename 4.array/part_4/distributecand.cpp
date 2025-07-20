#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set(candyType.begin(), candyType.end());

        return (set.size() > candyType.size() / 2) ? candyType.size() / 2 : set.size();
    }
};

int main() {

    return 0;
}