/**
 * Get Max and Min Node
 */

#include <iostream>

struct Node {
   int key;
   Node *left = NULL;
   Node *right = NULL;
   Node *p = NULL; 
};


Node *insert_bst(Node *root, int val)
{
    Node *new_node = new Node();
    new_node->key = val;
    
    if(root == NULL)
    {
        root = new_node;
        return root;
    }

    Node *temp = root;
    while(temp != NULL)
    {
        if(val >= temp->key)
        {
            if(temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new_node;
                new_node->p = temp;
                break;
            }
            
        }
        else
        {
            if(temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new_node;
                new_node->p = temp;
                break;
            }
            
        }
    }
    return root;

}

int max_node_bst(Node *root)
{
    Node *temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->key;
}

int min_node_bst(Node *root)
{
    Node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->key;
}

void print_inorder(Node *root)
{
    if(root->left != NULL)
    print_inorder(root->left);

    std::cout<<root->key<<" ";

    if(root->right != NULL)
    {
        print_inorder(root->right);
    }
}
int main()
{
    Node * root { NULL };
    int len, val;
    std::cout<<"Enter Array length : ";
    std::cin>>len;

    std::cout<<"Enter Array : ";
    for(int i = 0; i < len; i++)
    {
        std::cin>>val;
        root = insert_bst(root, val);
    }

    std::cout<<"inorder traversal :  ";
    print_inorder(root);
    std::cout<<std::endl;

    std::cout<<"Min Node : "<<min_node_bst(root)<<std::endl;
    std::cout<<"Max Node : "<<max_node_bst(root)<<std::endl;
    return 0;
}