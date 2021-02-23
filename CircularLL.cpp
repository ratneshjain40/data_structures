#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
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
                cout << "Node index " << i;
                node *temp = enter_new_node();
                insert_at_end(temp);
            }
        }
        else
        {
            cout << "List already created!";
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
            int i = 0;
            new_node->next = head;
            head = new_node;
            tail->next = head;
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
            tail = tail->next;
            tail->next = head;
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
                    temp->next = new_node;
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
            tail->next = head;
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
            node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            node *del = temp->next;
            tail = temp;
            tail->next = head;
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
                    temp->next = temp->next->next;
                    delete del;
                }
            }
        }
    }

    void reverse()
    {
        node *curr = head;
        node *prev = NULL;
        node *next;
        while (true)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr == head)
            {
                break;
            }
        }

        head = prev;
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        tail = curr;
        tail->next = head;
    }

    void concat(linked_list new_list)
    {
        node *temp = new_list.head;
        while (true)
        {
            insert_at_end(temp);
            temp = temp->next;
            if (temp == head)
            {
                break;
            }
        }
    }

    void display()
    {
        node *temp = head;
        int i = 0;

        cout << "\nIndex\t";
        while (true)
        {
            cout << i << "\t";
            temp = temp->next;
            i = i + 1;
            if (temp == head)
            {
                break;
            }
        }

        temp = head;
        cout << "\nData\t";
        while (true)
        {
            cout << temp->data << "\t";
            temp = temp->next;
            i = i + 1;
            if (temp == head)
            {
                break;
            }
        }
        cout << endl;
    }

    node *enter_new_node()
    {
        node *temp = new node;
        int x;
        cout << "\nEnter node data (int): ";
        cin >> x;
        temp->data = x;
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
             << "\n8. reverse"
             << "\n9. conact"
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
            node *temp = list.enter_new_node();
            list.insert_at_start(temp);
            cout << "\n";
            break;
        }
        case 3:
        {
            node *temp = list.enter_new_node();
            list.insert_at_end(temp);
            cout << "\n";
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter the index to push the node into: ";
            cin >> n;
            node *temp = list.enter_new_node();
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
            list.reverse();
            cout << "\n";
            break;
        }
        case 9:
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