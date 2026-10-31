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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        return head;
        ListNode* trav=head;
        while(trav!=NULL && trav->next!=NULL){
            if(trav->val==trav->next->val){
            ListNode *temp=trav->next;
            trav->next=temp->next;
            delete temp;
            }
            else
            trav=trav->next;
        }
        return head;
    }
};