#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.length(), n = b.length();
        int nooftimes = n / m, res = nooftimes;

        string temp = "";
        while(nooftimes--) temp += a;

        if(temp.find(b) != string::npos) return res;

        temp += a;
        if(temp.find(b) != string::npos) return res + 1;

        temp += a;
        if(temp.find(b) != string::npos) return res + 2;

        return -1;
    }
};

int main() {

    return 0;
}