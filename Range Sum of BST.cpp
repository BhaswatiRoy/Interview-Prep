Problem: https://leetcode.com/problems/range-sum-of-bst/description

/*
Approach:
1. Inorder Traversal and check if node value falls in range
2. If yes then store in the sum

TC: O(n)
SC: O(1)
*/

void dfs(int &sum, int low, int high, TreeNode *root)
{
        if(root==NULL)
        {
            return;
        }
        if(root->val>=low && root->val<=high)
        {
            sum+=root->val;
        }
        dfs(sum,low,high,root->left);
        dfs(sum,low,high,root->right);
}

int rangeSumBST(TreeNode* root, int low, int high) 
{
        int sum=0;
        dfs(sum,low,high,root);
        return sum;
}
