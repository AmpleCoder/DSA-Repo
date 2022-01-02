/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
to-do : try to get into the depth of why it doesn't works when one or both nodes are absent then 
and how it fetches the lca's from subtrees
*/

class Solution {
public:
    TreeNode *ans(TreeNode *root,int val1,int val2)
    {
        if(root==NULL)  return NULL;
        if(root->val==val1 || root->val==val2)  return root;
        TreeNode *lca1=ans(root->left,val1,val2);
        TreeNode *lca2=ans(root->right,val1,val2);
        if(lca1!=NULL && lca2!=NULL)    return root;
        if(lca1!=NULL)  return lca1;
        return lca2;
    } 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ans(root,p->val,q->val);
    }
};