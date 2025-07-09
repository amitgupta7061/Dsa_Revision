#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        string result = "";
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            if(node) result += to_string(node->val) + ",";
            else result += "#,";

            if(node) q.push(node->left);
            if(node) q.push(node->right);
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string word;
        getline(ss, word, ',');
        TreeNode* root = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            getline(ss, word, ',');
            if(word == "#") node->left = NULL;
            else{
                node->left = new TreeNode(stoi(word));
                q.push(node->left);
            }
            getline(ss, word, ',');
            if(word == "#") node->right = NULL;
            else{
                node->right = new TreeNode(stoi(word));
                q.push(node->right);
            }
        }

        return root;
    }
};


int main() {

    return 0;
}