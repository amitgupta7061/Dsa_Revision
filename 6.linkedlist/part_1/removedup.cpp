#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode(INT_MIN);
        ListNode* curr = root;
        ListNode* temp1 = head;

        while(temp1){
            if(temp1->val != curr->val){
                curr->next = temp1;
                curr = curr->next;
            }
            temp1 = temp1->next;
        }
        curr->next = NULL;
        return root->next;
    }
};

int main() {

    return 0;
}