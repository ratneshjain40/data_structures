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

class binary_tree
{
public:
    node *root;

    binary_tree()
    {
        root = NULL;
    }

    void create()
    {
        int exit = 0;
        int ch;

        while (exit == 0)
        {
            add_node();
            cout << "do you want to add more nodes? : 1(yes) or 0(no)";
            cin >> ch;
            if (!ch)
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
            int exit = 0;
            char ch;
            node *temp = root;
            while (exit == 0)
            {
                cout << "put node to left or right of "
                     << temp->data;
                cin >> ch;
                if (ch == 'l')
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        break;
                    }
                    temp = temp->left;
                }
                else
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

    int exit = 0;
    while (exit == 0)
    {
        binary_tree tree;
        int ch;
        cout << "Menu :"
             << "\n1. create"
             << "\n2. insert at start"
             << "\n3. insert at end"
             << "\n4. insert at index"
             << "\n5. delete at start"
             << "\n6. delete at end"
             << "\n7. delete at index"
             << "\n8. reverse"
             << "\n9. conact"
             << "\n10. display\n";

        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            tree.create();
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