#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }
        int slots = 1;
        for(auto &n : nodes){
            if(--slots < 0) return false;
            if(n != "#") slots += 2;
        }
        return slots == 0;
    }
};

int main() {

    return 0;
}