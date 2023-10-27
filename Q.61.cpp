#include <iostream>
#include <vector>
using namespace std;

// Define a structure for a graph node (adjacency list)
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;
    GraphNode(int value) : data(value) {}
};

// Define a class for an undirected graph
class Graph {
public:
    vector<GraphNode*> nodes;

    // Function to add a new node to the graph
    void addNode(int value) {
        nodes.push_back(new GraphNode(value));
    }

    // Function to add an undirected edge between two nodes
    void addEdge(GraphNode* node1, GraphNode* node2) {
        node1->neighbors.push_back(node2);
        node2->neighbors.push_back(node1);
    }
};

// Function to display the graph
void displayGraph(const Graph& graph) {
    for (const GraphNode* node : graph.nodes) {
        cout << "Node " << node->data << " is connected to: ";
        for (const GraphNode* neighbor : node->neighbors) {
            cout << neighbor->data << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph graph;

    // Add nodes to the graph
    for (int i = 1; i <= 5; i++) {
        graph.addNode(i);
    }

    // Add edges to the graph
    graph.addEdge(graph.nodes[0], graph.nodes[1]);
    graph.addEdge(graph.nodes[0], graph.nodes[2]);
    graph.addEdge(graph.nodes[1], graph.nodes[3]);
    graph.addEdge(graph.nodes[2], graph.nodes[4]);

    // Display the graph
    displayGraph(graph);

    return 0;
}
