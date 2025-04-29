/**
 * Search an element
 */

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

Node *search_bst(Node *head, int find_val)
{
    Node *trav = head;
    while(trav != NULL)
    {
        if(trav->key == find_val)
        {
            return trav;
        }
        else if(trav->key <= find_val)
        {
            if(trav->right != NULL)
            {
                trav = trav->right;
            }
            else
            {
                std::cout<<"Node not Present"<<std::endl;
                return NULL;
            }
        }
        else if(trav->key > find_val)
        {
            if(trav->left != NULL)
            {
                trav = trav->left;
            }
            else
            {
                std::cout<<"Node not Present"<<std::endl;
                return NULL;
            }
        }
    }
    return NULL;
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

    int find_val;
    std::cout<<"Enter Val to Search : ";
    std::cin>>find_val;
    Node *ret = search_bst(head, find_val);
    if(ret != NULL)
    {
        std::cout<<"Node Found : "<<std::endl;
        std::cout<<"\t\tparent : "<<ret->p->key<<std::endl;
        std::cout<<"\t\tleft child : "<<((ret->left != NULL) ? ret->left->key : -1)<<std::endl;
        std::cout<<"\t\tright child : "<<((ret->right != NULL) ? ret->right->key : -1)<<std::endl;
    }

}