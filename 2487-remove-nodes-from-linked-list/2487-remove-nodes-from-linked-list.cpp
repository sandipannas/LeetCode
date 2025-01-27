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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> gg;
        
        while(head!=NULL)
        {
            if(gg.empty())
            {
                gg.push(head);
            }
            else{
                while(!gg.empty() && gg.top()->val<head->val)
                {
                   gg.pop();
                }
                gg.push(head);
            }
            head=head->next;
        }
        head=NULL;
        while(!gg.empty())
        {
            gg.top()->next=head;
            head=gg.top();
            gg.pop();
        }
    return head;
    }
};