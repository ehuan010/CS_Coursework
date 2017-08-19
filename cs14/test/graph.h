
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <vector>

// data_t represents an edge of the graph
typedef std::pair< std::pair<int,int>, double> data_t;

//edge_it is an iterator for the edge map
typedef std::map< std::pair<int,int>, double>::const_iterator edge_it;

class Graph
{

    public:
    Graph( const int& nodes, const bool& directed );
    ~Graph();

    int V() const;
    int E() const;
    bool directed() const;
    void insert( const int& s, const int& t, const double& weight );
    void remove( const int& s, const int& t );
    bool edge( const int& s, const int& t);
    edge_it getEdge( const int& s, const int& t);
    void show() const;
    std::vector<data_t> sorted_edges();
    std::vector<data_t> topological_sort();
    int connected_components();
    bool containsCycle();
    std::vector<data_t> maxSubMST();
    int* dfs(int v);
    std::vector<data_t> MST_Kruskal();

    std::pair<int,int> getMinEdge(int first);
    void getParents(int c,std::vector<int>& v);
    void dijkstra(int d);
    bool pathExists(int x, int y);
    double minParentPath(int x);
    double getWeight(int x, int y);

	private:
    int nNodes;
    int nEdges;
    bool isDirected;

    //this map contains the edges of the graph
    std::map< std::pair<int,int>, double > edge_map;

};

#endif /* GRAPH_H_ */
