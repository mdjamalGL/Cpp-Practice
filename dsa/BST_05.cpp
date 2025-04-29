/**
 * Get Predecessor and Successors of a Node;
 * Predecessor : Node with the highest Key less than the Node
 * Successor : Node with the least key that is higer than the Node
 *
 * Also called Inorder Successor and Inorder Predecessor
 */

#include <iostream>

struct Node
{
    int key;
    Node *left = NULL;
    Node *right = NULL;
    Node *p = NULL;
};

Node *insert_bst(Node *root, int val)
{
    Node *new_node = new Node();
    new_node->key = val;

    if (root == NULL)
    {
        root = new_node;
        return root;
    }

    Node *temp = root;
    while (temp != NULL)
    {
        if (val >= temp->key)
        {
            if (temp->right != NULL)
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
            if (temp->left != NULL)
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

Node *search_bst(Node *head, int find_val)
{
    Node *trav = head;
    while (trav != NULL)
    {
        if (trav->key == find_val)
        {
            return trav;
        }
        else if (trav->key <= find_val)
        {
            if (trav->right != NULL)
            {
                trav = trav->right;
            }
            else
            {
                std::cout << "Node not Present" << std::endl;
                return NULL;
            }
        }
        else if (trav->key > find_val)
        {
            if (trav->left != NULL)
            {
                trav = trav->left;
            }
            else
            {
                std::cout << "Node not Present" << std::endl;
                return NULL;
            }
        }
    }
    return NULL;
}

Node *max_node_bst(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *min_node_bst(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *get_predecessor_bst(Node *head, int node_val)
{
    Node *temp = search_bst(head, node_val);
    if(temp->left != NULL)
    {
        return max_node_bst(temp->left);
    }
    return NULL;
}

Node *get_successor_bst(Node *head, int node_val)
{
    Node *temp = search_bst(head, node_val);
    if(temp->right != NULL)
    {
        return min_node_bst(temp->right);
    }
    return NULL;
}

void print_inorder(Node *root)
{
    if (root->left != NULL)
        print_inorder(root->left);

    std::cout << root->key << " ";

    if (root->right != NULL)
    {
        print_inorder(root->right);
    }
}
int main()
{
    Node *root{NULL};
    int len, val;
    std::cout << "Enter Array length : ";
    std::cin >> len;

    std::cout << "Enter Array : ";
    for (int i = 0; i < len; i++)
    {
        std::cin >> val;
        root = insert_bst(root, val);
    }

    std::cout << "inorder traversal :  ";
    print_inorder(root);
    std::cout << std::endl;

    int node_val;
    std::cout << "Enter Node to get Predecessor and Successor : ";
    std::cin >> node_val;

    Node *predecessor = get_predecessor_bst(root,node_val);
    Node *successor = get_successor_bst(root, node_val);

    std::cout<< "Predecessor Node : " << predecessor->key << std::endl;
    std::cout << "Successor Node : " << successor->key << std::endl;
    return 0;
}