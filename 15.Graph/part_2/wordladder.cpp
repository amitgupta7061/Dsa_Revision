#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string str, string dst, unordered_set<string> &list){
        queue<pair<string, int>> q; q.push({str, 1});
        if(list.count(str)) list.erase(str);

        while(q.size()){
            auto [currstr, step] = q.front(); q.pop();
            if(currstr == dst) return step;

            for(int i = 0; i < currstr.size(); i++){
                char originalchar = currstr[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    currstr[i] = ch;
                    if(list.count(currstr)){
                        list.erase(currstr);
                        q.push({currstr, step + 1});
                    }
                }
                currstr[i] = originalchar;
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        return f(beginWord, endWord, list);
    }
};

int main() {

    return 0;
}