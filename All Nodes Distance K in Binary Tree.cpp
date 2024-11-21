Problem: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description

/*
Approach:
1. Convert the binary tree to an undirected graph by creating an adjacency list using DFS traversal
2. Do BFS traversal on the undirected graph starting from the target node
3. When we reach level k on the undirected graph then store all nodes in that level and return
4. Keep a currlevel variable to track the current level

TC: O(n) + O(n) = O(n) -> 2 traversals dfs+bfs
SC: O(V+E) = O(n + (n-1)) = O(n) -> n nodes & n-1 edges since this is binary tree
*/

//convert the tree to an undirected graph by converting nodes to an adjacency list
void treetograph(TreeNode* root, vector<vector<int>>&adj)
{
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            treetograph(root->left,adj);
        }
        if(root->right!=NULL)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            treetograph(root->right,adj);
        }
}

//do a bfs on the graph till level k starting from the target node
vector<int> graphbfs(int start, int k, vector<vector<int>>&adj, vector<int>&visited)
{
        queue<int>q;
        q.push(start);
        visited[start]=1;
        //set level as 0 from the target node 
        int currlevel=0;
        while(!q.empty())
        {
            int size=q.size();
            //if we reach level = k then store all nodes in the current level and return
            if(currlevel==k)
            {
                vector<int>levels;
                while(!q.empty())
                {
                    levels.push_back(q.front());
                    q.pop();
                }
                return levels;
            }
            //otherwise keep traversing level-wise and push nodes
            for(int i=0;i<size;i++)
            {
                int node=q.front();
                q.pop();
                for(int j=0;j<adj[node].size();j++)
                {
                    int adjnode=adj[node][j];
                    if(visited[adjnode]==0)
                    {
                        visited[adjnode]=1;
                        q.push(adjnode);
                    }
                }
            }
            //increment level to move to the next level
            currlevel++;
        }
        //if no nodes at distance k then return an empty vector
        return {};
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
        //in constraints its mentioned 500 nodes at max
        vector<vector<int>>adj(501);
        vector<int>visited(501,0);
        treetograph(root,adj);
        vector<int>levels=graphbfs(target->val,k,adj,visited);
        return levels;
}
