// Shortest Path in Directed Acyclic Graph
// http://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#define INF INT_MAX							// definition of infinite
using namespace std;

class Graph {
private:
	vector<vector<pair<int,int> > > G;      // data structure to store graph
	int vertex_size;						// total no of vertices

public:
	Graph(int vertex_size);
	void addEdge(int head, int tail, int weight);
	void printGraph();
	void shortestPath(int source);
	void topologicalSortUtil(int i, bool* visited, stack<int>* stack);
};

Graph::Graph(int vertex_size) {
	this->vertex_size = vertex_size;
	this->G.resize(vertex_size);
}

void Graph::addEdge(int head, int tail, int weight) {
	G[head].push_back(make_pair(tail, weight));
}

void Graph::printGraph() {
	cout<<"adj list rep of graph.."<<endl;
	for (int i = 0; i < vertex_size; i++) {
		cout<<i<<" -> ";
		for (int j = 0; j < G[i].size(); j++)
			cout<<G[i][j].first<<" ";
		cout<<endl;
	}
}

void Graph::shortestPath(int source) {
	cout<<endl<<"shortest path to all vertices from vertex "<<source<<" is: "<<endl;
	bool *visited = new bool[vertex_size];
	for (int i = 0; i < vertex_size; i++)
		visited[i] = false;
	// make a topological ordered list of vertices
	stack<int> stack;
	topologicalSortUtil(source, visited, &stack);
	
	// initialize distance to all vertices as infinite and distance to source as 0
	int* dist = new int[vertex_size];
	for (int i = 0; i < vertex_size; i++)
		dist[i] = INF;
	dist[source] = 0;

	// scan the adj list of each vertex in the list and calculate shortest path
	vector<pair<int,int> >::iterator v;
	while (!stack.empty()) {
		int u = stack.top();
		stack.pop();
		if (dist[u] != INF)
			for (v = G[u].begin(); v != G[u].end(); v++)
				if (dist[v->first] > dist[u] + v->second)
					dist[v->first] = dist[u] + v->second;
	}
	
	// print the calculated shortest paths
	for (int i = 0; i < vertex_size; i++)
		(dist[i] == INF) ? cout<<"INF " : cout<<dist[i]<<" ";
}

void Graph::topologicalSortUtil(int i, bool* visited, stack<int>* stack) {
	visited[i] = true;
	vector<pair<int,int> >::iterator itr;
	for (itr = G[i].begin(); itr != G[i].end(); itr++)
		if (!visited[itr->first])
			topologicalSortUtil(itr->first, visited, stack);
	stack->push(i);
}

int main() {
	Graph* G = new Graph(6);
	// adding edges
	G->addEdge(0, 1, 5);
    G->addEdge(0, 2, 3);
    G->addEdge(1, 3, 6);
    G->addEdge(1, 2, 2);
    G->addEdge(2, 4, 4);
    G->addEdge(2, 5, 2);
    G->addEdge(2, 3, 7);
    G->addEdge(3, 4, -1);
    G->addEdge(4, 5, -2);
	G->printGraph();

	G->shortestPath(1);
	cout<<endl<<endl;
	return 0;
}