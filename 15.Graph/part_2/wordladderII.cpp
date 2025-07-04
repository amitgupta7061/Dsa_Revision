#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> f(string str, string dst, unordered_set<string> &list) {
        vector<vector<string>> result;
        queue<vector<string>> q;
        q.push({str});
        if (list.count(str)) list.erase(str);

        vector<string> usedThisLevel;

        while (!q.empty()) {
            usedThisLevel.clear();

            for (int i = q.size(); i > 0; i--) {
                vector<string> ladder = q.front(); q.pop();
                string currstr = ladder.back();

                if (currstr == dst) {
                    result.push_back(ladder);
                    continue;
                }

                for (int j = 0; j < currstr.size(); j++) {
                    char originalchar = currstr[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == originalchar) continue;
                        currstr[j] = ch;
                        if (list.count(currstr)) {
                            vector<string> newLadder = ladder;
                            newLadder.push_back(currstr);
                            q.push(newLadder);
                            usedThisLevel.push_back(currstr); 
                        }
                    }
                    currstr[j] = originalchar;
                }
            }
            for (const string &word : usedThisLevel) {
                list.erase(word);
            }
        }

        return result;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        return f(beginWord, endWord, list);
    }
};



int main() {

    return 0;
}