#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Define a structure for a graph node (adjacency list)
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;
    GraphNode(int value) : data(value) {}
};

// Define a class for a graph
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

// Function to perform DFS traversal of a graph
void dfsTraversal(GraphNode* startNode, unordered_map<GraphNode*, bool>& visited) {
    if (startNode == nullptr) {
        return;
    }

    cout << startNode->data << " ";
    visited[startNode] = true;

    for (const GraphNode* neighbor : startNode->neighbors) {
        if (!visited[neighbor]) {
            dfsTraversal(const_cast<GraphNode*>(neighbor), visited);
        }
    }
}

int main() {
    Graph graph;

    // Add nodes to the graph
    for (int i = 1; i <= 7; i++) {
        graph.addNode(i);
    }

    // Add edges to the graph
    graph.addEdge(graph.nodes[0], graph.nodes[1]);
    graph.addEdge(graph.nodes[0], graph.nodes[2]);
    graph.addEdge(graph.nodes[1], graph.nodes[3]);
    graph.addEdge(graph.nodes[1], graph.nodes[4]);
    graph.addEdge(graph.nodes[2], graph.nodes[5]);
    graph.addEdge(graph.nodes[2], graph.nodes[6]);

    unordered_map<GraphNode*, bool> visited;

    cout << "DFS Traversal starting from Node 1: ";
    dfsTraversal(graph.nodes[0], visited);
    cout << endl;

    return 0;
}
