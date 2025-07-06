#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26];
        vector<int> Indegree(26, 0), isPresent(26, false);

        for (auto& word : words) {
            for (char c : word) {
                isPresent[c - 'a'] = true;
            }
        }

        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i], word2 = words[i+1];
            int len = min(word1.length(), word2.length());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    Indegree[word2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            if (!found && word1.length() > word2.length()) {
                return "";
            }
        }

        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(isPresent[i] && Indegree[i] == 0) q.push(i);
        }

        string result = "";
        while(!q.empty()){
            int node = q.front(); q.pop();
            result.push_back(node + 'a');

            for(auto neigh : adj[node]){
                Indegree[neigh]--;
                if(Indegree[neigh] == 0) q.push(neigh);
            }
        }

        if(result.size() != count(isPresent.begin(), isPresent.end(), true)) return "";

        return result;
    }
};



int main() {

    return 0;
}