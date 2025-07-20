#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* child[2];
    Node(){
        child[0] = child[1] = NULL;
    }
};

class Solution {
public:
    void insertinTrie(int num, Node* root){
        Node* curr = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!curr->child[bit]){
                curr->child[bit] = new Node();
            }
            curr = curr->child[bit];
        }
    }

    int findmaxi(int num, Node* root){
        Node* curr = root;
        int maxi = 0;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1, opp = (bit == 0) ? 1 : 0;

            if(curr->child[opp]){
                maxi |= (1 << i);
                curr = curr->child[opp];
            } else{
                curr = curr->child[bit];
            }
        }

        return maxi;
    }

    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for(int num : nums) insertinTrie(num, root);

        int result = 0;
        for(int num : nums)
            result = max(result, findmaxi(num, root));

        return result;
    }
};


int main() {

    return 0;
}