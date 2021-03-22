#include <iostream>
#include <stack>

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
            string ch;
            node *temp = root;
            while (true)
            {
                cout << "put node to left or right of "
                     << temp->data << " (l or r) : ";
                cin >> ch;
                if (ch[0] == 'l')
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        break;
                    }
                    temp = temp->left;
                }
                else if (ch[0] == 'r')
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

    void pre_order(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";
        pre_order(t->left);
        pre_order(t->right);
    }

    void in_order(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        pre_order(t->left);
        cout << t->data << " ";
        pre_order(t->right);
    }

    void post_order(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        pre_order(t->left);
        pre_order(t->right);
        cout << t->data << " ";
    }

    void pre_order_non_recursive(node *head)
    {

        if (head == NULL)
        {
            return;
        }

        stack<node *> s;
        s.push(head);

        while (s.empty() == false)
        {

            node *temp = s.top();
            cout << temp->data << " ";
            s.pop();

            if (temp->right)
            {
                s.push(temp->right);
            }
            if (temp->left)
            {
                s.push(temp->left);
            }
        }
    }

    void in_order_non_recursive(node *head)
    {
        node *temp = head;
        stack<node *> s;
        while (true)
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            if (s.empty())
            {
                break;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    void post_order_non_recursive(node *head)
    {
        stack<node *> s1;
        stack<node *> s2;

        s1.push(head);
        node *temp;
        while (s1.empty() == false)
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }

        while (s2.empty() == false)
        {
            node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
        }
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

int main()
{
    binary_tree tree;
    int exit = 0;
    while (exit == 0)
    {
        int ch;
        cout << "\nMenu :"
             << "\n1. create tree"
             << "\n2. pre order traversal recursive"
             << "\n3. in order traversal recursive"
             << "\n4. post order traversal recursive"
             << "\n5. pre order traversal non recursive"
             << "\n6. in order traversal non recursive"
             << "\n7. post order traversal non recursive";

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
            cout << "pre order traversal : ";
            tree.pre_order(tree.root);
            break;
        }
        case 3:
        {
            cout << "\n";
            cout << "in order traversal : ";
            tree.in_order(tree.root);
            break;
        }
        case 4:
        {
            cout << "\n";
            cout << "post order traversal : ";
            tree.post_order(tree.root);
            break;
        }
        case 5:
        {
            cout << "\n";
            cout << "pre order traversal : ";
            tree.pre_order_non_recursive(tree.root);
            break;
        }
        case 6:
        {
            cout << "\n";
            cout << "in order traversal : ";
            tree.in_order_non_recursive(tree.root);
            break;
        }
        case 7:
        {
            cout << "\n";
            cout << "in order traversal : ";
            tree.post_order_non_recursive(tree.root);
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