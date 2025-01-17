/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* p1=root;
        TreeNode* p2=NULL;
        if(p1==NULL)
        {
            return new TreeNode(val);
        }
        while(p1!=NULL)
        {   p2=p1;
            if((p1->val)>val)
            {
              p1=p1->left;
            }
            else
            {
                p1=p1->right;
            }
        }
        
        if(p2->val>val)
        {
            p2->left=new TreeNode(val);
        }
        else
        {
            p2->right=new TreeNode(val);
        }
    cout<<p2->val;
    return root;}
};