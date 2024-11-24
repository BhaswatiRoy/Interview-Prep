Problem: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description

/*
Approach:
1. Perform a BFS traversal and we will keep a variable "null_found" to keep track if we find a null node
2. If we find a left child is null then we update "null_found" to true
3. If we find a non null left child then we check if "null_found" is true then we instantly return false
   Because we found a null before and non null later 
4. Otherwise we will push the non null child to the queue
5. If we find a non null right child then we check if "null_found" is tre then we instantly return false
   Because we found a null before and non null later.
6. Otherwise we will push the non null child to the queue

TC: O(n) -> BFS traversal
SC: O(n) -> queue space
*/

bool bfs(TreeNode *root)
{
        queue<TreeNode*>q;
        q.push(root);
        bool null_found=false;
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            //any left child found null then we update null_found to true
            if(node->left==NULL)
            {
                null_found=true;
            }
            else 
            {
                //if left child is not null & a null was previously found in this level then false
                if(null_found==true)
                {
                    return false;
                }
                q.push(node->left);
            }
            //any right child found null then we update null_found to true
            if(node->right==NULL)
            {
                null_found=true;
            }
            else
            {
                //if right child is not null & a null was previously found in this level then false
                if(null_found==true)
                {
                    return false;
                }
                q.push(node->right);
            }
        }
        return true;
}

bool isCompleteTree(TreeNode* root) 
{
        bool ans=bfs(root);
        return ans;
}
