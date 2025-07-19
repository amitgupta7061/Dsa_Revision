#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1); stringstream s2(version2);
        int v1, v2;
        char dotChar;

        while (bool(s1 >> v1) + bool(s2 >> v2)) {
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            s1 >> dotChar;
            s2 >> dotChar;
            v1 = v2 = 0;
        }

        return 0;
    };
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            int num1 = 0, num2 = 0;

            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i++;
            j++;
        }

        return 0;
    }
};


int main() {

    return 0;
}