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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){return true;}
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* p1=slow;
        ListNode* p2=slow->next;
        slow->next=NULL;
        ListNode* p3=NULL;
        if(p2!=NULL){
        p3=p2->next;}
        while(p2!=NULL)
        {
          p2->next=p1;
          p1=p2;
          p2=p3;
          if(p3!=NULL) { p3=p3->next; }     
        }
        p2=head;
        while(p1!=slow)
        {
            if(p1->val!=p2->val){return false;}
            p1=p1->next;
            p2=p2->next;
        }
        if(p1->val!=p2->val){return false;}
    return true;
    }
};