Problem:
Part 1: https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/
Part 2: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description

For part 1 there are no additional conditions

For part 2 the traversal requires sorting by vertical order first, 
then by the row level (or horizontal distance), 
and finally by value for nodes that share the same row and vertical position.

For part 1, we don't need to store horizontal-level data, but for part 2, we need to because later, 
we will sort based on horizontal-level data.

/*
        1 (0,0)
      /        \
     2 (1,-1)   3 (1,1)
  /        \
4 (2,-2)    5 (2,0)
storing (horizontal level, vertical level)

1. Do level order traversal and store {node, {horizontal, vertical}} in queue
2. In map store key = vertical & value = {horizontal, node->val}
3. Do level order traversal and store all nodes on the map based on their vertical position
4. Now for each vertical position, the map has nodes stored as {horizontal, node->val}
5. So if we sort it, then it will be sorted as a horizontal position the node value

TC: O(n) + O(nlogn) = O(nlogn) -> BFS traversal + sorting in the worst case of a skewed tree where all nodes are in 1 vertical
SC: O(n) + O(n) = O(n) -> queue + map
*/

vector<vector<int>> bfs(TreeNode *root)
{
        if(root==NULL)
        {
            return {};
        }
        queue<pair<TreeNode*,pair<int,int>>>q;
        // Store {vertical -> {horizontal, node->val}}
        map<int,vector<pair<int,int>>>mp;
        //{node,{horizontal,vertical}}
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int size=q.size();
            //for every horizontal level store in a map according to vertical level
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                TreeNode* node=temp.first;
                int horizontal=temp.second.first;
                int vertical=temp.second.second;
                q.pop();
                mp[vertical].push_back({horizontal, node->val});
                //if children are not null then push them to the queue
                if(node->left!=NULL)
                {
                    q.push({node->left,{horizontal+1, vertical-1}});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right,{horizontal+1, vertical+1}});
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            vector<pair<int,int>>temp=it.second;
            //multiple nodes in same row,col needs to be in sorted format
            //sorted by horizontal level first then node value
            sort(temp.begin(),temp.end());
            vector<int>v;
            for(auto it:temp)
            {
                v.push_back(it.second);
            }
            ans.push_back(v);
        }
        return ans;
}

vector<vector<int>> verticalTraversal(TreeNode* root) 
{
        vector<vector<int>>ans=bfs(root);
        return ans;
}
