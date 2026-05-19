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
    ListNode* merged(ListNode* head1 , ListNode* head2){
        if(head1==NULL && head2==NULL){ return NULL;}
        if(head1==NULL){ return head2; }
        if(head2==NULL){ return head1; }

        ListNode* p1=head1;
        ListNode* p2=head2;

        ListNode* st=NULL;
        ListNode* ans=NULL;

        if(head1->val<=head2->val){
            st=head1; ans=head1; p1=p1->next;
        }
        else{
            st=head2; ans=head2; p2=p2->next;
        }

        while(p1!=NULL && p2!=NULL){
            if(p1->val<=p2->val){
                st->next=p1;
                p1=p1->next;
            }
            else{
                st->next=p2;
                p2=p2->next;
            }
            st=st->next;
        }

        if(p1!=NULL){ st->next=p1; }
        if(p2!=NULL){ st->next=p2; }

        return ans;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){ return NULL; }
        if(lists.size()==1){ return lists[0];}
        vector<ListNode*> answer;
        int count=lists.size();

        while(count!=1){
            int left=0;
            int right=lists.size()-1;

            while(left<=right){
                if(left==right){
                    answer.push_back(lists[left]);
                    break;
                }
            ListNode* head1=lists[left];
            ListNode* head2=lists[right];
            ListNode* res=merged(head1,head2); count--;

            answer.push_back(res);
            left++;
            right--;
            }
            lists=answer;
            answer={};
        }
        return answer[0];
    }
};