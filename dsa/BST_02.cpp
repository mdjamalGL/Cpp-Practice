/**
 * Delete node
 * Conditions : Node has
 * 1. no child : just delete node
 * 2. left child only : replace node with its left child
 * 3. right child only : replace node with its right child
 * 4. Both left and right child : replace node with left most child of the right child node,
 *    Suppose that replaceable_node is 'k', then the left child (subtree) of del_node becomes left child of replaceable_node,
 *    and the right child (subtree) of del_node becomes the right child of replaceable node.
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
 
 void delete_bst(Node *root, int x)
 {
    //01 condition
    Node *del_node = root;
    while(del_node != NULL)
    {
        if(del_node->key == x)
        break;

        if(del_node->key > x )
        {
            if(del_node->left != NULL)
            {
                del_node = del_node->left;
            }
            else
            {
                std::cout<<"Node is not available to delete"<<std::endl;
                return;
            }
        }
        else if(del_node->key <= x)
        {
            if(del_node->right != NULL)
            {
                del_node = del_node->right;
            }
            else
            {
                std::cout<<"Node is not available to delete"<<std::endl;
                return;
            }
        }
            
    }


    //01
    Node *parent = del_node->p;
    if(del_node->left == NULL && del_node->right == NULL)
    {
        
        if(parent->left == del_node)
        {
            delete del_node;
            parent->left = NULL;
        }
        else
        {
            delete del_node;
            parent->right = NULL;
        }
    }
    //02
    else if(del_node->left == NULL && del_node->right != NULL)
    {
        if(parent->left == del_node)
        {
            parent->left = del_node->right;
            del_node->right->p = parent;
            delete del_node;
        }
        else
        {
            parent->right = del_node->right;
            del_node->right->p = parent;
            delete del_node;
        }
    }
    //03
    else if(del_node->left != NULL && del_node->right == NULL)
    {
        if(parent->left == del_node)
        {
            parent->left = del_node->left;
            del_node->left->p = parent;
            delete del_node;
        }
        else
        {
            parent->right = del_node->left;
            del_node->left->p = parent;
            delete del_node;
        }
    }
    //04
    else
    {
        Node *replace_node = del_node->right;
        while(replace_node->left != NULL)
        {
            replace_node = replace_node->left;
            if(replace_node->left == NULL)
            {
                replace_node->p->left = NULL;
            }
        }
        replace_node->left = del_node->left;
        if(parent->left == del_node)
        {
            parent->left = replace_node;
            replace_node->p = parent;
            delete del_node;
        }
        else
        {
            parent->right = replace_node;
            replace_node->p = parent;
            delete del_node;
        }
        replace_node = NULL;
    }
    del_node = NULL;
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

     int del_val = 0;
     std::cout<<"Enter Node to Delete : ";
     std::cin>>del_val;

     delete_bst(root, del_val);

     std::cout<<"inorder traversal after delete : ";
     print_inorder(root);
     std::cout<<std::endl;
     
 }