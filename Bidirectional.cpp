#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *prev, *next;
};

class linked_list
{
public:
    node *head, *tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void create(int n)
    {
        if (head == NULL)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Node index " << i << " ";
                node *temp = enter_node_data();
                insert_at_end(temp);
            }
        }
    }

    void insert_at_start(node *new_node)
    {
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insert_at_end(node *temp)
    {
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }

    void insert_at_index(node *new_node, int n)
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "List not created!\n";
        }
        else
        {
            int i;
            for (i = 0; i < n - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "Index Does Not Exist!\n";
                    break;
                }
            }
            if (temp != NULL)
            {
                if (n == 0)
                {
                    insert_at_start(new_node);
                }
                else
                {
                    new_node->next = temp->next;
                    temp->next->prev = new_node;

                    temp->next = new_node;
                    new_node->prev = temp;
                }
            }
        }
    }

    void delete_at_start()
    {
        if (head == NULL)
        {
            cout << "\nNo elements to delete!\n";
        }
        else
        {
            node *del = head;
            head = head->next;
            delete del;
        }
    }

    void delete_at_end()
    {
        if (head == NULL)
        {
            cout << "\nNo elements to delete!\n";
        }
        else
        {
            node *del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
        }
    }
    void delete_at_index(int n)
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "\nNo elements to delete!\n";
        }
        else
        {
            int i;
            for (i = 0; i < n - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "Index Does Not Exist!\n\n";
                    break;
                }
            }
            if (temp != NULL)
            {
                if (n == 0)
                {
                    delete_at_start();
                }
                else
                {
                    node *del = temp->next;
                    temp->next = del->next;
                    if (del->next == NULL)
                    {
                        tail = temp;
                    }
                    else
                    {
                        del->next->prev = temp;
                    }
                    delete del;
                }
            }
        }
    }

    void concat(linked_list new_list)
    {
        node *temp = new_list.head;
        while (temp != NULL)
        {
            insert_at_end(temp);
            temp = temp->next;
        }
    }

    void reverse()
    {
        if (head == NULL)
        {
            cout << "List not created!\n";
        }
        node *curr = head;
        node *prev = NULL;
        node *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }

        head = prev;
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        tail = curr;

        cout << "\nReversed List :";
        display();
    }

    void display()
    {
        node *temp = head;
        int i = 0;

        cout << "\nIndex\t";
        while (temp != NULL)
        {
            cout << i << "\t";
            temp = temp->next;
            i = i + 1;
        }

        temp = head;
        cout << "\nData\t";
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
            i = i + 1;
        }
        cout << endl;
    }

    node *enter_node_data()
    {
        node *temp = new node;
        int x;
        cout << "Enter node data (int): ";
        cin >> x;
        temp->data = x;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }
};

int main()
{
    linked_list list;
    int exit = 0;

    while (exit == 0)
    {
        int ch;
        cout << "Menu :"
             << "\n1. create"
             << "\n2. insert at start"
             << "\n3. insert at end"
             << "\n4. insert at index"
             << "\n5. delete at start"
             << "\n6. delete at end"
             << "\n7. delete at index"
             << "\n8. conact"
             << "\n9. reverse"
             << "\n10. display\n";

        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "\nNumber of node you want to enter: ";
            cin >> n;
            list.create(n);
            cout << "\n";
            break;
        }
        case 2:
        {
            node *temp = list.enter_node_data();
            list.insert_at_start(temp);
            cout << "\n";
            break;
        }
        case 3:
        {
            node *temp = list.enter_node_data();
            list.insert_at_end(temp);
            cout << "\n";
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter the index to push the node into: ";
            cin >> n;
            node *temp = list.enter_node_data();
            list.insert_at_index(temp, n);
            cout << "\n";
            break;
        }
        case 5:
        {
            list.delete_at_start();
            cout << "\n";
            break;
        }
        case 6:
        {
            list.delete_at_end();
            cout << "\n";
            break;
        }
        case 7:
        {
            int n;
            cout << "Enter the index to delete node: ";
            cin >> n;
            list.delete_at_index(n);
            cout << "\n";
            break;
        }
        case 8:
        {
            int n;
            linked_list new_list;
            cout << "\nNumber of node you want to enter: ";
            cin >> n;
            new_list.create(n);
            list.concat(new_list);
            cout << "\n";
            break;
        }
        case 9:
        {
            list.reverse();
            cout << "\n";
            break;
        }
        case 10:
        {
            list.display();
            cout << "\n";
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