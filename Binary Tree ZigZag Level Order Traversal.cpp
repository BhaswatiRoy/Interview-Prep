Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description

/*
1. Keep a level value set to 0 initially to track the levels
2. Do normal BFS traversal and if we reach to any level which is even then push to "ans" vector
3. If we reach to any level which is odd then reverse and push to "ans" vector

TC: O(n) + O(n) = O(n) -> BFS traversal + reversal
SC: O(n) -> stores all n nodes of tree
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<vector<int>>ans;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            if(level%2==0)
            {
                ans.push_back(temp);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            level++;
        }
        return ans;
}
