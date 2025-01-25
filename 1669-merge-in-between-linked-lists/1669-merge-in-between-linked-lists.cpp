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
    
        ListNode* p=list1;
        ListNode* r=list1;
        for(int i=1;i<a;i++)
        {
          p=p->next;
        }
        for(int i=1;i<=b;i++)
        {
          r=r->next;
        }
        ListNode* q=list2;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        if(a==b)
        {
           ListNode* tem=r->next;
           p->next=list2;
           q->next=tem;
           return list1;
        }
        p->next=list2;
        q->next=r->next;
        return list1;



    }
};