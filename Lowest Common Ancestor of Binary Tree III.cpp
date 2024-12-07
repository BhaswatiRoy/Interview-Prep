Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/description/

Left, Right & Parent pointers
Both nodes are definitely in tree

/*
Approach:
1. Make copies of p & q as p_copy & q_copy. We need the actual nodes later so we make copies
2. Now traverse p_copy &  q_copy till parent reached NULL 
3. If p_copy reaches NULL set it to q
4. If q_copy reaches NULL set it to p
5. Then again start traversing till both of them are equal
6. And the node where they are equal is their LCA.

TC: O(2h) = O(2) -> h = height of the tree
SC: O(1) -> no extra space used
*/

//start traversing back to parent nodes
Node* lowestCommonAncestor(Node* p, Node * q) 
{
        //create copy nodes as we will need actual nodes later
        Node *p_copy=p;
        Node *q_copy=q;
        //traverse till both nodes are not equal
        while(p_copy!=q_copy)
        {
            //once p_copy reach root so no parent set it to opp node q
            if(p_copy->parent==NULL)
            {
                p_copy=q;
            }
            //otherwise keep iterating to parent node
            else
            {
                p_copy=p_copy->parent;
            }
            //once q_copy reach root so no parent set it to opp node p
            if(q_copy->parent==NULL)
            {
                q_copy=p;
            }
            //otherwise keep iterating to parent node
            else
            {
                q_copy=q_copy->parent;
            }
        }
        //return the node where both p_copy & q_copy are same thats the LCA
        return p_copy;
}
