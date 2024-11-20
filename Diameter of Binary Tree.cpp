Problem: https://leetcode.com/problems/diameter-of-binary-tree

/*
        1
      /   \
     2     3
    /  \
   4    5
Approach:
1. every node's height is calculated
2. then left & right subtree height is calculated and +1 is added to find diameter of the node (+1 for considering root of left & right subtree)
3. eg node 1 has left height as 2 & right height as 1, so total diameter is (2+1)+1 = 4

TC: O(n) -> dfs traversal
SC: O(1) -> no extra space used
*/


//this function is same as finding height of a binary tree 
//in finding height function we have heights of both left & right subtree 
int dfs(TreeNode* root, int &maxi)
{
        if(root==NULL)
        {
            return 0;
        }
        int leftht=dfs(root->left,maxi);
        int rightht=dfs(root->right,maxi);
        //maximum path length is maximum of path length and lh+rh value
	//this is an extra parameter used over height function to find max value of path which gets stored
        maxi=max(maxi,leftht+rightht);
        //in end we are again returning same value as height function did for the root node considered at any point
        return 1+max(leftht,rightht);
}

int diameterOfBinaryTree(TreeNode* root) 
{
        int maxi=0;
        dfs(root,maxi);
        return maxi;
}
