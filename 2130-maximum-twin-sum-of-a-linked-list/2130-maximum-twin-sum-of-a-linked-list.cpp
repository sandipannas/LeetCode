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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next; 
        }
        ListNode* p1=slow;
        ListNode* p2=slow->next;
        ListNode* p3=NULL; if(p2!=NULL){ p3=slow->next->next;}
        slow->next=NULL;

        while(p2!=NULL)
        {
            p2->next=p1;
            p1=p2;
            p2=p3;
            if(p3!=NULL){ p3=p3->next;
            }
        }
        p2=head;
        int maxi=0;
        while(p2!=slow){
           maxi=max(p1->val+p2->val,maxi);
           p1=p1->next;
           p2=p2->next;
        }
    return maxi;}
};