#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0, needopen = 0;
        for(auto &ch : s){
            if(ch == '(') size++;
            else size > 0 ? size-- : needopen++;
        }
        return size + needopen;
    }
};

int main() {

    return 0;
}