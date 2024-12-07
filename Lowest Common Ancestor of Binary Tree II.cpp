Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description

Left & Right pointers only
Both nodes might not be in the tree
So we keep extra boolean pointers found_p, found_q
This checks in last, whether we found p & q

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
2. perform DFS traversal till we reach a required node say 4, then we will return 4, and set found_p=true
3. again when we reach 6, we will return NULL because no desired node was found
4. but if we reach 7, we will return 7
5. now node 5 has NULL & 7 returned so we will return 7, and set found_q=true
6. now node 2 has 4 & 7 returned from both sides so that's the LCA
7. In end we check if both found_p & found_q are true then we return LCA or return NULL

TC: O(n) -> dfs traversal
SC: O(1) -> no extra space used only O(n) can be used for auxiliary stack space for a skewed tree
*/

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q, bool &found_p, bool &found_q)
{
        if(root==NULL)
        {
            return NULL;
        }
        //doing recursive calls first and then check if we found p or q
        TreeNode *left=lca(root->left,p,q,found_p,found_q);
        TreeNode *right=lca(root->right,p,q,found_p,found_q);
        if(root==p)
        {
            found_p=true;
            return root;
        }
        else if(root==q)
        {
            found_q=true;
            return root;
        }
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
        return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
        bool found_p=false;
        bool found_q=false;
        TreeNode* lca_node=lca(root,p,q,found_p,found_q);
       if(found_p==true && found_q==true)
       {
            return lca_node;
       }
       return NULL;
}
