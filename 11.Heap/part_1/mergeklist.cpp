#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* list3 = new ListNode(100);
        ListNode* temp3 = list3;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp3 = temp1;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }
        if(temp1!=NULL) temp3->next = temp1;
        if(temp2!=NULL) temp3->next = temp2;
        return list3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        while(lists.size() > 1){
            ListNode* temp1 = lists.back(); lists.pop_back();
            ListNode* temp2 = lists.back(); lists.pop_back();
            lists.push_back(mergeTwoLists(temp1, temp2));
        }
        return lists[0];
    }
};

// for solving using heap first put all element in minheap 
// then make new linkedlist using all the node which is
// present in heap one by one 


int main() {

    return 0;
}