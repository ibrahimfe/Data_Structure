#include <iostream>
#include <list>

using namespace std;

class Graph {
  int numNodes;
  list<int> *adjList;

public:
  Graph(int numNodes) {
    this->numNodes = numNodes;
    adjList = new list<int>[numNodes];
  }

  void addEdge(int node1, int node2) {
    adjList[node1].push_back(node2);
    adjList[node2].push_back(node1);
  }
  void printGraph() {
    for (int i = 0; i < numNodes; ++i) {
      cout << "Node " << i << ": ";
      for (int node : adjList[i]) {
        cout << node << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, char const *argv[]){
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.printGraph();
  return 0;
}