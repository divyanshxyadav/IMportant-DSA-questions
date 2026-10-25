/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail2=list2;
        while(tail2->next!=NULL){
            tail2=tail2->next;
        }
ListNode* aless1=list1;
ListNode* bplus1=list1;
int num1=a-1;
while(num1--){
    aless1=aless1->next;
}
int num2=b+1;
while(num2--){
    bplus1=bplus1->next;
}
aless1->next=list2;
tail2->next=bplus1;
return list1;
    }
};