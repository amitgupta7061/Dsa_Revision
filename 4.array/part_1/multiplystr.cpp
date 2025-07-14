#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply_digit(string &str, int num){
        string result = "";
        int carry = 0;
        for(int i = str.length() - 1; i >= 0; i--){
            int k = str[i] - '0';
            int temp = k * num + carry;
            int x = temp % 10;
            carry = temp / 10;
            result = to_string(x) + result;
        }

        while (carry > 0) {
            result = to_string(carry % 10) + result;
            carry /= 10;
        }

        return result;
    }

    void addtostr(string &s1, string &s2, int pos){
        for (int i = 0; i < pos; i++) {
            s2 += '0';
        }

        string result = "";
        int carry = 0;
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';

            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }

        s1 = result;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string result = "0";
        int pos = 0;
        for (int i = num2.length() - 1; i >= 0; i--){
            int num = num2[i] - '0';
            string aftermul = multiply_digit(num1, num);
            addtostr(result, aftermul, pos);
            pos++;
        }
        return result;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int mul = a * b + result[i + j + 1];

                result[i + j + 1] = mul % 10;
                result[i + j] += mul / 10;
            }
        }

        string res = "";
        for (int num : result) {
            if (!(res.empty() && num == 0))
                res += (num + '0');
        }

        return res.empty() ? "0" : res;
    }
};


int main() {

    return 0;
}