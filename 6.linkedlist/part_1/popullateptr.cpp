#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        queue<Node*> q;
        q.push(root);

        while(q.size()){
            Node* prev = NULL;
            for(int i = q.size(); i > 0; i--){
                Node* node = q.front(); q.pop();
                if(prev == NULL){
                    prev = node;
                } else {
                    prev->next = node;
                    prev = node;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            prev->next = NULL;
        }

    }
};

int main() {

    return 0;
}