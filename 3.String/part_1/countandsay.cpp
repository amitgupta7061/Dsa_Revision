#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string f(string s){
        vector<pair<int, int>> map;
        int freq = 1, num = s[0] - '0';
        if(s.length() < 2) map.push_back({num, freq});
        else {
            for(int i = 1; i < s.length(); i++){
                if(s[i] - '0' == s[i-1] - '0') freq++;
                else{
                    map.push_back({num, freq});
                    num = s[i] - '0'; freq = 1;
                }
            }
            map.push_back({num, freq});
        }
        string result = "";
        for(auto it : map){
            result += to_string(it.second);
            result += to_string(it.first);
        }

        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; i++){
            result = f(result);
        }
        return result;
    }
};

int main() {

    return 0;
}