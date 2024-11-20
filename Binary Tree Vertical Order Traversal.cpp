Problem: https://leetcode.com/problems/binary-tree-vertical-order-traversal

/*
        1 (0,0)
      /        \
     2 (1,-1)   3 (1,1)
  /        \
4 (2,-2)    5 (2,0)
storing (horizontal level, vertical level)

Approach:
1. Store as {nodes, horizontal level, vertical level} in the queue
2. horizontal + 1 for all children
3. vertical + 1 for right children & vertical - 1 for left children
4. store nodes based on the vertical level in a map
5. then finally convert the map to a vector

TC: O(n) -> BFS traversal 
SC: O(n) -> queue datastructure used
*/

vector<vector<int>> verticalOrder(TreeNode* root) 
{
        if(root==NULL)
        {
            return {};
        }
        //{node, {horizontal point, vertical point}}
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,vector<int>>mp;
        vector<vector<int>>ans;
        while(!q.empty())
        {
            auto temp=q.front();
            TreeNode* node = temp.first;
            int horizontal = temp.second.first;
            int vertical = temp.second.second;
            //store nodes according to their vertical position in the map
            mp[vertical].push_back(node->val);
            q.pop();
            //for left & right children update the horizontal & vertical indices properly
            if(node->left!=NULL)
            {
                //horizontal+1, vertical-1
                q.push({node->left,{horizontal+1,vertical-1}});
            }
            if(node->right!=NULL)
            {
                //horizontal+1, vertical+1
                q.push({node->right,{horizontal+1,vertical+1}});
            }
        }
        //then finally store the nodes into a vector based on vertical order
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
}
