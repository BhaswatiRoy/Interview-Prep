Problem: https://leetcode.com/problems/binary-tree-right-side-view

/*
Approach:
1. Level order BFS traversal
2. The last node of each level is the right-side view of the binary tree
3. store the last node after every level traversal and push it to a vector

TC: O(n) -> simple BFS traversal
SC: O(n) -> considering the vector to store right side view
*/

//last node of each level in level order traversal is the right side view
vector<int> bfs(TreeNode *root)
{
        queue<TreeNode*>q;
        q.push(root);
        vector<int>rightsideview;
        TreeNode *lastnode=root;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                lastnode=node;
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            rightsideview.push_back(lastnode->val);
        }
        return rightsideview;
}

vector<int> rightSideView(TreeNode* root) 
{
        if(root==NULL)
        {
            return {};
        }
        vector<int>rightsideview=bfs(root);
        return rightsideview;
}
