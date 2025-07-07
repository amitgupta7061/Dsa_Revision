#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f(vector<int> &inorder, int s, int e){
        if(s > e) return NULL;
        int mid = (s + e + 1) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = f(inorder, s, mid - 1);
        root->right = f(inorder, mid + 1, e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> inorder;
        while(head){
            inorder.push_back(head->val);
            head = head->next;
        }
        f(inorder, 0, inorder.size() - 1);
    }
};

int main() {

    return 0;
}