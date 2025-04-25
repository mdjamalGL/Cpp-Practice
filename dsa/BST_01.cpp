#include <iostream>

struct Node {
   int key;
   Node *left = NULL;
   Node *right = NULL;
   Node *p = NULL; 
};


Node *insert_bst(Node *head, int val)
{
    Node *new_node = new Node();
    new_node->key = val;
    
    if(head == NULL)
    {
        head = new_node;
        return head;
    }

    Node *temp = head;
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
    return head;

}

void print_inorder(Node *head)
{
    if(head->left != NULL)
    print_inorder(head->left);

    std::cout<<head->key<<" ";

    if(head->right != NULL)
    {
        print_inorder(head->right);
    }
}
int main()
{
    Node * head { NULL };
    int len, val;
    std::cout<<"Enter Array length : ";
    std::cin>>len;

    std::cout<<"Enter Array : ";
    for(int i = 0; i < len; i++)
    {
        std::cin>>val;
        head = insert_bst(head, val);
    }

    std::cout<<"inorder traversal :  ";
    print_inorder(head);
    std::cout<<std::endl;
    
}