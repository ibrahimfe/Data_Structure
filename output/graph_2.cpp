#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph
{
  int numNodes;
  list<int> *adjList;

public:
  Graph(int numNodes)
  {
    this->numNodes = numNodes;
    adjList = new list<int>[numNodes];
  }

  void addEdge(int node1, int node2)
  {
    adjList[node1].push_back(node2);
    adjList[node2].push_back(node1);
  }
  void printGraph()
  {
    for (int i = 0; i < numNodes; ++i)
    {
      cout << "Node " << i << ": ";
      for (int node : adjList[i])
      {
        cout << node << " ";
      }
      cout << endl;
    }
  }
  bool isPathExists(int startNode, int endNode)
  {
    vector<bool> visited(numNodes, false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
      int currentNode = q.front();
      q.pop();

      if (currentNode == endNode)
        return true;

      for (int adjNode : adjList[currentNode])
      {
        if (!visited[adjNode])
        {
          visited[adjNode] = true;
          q.push(adjNode);
        }
      }
    }

    return false;
  }
};

int main(int argc, char const *argv[])
{
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.printGraph();

  if (graph.isPathExists(0, 4))
  {
    cout << "There is a path between the node 0 and 4" << endl;
  }
  else
  {
    cout << "There is no path between the node" << endl;
  }

  return 0;
}