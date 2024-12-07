Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/*
Approach:
        1
      /   \
    2      3
  /  \
4      5
      / \
    6    7
    
1. LCA(4,7)
2. perform DFS traversal till we reach a required node say 4, then we will return 4
3. again when we reach 6, we will return NULL because no desired node was found
4. but if we reach 7, we will return 7
5. now node 5 has NULL & 7 returned so we will return 7
6. now node 2 has 4 & 7 returned from both sides so that's the LCA

TC: O(n) -> dfs traversal
SC: O(1) -> no extra space used only O(n) can be used for auxiliary stack space for a skewed tree
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
        if(root==NULL)
        {
            return NULL;
        }
        //if either of the nodes p/q is found then return that
        if(root==p || root==q)
        {
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //if the right child is not null then return the right child
        if(left==NULL && right!=NULL)
        {
            return right;
        }
        //if left child is not null then return left child
        else if(left!=NULL && right==NULL)
        {
            return left;
        }
        //if both are not null so we found the node below which p & q is present
        //this is why from one side p will be returned and from the other side q will be returned
        else if(left!=NULL && right!=NULL)
        {
            return root;
        }
        //if both left and right are NULL then we are at leaf node so return NULL
        return NULL;
}
