#include <iostream>
#include <queue>
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

// Function to perform BFS traversal of a graph
void bfsTraversal(Graph& graph, GraphNode* startNode) {
    if (startNode == nullptr) {
        return;
    }

    unordered_map<GraphNode*, bool> visited;
    queue<GraphNode*> nodeQueue;

    nodeQueue.push(startNode);
    visited[startNode] = true;

    while (!nodeQueue.empty()) {
        GraphNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currentNode->data << " ";

        for (const GraphNode* neighbor : currentNode->neighbors) {
            if (!visited[neighbor]) {
                nodeQueue.push(const_cast<GraphNode*>(neighbor));
                visited[neighbor] = true;
            }
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

    cout << "BFS Traversal starting from Node 1: ";
    bfsTraversal(graph, graph.nodes[0]);
    cout << endl;

    return 0;
}
#include <iostream>
#include <queue>
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

// Function to perform BFS traversal of a graph
void bfsTraversal(Graph& graph, GraphNode* startNode) {
    if (startNode == nullptr) {
        return;
    }

    unordered_map<GraphNode*, bool> visited;
    queue<GraphNode*> nodeQueue;

    nodeQueue.push(startNode);
    visited[startNode] = true;

    while (!nodeQueue.empty()) {
        GraphNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currentNode->data << " ";

        for (const GraphNode* neighbor : currentNode->neighbors) {
            if (!visited[neighbor]) {
                nodeQueue.push(const_cast<GraphNode*>(neighbor));
                visited[neighbor] = true;
            }
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

    cout << "BFS Traversal starting from Node 1: ";
    bfsTraversal(graph, graph.nodes[0]);
    cout << endl;

    return 0;
}
