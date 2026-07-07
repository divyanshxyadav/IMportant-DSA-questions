/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mpp;
ListNode*temp=head;
int i=0;
while(temp!=NULL && temp->next!=NULL){
    if(mpp.find(temp)!=mpp.end())
    return temp;
mpp[temp]=i;
i++;
temp=temp->next;

}
return nullptr;
    }
};