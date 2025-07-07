#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;

        while(temp2){
            swap(temp1->val, temp2->val);
            if(temp2->next) temp1 = temp2->next;
            else return head;
            if(temp2->next->next) temp2 = temp2->next->next;
            else return head;
        }
        
        return head;
    }
};

int main() {

    return 0;
}