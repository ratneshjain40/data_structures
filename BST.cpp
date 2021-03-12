#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    void create()
    {
        int ch;

        while (true)
        {
            add_node();
            cout << "continue adding nodes? 1-yes || 0-no : ";
            cin >> ch;
            if (ch != 1)
            {
                break;
            }
        }
    }

    void add_node()
    {
        node *new_node = enter_new_node();
        if (root == NULL)
        {
            root = new_node;
        }
        else
        {
            node *temp = root;
            while (true)
            {
                if (new_node->data <= temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        break;
                    }
                    temp = temp->left;
                }
                else if (new_node->data > temp->data)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new_node;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    

    node *delete_node(node *head, int data)
    {
        if (head == NULL)
        {
            return head;
        }
        if (data < head->data)
        {
            head->left = delete_node(head->left, data);
        }
        else if (data > head->data)
        {
            head->right = delete_node(head->right, data);
        }
        else
        {
            if (head->left == NULL && head->right == NULL)
            {
                delete head;
                head = NULL;
            }
            else if (head->left == NULL)
            {
                node *temp = head;
                head = head->right;
                delete temp;
            }
            else if (head->right == NULL)
            {
                node *temp = head;
                head = head->left;
                delete temp;
            }
            else
            {
                node *temp = find_min_node(head->right);
                head->data = temp->data;
                head->right = delete_node(head->right,temp->data);
            }
        }
        return head;
    }

    node *find_min_node(node *t)
    {
        if (t->left == NULL)
        {
            return t;
        }
        return find_min_node(t->left);
    }

    node *enter_new_node()
    {
        int x;
        cout << "\nEnter node data (int): ";
        cin >> x;
        node *temp = new node(x);
        return temp;
    }
};