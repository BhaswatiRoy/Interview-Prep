Problem: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/

/*
Approach 1: not in place
1. create a vector of the sorted elements from inorder traversal of BST
2. Convert the vector to a doubly linked list

TC: O(n)
SC: O(1)

Approach 2: in place
        4
      /   \
    2      5
  /  \
1      3

1. Inorder traversal of BST gives sorted format 
2. Set nodes *first & *last to NULL initially
3. Keep on traversing left subtree till we get the lowest element
4. while traversing if we get last == NULL means got the lowest element so set it as first & last
   (when we reach node 1) 
5. if we get last != NULL means we already got last element before this 
   (when we reach node 2)
6. so connect last & first elements and do this for all other nodes
7. in the end also connect last & first nodes with eachother

TC: O(n)
SC: O(1)
*/

void inorder(Node *root, Node*&first, Node *&last)
{
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,first,last);
        //if last is null so we reached the lowest value
        if(last==NULL)
        {
            first=root;
        }
        //if not null means we got a first & last value before this
        //so we connect last->right to current root
        //and we connect current root->left to last->right
        if(last!=NULL)
        {
            last->right=root;
            root->left=last;
        }
        //after operation we always set last to current root
        last=root;
        inorder(root->right,first,last);
}

Node* treeToDoublyList(Node* root) 
{
        if(root==NULL)
        {
            return NULL;
        }
        Node *first=NULL;
        Node *last=NULL;
        //inorder traversal of BST gives us sorted values
        inorder(root,first,last);
        //in end we connect last & first
        first->left=last;
        last->right=first;
        return first;
}
