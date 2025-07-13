#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() or s.empty()) return result;

        int wordlen = words[0].size(), n = s.size(); 
        int wordcnt = words.size(), windowlen = wordlen * wordcnt;

        if(n < windowlen) return result;

        unordered_map<string, int> wordfreq;
        for(auto &word : words) wordfreq[word]++;

        for(int i = 0; i < wordlen; i++){
            int start = i, cnt = 0;
            unordered_map<string, int> currfreq;

            for(int j = i; j + wordlen <= n; j += wordlen){ // every wordlen window
                string word = s.substr(j, wordlen);

                if(wordfreq.count(word)){
                    currfreq[word]++;
                    cnt++;
                
                    while(currfreq[word] > wordfreq[word]){
                        string prevword = s.substr(start, wordlen);
                        currfreq[prevword]--;
                        start += wordlen;
                        cnt--;
                    }

                    if(cnt == wordcnt) result.push_back(start);
                } else { // start a new window
                    currfreq.clear();
                    cnt = 0;
                    start = j + wordlen;
                }
            }
        }
        
        return result;
    }
};

int main() {

    return 0;
}