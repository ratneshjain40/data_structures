#include <iostream>
#include <list>
#include <iterator>
#include <map>

using namespace std;

class node
{
public:
    int vertex;
    list<node> adjacent;
};

class Graph
{
private:
    node adjacency_list[20];
    int size;
    map<int, bool> visited;

public:
    int get_size()
    {
        return size;
    }

    node get_node(int vertex)
    {
        return adjacency_list[vertex];
    }

    void dfs(int v)
    {

        visited[v] = true;
        node n = get_node(v);
        cout << n.vertex << " ";
        list<node>::iterator it;

        for (it = n.adjacent.begin(); it != n.adjacent.end(); ++it)
        {
            if (!visited[(*it).vertex])
            {
                dfs((*it).vertex);
            }
        }
    }

    void create(int n)
    {
        size = n;
        for (int i = 0; i < size; i++)
        {
            adjacency_list[i].vertex = i;
        }
        cout << "Enter adjacent nodes after the '---->' \n";
        cout << "For each node you can enter " << n - 1 << " adjacent nodes, enter any char ('a') value to exit \n";
        cout << "\n";
        enter_adjacent_nodes();
    }

    void enter_adjacent_nodes()
    {
        int num;
        for (int i = 0; i < size; i++)
        {
            show_node(adjacency_list[i]);
            // Number of nodes we can enter
            num = (size - adjacency_list[i].adjacent.size()) - 1;

            while (num > 0)
            {
                char ch;
                int vertex;
                cin >> ch;
                // Convert input to int by subtracting 48 ascii value of 0
                vertex = ch - '0';
                // If in our integer range means its valid user input or else we need to break
                if (vertex < size)
                {
                    add_adjacent(i, vertex);
                    add_adjacent(vertex, i);
                }
                else
                {
                    break;
                }
                num--;
            }
            // Ignores any left over chars from previous input upto 10000 chars
            cin.ignore(10000, '\n');
        }
    }

    void add_adjacent(int i, int j)
    {
        node a = adjacency_list[i];
        node b = adjacency_list[j];

        // Same node cant be added
        if (i == j)
        {
            return;
        }
        // if already added, ignore
        list<node>::iterator it;

        for (it = a.adjacent.begin(); it != a.adjacent.end(); ++it)
        {
            if (it->vertex == b.vertex)
            {
                return;
            }
        }
        adjacency_list[i].adjacent.push_back(adjacency_list[j]);
        return;
    }

    void show_node(node parent)
    {
        list<node> lst = parent.adjacent;
        cout << "{ " << parent.vertex << " } ---->  ";
        list<node>::iterator it;

        for (it = lst.begin(); it != lst.end(); ++it)
        {
            cout << it->vertex << ' ';
        }
    }

    void display()
    {
        cout << "\n------------ Adjacency List Representation ------------\n\n";
        for (int i = 0; i < size; i++)
        {
            show_node(adjacency_list[i]);
            cout << "\n";
        }
        cout << "\n------------ End ------------\n";
    }
};

int main()
{
    Graph graph;
    int exit = 0;

    while (exit == 0)
    {
        int ch;
        cout << "Menu :"
             << "\n1. Create"
             << "\n2. Display"
             << "\n3. DFS\n";

        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "\nNumber of node you want to enter: ";
            cin >> n;
            graph.create(n);
            cout << "\n";
            break;
        }
        case 2:
        {
            graph.display();
            break;
        }
        case 3:
        {
            int start;
            cout << "Enter start vertex from 0 -  " << graph.get_size() - 1 << " : ";
            cin >> start;
            cout << "DFS is : ";
            graph.dfs(start);
            cout << "\n";
            break;
        }
        default:
        {
            break;
            exit = 1;
        }
        }
    }
    return 0;
}
