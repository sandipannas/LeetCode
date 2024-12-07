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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* p0=NULL;
        ListNode* p1=head;
        ListNode* p2=head->next;
        while(p1!=NULL)
        {
            p1->next=p0;
            p0=p1;
            p1=p2;
            if(p2!=NULL){p2=p2->next;}
        }
    return p0;}
};