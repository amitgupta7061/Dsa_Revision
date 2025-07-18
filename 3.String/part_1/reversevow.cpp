#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while(l < r){
            while(l < r and !st.count(s[l])) l++;
            while(r < l and !st.count(s[r])) r--;

            swap(s[l], s[r]);
            l++; r--;
        }

        return s;
    }
};

int main() {

    return 0;
}