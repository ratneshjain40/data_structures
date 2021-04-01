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
        cout << "No of nodes to enter : ";
        cin >> ch;

        for (int i = 0; i < ch; i++)
        {
            cout << "Node " << (i + 1) << " ";
            add_node();
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
                head->right = delete_node(head->right, temp->data);
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

    struct node *search(struct node *root, int data)
    {
        if (root == NULL || root->data == data)
            return root;

        if (root->data < data)
            return search(root->right, data);

        return search(root->left, data);
    }

    node *enter_new_node()
    {
        int x;
        cout << "Enter node data (int): ";
        cin >> x;
        node *temp = new node(x);
        return temp;
    }
};

int main()
{
    BST tree;
    int exit = 0;
    while (exit == 0)
    {
        int ch;
        cout << "\nMenu :"
             << "\n1. Create tree"
             << "\n2. Search node"
             << "\n3. Delete node";

        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            tree.create();
            break;
        }
        case 2:
        {
            cout << "\n";
            int data;
            cout << "Enter node to search : ";
            cin >> data;
            node *search = tree.search(tree.root, data);
            if (search != NULL)
            {
                cout << "Node Found in BST\n";
            }
            else
            {
                cout << "Node NOT in BST!\n";
            }
            break;
        }
        case 3:
        {
            cout << "\n";
            int data;
            cout << "Enter node to delete : ";
            cin >> data;
            node *del = tree.delete_node(tree.root, data);
            if (del != NULL)
            {
                cout << "Node Deleted in BST\n";
            }
            else
            {
                cout << "Node NOT in BST!\n";
            }
            break;
        }
        default:
        {
            exit = 1;
            break;
        }
        }
    }
    return 0;
}