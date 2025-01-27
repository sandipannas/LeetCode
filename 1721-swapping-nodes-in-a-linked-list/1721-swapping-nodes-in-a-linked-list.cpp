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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p=head;
        int n=1;
        while(p!=NULL)
        {
            n++;
            p=p->next;
        }
        int count=n-k;
        p=head;
        while(count!=1)
        {
          count--;
          p=p->next;
        }
        ListNode* a=p;
        p=head;
        count=k;
        while(count!=1)
        {
           count--;
           p=p->next; 
        }
        ListNode* b=p;
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    return head;}
};