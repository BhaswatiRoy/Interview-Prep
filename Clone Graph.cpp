Problem: https://leetcode.com/problems/clone-graph/description

/*
1. Create a new graph
2. Do DFS on current graph and store each node of current graph to new graph
3. Mark the nodes as visited for current graph to not visit again
TC: O(V+E) -> simple DFS traversal
SC: O(V+E) -> storing a new graph
*/

void dfs(Node *node, Node *copygraph, vector<Node*>&visited)
{
        //add the node in visited vector
        visited[copygraph->val]=copygraph;
        for(auto adjnodes:node->neighbors)
        {
            //if the adjacent/neighbor nodes are not visited
            if(visited[adjnodes->val]==NULL)
            {
                Node* newnode=new Node(adjnodes->val);
                //push that node into neighbors of the copygraph reference
                (copygraph->neighbors).push_back(newnode);
                //recursively call function for other nodes
                dfs(adjnodes,newnode,visited);
            }
            //if the adjacent/neighbor nodes are visited
            else
            {
                //push that node into neighbors of the copygraph reference
                (copygraph->neighbors).push_back(visited[adjnodes->val]);
            }
        }
}

Node* cloneGraph(Node* node) 
{
        if(node==NULL)
        {
            return NULL;
        }
        vector<Node*>visited(1000,NULL);
        //create graph copy with given node value
        Node *copygraph=new Node(node->val);
        //call dfs to clone the entire graph 
        dfs(node,copygraph,visited);
        return copygraph;
}
