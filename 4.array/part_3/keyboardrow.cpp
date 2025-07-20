#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        const vector<int> rows{2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

        for (string& word : words) {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
            int row = rows[lowerWord[0] - 'a'];

            bool isValid = all_of( lowerWord.begin(), lowerWord.end(),
                          [&](char c) { return rows[c - 'a'] == row; });

            if (isValid) ans.push_back(word);
        }
        return ans;
    }
};

int main() {

    return 0;
}