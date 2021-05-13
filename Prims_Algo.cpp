#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class node
{
public:
	int vertex;
	list< pair<node, int> > adjacent;
};

class Graph
{
public:
	node node_list[20];
	int size;

	int get_size()
	{
		return size;
	}

	node get_node(int vertex)
	{
		return node_list[vertex];
	}

	void create(int n)
	{
		size = n;
		for (int i = 0; i < size; i++)
		{
			node_list[i].vertex = i;
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
			show_node(node_list[i]);
			// Number of nodes we can enter
			num = (size - node_list[i].adjacent.size()) - 1;

			while (num > 0)
			{
				char ch;
				char dh;

				int vertex;
				int dist;
				cin >> ch >> dh;
				// Convert input to int by subtracting 48 ascii value of 0
				vertex = ch - '0';
				if (vertex >= size)
				{
					break;
				}

				dist = dh - '0';
				// If in our integer range means its valid user input or else we need to break
				if (vertex < size)
				{
					add_adjacent(i, vertex, dist);
					add_adjacent(vertex, i, dist);
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

	void add_adjacent(int i, int j, int dist)
	{
		node a = node_list[i];
		node b = node_list[j];

		// Same node cant be added
		if (i == j)
		{
			return;
		}
		// if already added, ignore
		list< pair<node, int> >::iterator it;

		for (it = a.adjacent.begin(); it != a.adjacent.end(); ++it)
		{
			if (it->first.vertex == b.vertex)
			{
				return;
			}
		}
		node_list[i].adjacent.push_back(make_pair(b,dist));
		return;
	}

	void show_node(node parent)
	{
		list< pair<node, int> > lst = parent.adjacent;
		cout << "{ " << parent.vertex << " } ---->  \n";
		list< pair<node, int> >::iterator it;

		for (it = lst.begin(); it != lst.end(); ++it)
		{	
			cout << it->first.vertex << " - " << it->second << "\n";
		}
	}

	void display()
	{
		cout << "\n------------ List Representation ------------\n\n";
		for (int i = 0; i < size; i++)
		{
			show_node(node_list[i]);
			cout << "\n";
		}
		cout << "\n------------ End ------------\n";
	}
};

class PrimsAlgo
{
private:
	Graph graph;
	int count;
	node main_set[20];
	bool in_set[20];
	
public:
	PrimsAlgo(Graph g) {
		graph = g;
		for (int i = 0; i <= 20; i++)
		{
			in_set[i] = false;
		}
	}

	node next_min() {
		node min_node;
		int min_node_dist = 999;
		min_node.vertex = 20;

		for (int i = 0; i <= count; i++)
		{
			list< pair<node, int> > lst = main_set[i].adjacent;
			list< pair<node, int> >::iterator it;

			for (it = lst.begin(); it != lst.end(); ++it)
			{	
				int v = it->first.vertex;
				if(!in_set[v] && it->second < min_node_dist) {
					min_node = graph.get_node(it->first.vertex);
					min_node_dist = it->second;
				}
			}
		}
		return min_node;
	}

	void run(node n){
		count = 0;
		main_set[count] = n;
		in_set[n.vertex] = true;
		for (int i = 0; i < graph.get_size() - 1; i++)
		{
			node next = next_min();
			in_set[next.vertex] = true;
			main_set[++count] = next;
		}
	}

	void display() {
		cout << "\n------------ Main Set ------------\n\n";
		for (int i = 0; i <= count; i++)
		{
			cout << main_set[i].vertex <<"\n";
		}
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
			 << "\n3. Prims\n";


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
			PrimsAlgo alg(graph);
			alg.run(graph.get_node(0));
			alg.display();
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
