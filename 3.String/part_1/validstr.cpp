#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        
        if(word.length() < 3) return false;
        bool havecons = false, havevowel = false;

        for(auto &ch : word){
            if(isdigit(ch)) continue;
            else if(isalpha(ch)){
                if(ch == 'a' or ch == 'o' or ch == 'i' or ch == 'e' or ch == 'u' or
                ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') havevowel = true;
                else havecons = true;
            } else return false;
        }

        return havecons and havevowel;
    }
};

int main() {

    return 0;
}