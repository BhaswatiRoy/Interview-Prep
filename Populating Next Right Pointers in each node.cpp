Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

/*
Approach 1: extra space
1. Store all level wise nodes in 2d vector
2. Make each node's next pointer to the next node in the level
3. Only last node of each level points to NULL
TC: O(n) -> single pass traversal
SC: O(n) -> storing all n nodes

Approach 2: no extra space
1. Keep a "prev" node for each level and initialise it to NULL
2. Then for each node in level check "prev"
3. If "prev" is NULL means this is 1st node of level so set "prev" to that node
4. If "prev" is not NULL means this is not 1st node of the level so "prev" next will point to "curr" node
5. Last node of each level will point to NULL.
TC: O(n) -> single pass traversal
SC: O(1) -> no exttra space
*/

//with extra space
Node* connect(Node* root) 
{
        if(root==NULL)
        {
            return NULL;
        }
        vector<vector<Node*>>levels;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<Node*>temp;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                temp.push_back(node);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            levels.push_back(temp);
        }
        int n=levels.size();
        for(int j=0;j<n;j++)
        {
            int m=levels[j].size();
            for(int k=0;k<m-1;k++)
            {
                Node* currnode=levels[j][k];
                Node* nextnode=levels[j][k+1];
                currnode->next=nextnode;
            }
            Node* lastnode=levels[j][m-1];
            lastnode->next=NULL;
        }
        return root;
}

//without extra space
Node* connect(Node* root) 
{
        if(root==NULL)
        {
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            //initialise the prev for a level
            Node* prev=NULL;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                //1st node of the level from left
                if(prev==NULL)
                {
                    prev=node;
                }
                //connect the last node pointer to current node
                else
                {
                    prev->next=node;
                    prev=node;
                }
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            //last node of the level points to NULL
            prev->next=NULL;
        }
        return root;
}
