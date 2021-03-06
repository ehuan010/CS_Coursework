#include "graph.h"


 vector<string>* Node::neighbors() {
   vector<string>* vec = new vector<string>();
   vector<Edge*>::iterator it;
   for(it=adjacents->begin();it!=adjacents->end();it++) {
     vec->push_back((*it)->getNode()->getPayload());
   }
   return vec;
 }


 void Graph::addNode(string name) {
    Node* node = new Node(name);
    graph->insert(pair<string,Node*>(name,node));
 }

 void Graph::addEdge(string k1, string k2, double w=1.0) {
   map<string,Node* >::iterator it1,it2;
   it1 = graph->find(k1);
   it2 = graph->find(k2);

   //Check both nodes exists using the map
   if (it1 != graph->end() && it2 != graph->end()) {
      Node* n1 = (*it1).second;
      Node* n2 = (*it2).second;
      //Create the edge and add it to the adjacents
      Edge* e = new Edge(n2,w);
      n1->addEdge(e);
      //Undirected graph: we add the reverse or back edge
      if (!directed) {
	Edge* be = new Edge(n1,w);
	n2->addEdge(be);
      }
   }
 }


void Graph::printGraph() {
   //Iterate each node
  map<string,Node* >::iterator it;
  for (it=graph->begin(); it != graph->end();it++) {
    Node* n = (*it).second;
    cout << n->getPayload() << "[";
    
    //Iterate the neighboors
    vector<string>* neigh  = n->neighbors(); 
    vector<string>::iterator itn;
    for(itn=neigh->begin();itn!=neigh->end();itn++) {
       cout << (*itn) << " ";
    }
    cout << "]" << endl;
  }
}

vector<string>* Graph::reachable(string nid) {
  
  vector<string>* vec = new vector<string>();
 
 //Check the initial node exists
  map<string,Node* >::iterator it;
  it = graph->find(nid);
	if(it == graph->end()) return vec;
  //Add the initial node
  Node* n = (*it).second;
  queue<Node*> toVisit;
  toVisit.push(n);  
  vec->push_back(n->getPayload());
  
  //Start the BFS
  while (!toVisit.empty()) {
    
    //Visit each neighbor
    Node* curr = toVisit.front();
    toVisit.pop();
    int sz = curr->degree();
    int i = 0;
    while(sz != 0){
		Edge* e = (curr->adjacentsList()->at(i));
		Node* neigh = e->getNode();
		
		if(!neigh->isVisited())
		{
			neigh->setVisited(true);
			vec->push_back(neigh->getPayload());
			toVisit.push(neigh);
		}
		sz--;
		i++;
    }
    
  }
  return vec;
}

bool Graph::IsThereTripletClique()
{
  
}


int main() {
  cout << "Graph Example 2.0\n";
  Graph g(true);
  
  g.addNode("a");
  g.addNode("b");
  g.addNode("c");
  g.addNode("d");
  g.addNode("e");

  g.addEdge("a","b",10);
  g.addEdge("b","c",5);
  g.addEdge("c","d",8);
  g.addEdge("c","e",9);
  g.addEdge("e","a",11);


  g.printGraph();

}


