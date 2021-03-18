#include <iostream>
#include <list>

using namespace std;

class node
{
public:
    int vertex;
    node(int n = NULL)
    {
        vertex = n;
    }
};

class Graph
{
    list<node> *adjacency_list_ptr;
    int size;
    Graph(int n, list<node> adjacency_list[])
    {
        size = n;
        adjacency_list_ptr = adjacency_list;
        for (int i = 0; i < size; i++)
        {
            list<node> curr_list = *(adjacency_list_ptr + i);
            curr_list.push_back(node(i));
        }
    }
    void create_graph()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int temp_vertex;
                list<node> curr_list = *(adjacency_list_ptr + i);
                cout << "Enter Vertex : ";
                cin >> temp_vertex;
                curr_list.push_back(node(temp_vertex));
            }
        }
    }

    void print_node_info(list<node> nlist)
    {
        cout << "Cuurent Node : " << nlist.front().vertex;
        cout << "Adjacent Nodes : ";
    }
};

int main()
{
    /* code */
    return 0;
}
