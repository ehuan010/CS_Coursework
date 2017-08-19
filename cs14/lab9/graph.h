#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Edge;

//Node
class Node {
public:
 Node(const string& elem):payload(elem),visited(false){ 
    adjacents = new vector<Edge* >();
  };
  ~Node() {};
  void   setVisited(bool v)        {visited = v;};
  bool    isVisited()              {return visited;};
  void   addEdge(Edge* e)    {
    adjacents->push_back(e);
  };
  int    degree()  const           {return adjacents->size();};
  string getPayload() const        {return payload;}
  vector<string>*  neighbors();
  vector<Edge* >*  adjacentsList()     {return adjacents;};
private:
  string        payload;
  bool          visited;
  vector<Edge* >* adjacents;
};


//Edge
class Edge {
public:
  Edge(Node* n, double w):node(n),weight(w){};
  ~Edge() {};
  void      setWeight(double w)  {weight=w;};
  Node*     getNode()   const    {return node;};
  double    getWeight() const    {return weight;};
private:
  Node*  node;
  double weight;
  friend class Node;
};


//Graph
class Graph {
public:
  Graph(bool directed):directed(directed){
    graph = new map<int,Node*>();
  };

  ~Graph() {
    delete graph;
   };
  
  void addNode(int nodeid,string payload);
  void addEdge(int nid1 , int nid2, double w);
  void printGraph();
  int  maxDegree();
  vector<string>* reachable(int nid);
  
private:
  map<int,Node*>* graph;
  bool directed;
};
