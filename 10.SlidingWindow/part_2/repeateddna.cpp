#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> result;

        for(int i = 0; i + 10 <= s.length(); i++){
            string dna = s.substr(i, 10);
            if(map.count(dna) and map[dna] == 1) result.push_back(dna);
            map[dna]++;
        }

        return result;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<int> seen, repeated;
        vector<string> result;

        unordered_map<char, int> charToBits = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        int hash = 0, mask = (1 << 20) - 1;

        for (int i = 0; i < s.length(); i++) {
            hash = ((hash << 2) | charToBits[s[i]]) & mask;
            
            if (i >= 9) {
                if (seen.count(hash)) {
                    if (!repeated.count(hash)) {
                        result.push_back(s.substr(i - 9, 10));
                        repeated.insert(hash);
                    }
                } else {
                    seen.insert(hash);
                }
            }
        }

        return result;
    }
};


int main() {

    return 0;
}