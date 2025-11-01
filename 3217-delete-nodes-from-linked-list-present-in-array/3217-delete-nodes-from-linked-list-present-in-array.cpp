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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(),nums.end());
        
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while(curr!=nullptr){
            int value=curr->val;
            if(set.count(value) && curr==head){
                head=curr->next;
                curr->next=nullptr;
                curr=head;
            }
            else if(set.count(value)){
               pre->next=curr->next;
               curr->next=nullptr;
               curr=pre->next;
            }
            else{
                pre=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};