#include <iostream>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include "graph.h"

using namespace std;
template<class T>
struct less_second
: std::binary_function<T,T,bool>
{
   inline bool operator()(const T& lhs, const T& rhs)
   {
      return lhs.second < rhs.second;
   }
};


Graph::Graph( const int& nodes, const bool& directed )
{
	nNodes = nodes;
    nEdges = 0;
    isDirected = directed;
}

Graph::~Graph()
{}

edge_it Graph::getEdge( const int& s, const int&t )
{
	std::pair<int,int> p( s, t );
    edge_it mit = edge_map.find( p );

    return mit;
}

// Check if edge exists between end nodes
bool Graph::edge( const int& s, const int& t)
{
    return getEdge( s, t ) != edge_map.end();
}

// Add an edge: map node pair with weight
void Graph::insert( const int& s, const int& t, const double& weight )
{
	std::pair<int,int> p1( s, t );
    std::pair<int,int> p2( t, s );
    edge_map[ p1 ] = weight;

    if ( !isDirected )
    {
    	edge_map[ p2 ] = weight;
    }

    nEdges++;
}

// Remove selected edge - remove both directions
// if graph is not directed
void Graph::remove( const int& s, const int& t )
{
	std::pair<int,int> p1( s, t );
    std::map< std::pair<int,int>, double>::iterator mit = edge_map.find( p1 );
    edge_map.erase( mit );

    if ( !isDirected )
    {
        std::pair<int,int> p2( t, s );
        mit = edge_map.find( p2 );
        edge_map.erase( mit );
    }

    nEdges--;
}

// Print the network topology
void Graph::show() const
{
	edge_it mit = edge_map.begin();

    for ( ; mit != edge_map.end(); ++ mit )
    {
    	std::pair<int,int> p = (*mit).first;
        std::cout << p.first  << " " <<
                   p.second << " " <<
                   (*mit).second << std::endl;
    }
}

// Return true if graph is directed; false otherwose
bool Graph::directed() const
{
    return isDirected;
}

// Return number of network nodes
int Graph::V() const
{
    return nNodes;
}

// Return number of edges
int Graph::E() const
{
	return nEdges;
}


//This function returns the Minimum Spanning Tree (MST) of this graph (Kruskal)
std::vector<data_t> Graph::MST_Kruskal()
{
    int i, number;
    int cicles[this->V()];
    std::vector<data_t> mst;
    mst.clear();
    std::vector<data_t> edges = sorted_edges();

    for( i=0; i < this->V(); i++) cicles[ i ] = i;

    while( (int) mst.size() < ( this->V() - 1) && edges.size() )
    {
        data_t dt = edges[ 0 ];
        std::pair<int,int> p = dt.first;
        int vi = p.first;
        int vj = p.second;

        if( cicles[ vi ] != cicles[vj] )
        {
            number = cicles[ vj ];
            for( i=0; i < this->V(); i++ )
            {
               if( cicles[ i ] == number )
                  {
                     cicles[ i ] = cicles[ vi ];
                  }
            }

            mst.push_back( dt );
        }
        edges.erase( edges.begin(), edges.begin() + 1 );
    }

    return mst;
}


/*
 * This function uses std::sort to sort the weighted edges of the graph
 * into nondecreasing order by weight
 */

std::vector<data_t> Graph::sorted_edges()
{
	std::vector< data_t > vec(edge_map.begin(), edge_map.end());

	std::sort(vec.begin(), vec.end(), less_second<data_t>());

	return vec;
}




	// Depth first search of this graph
	int* Graph::dfs(int v) {
	}

    /*
     * This function returns a topological ordering of a Directed Graph
     * topological sort works only on directed acyclic graphs (DAG)
     */
    std::vector<data_t> Graph::topological_sort()
    {

    }

    /*
     * This function returns the number of strongly connected components in this graph
     */

    int Graph::connected_components()
    {

    }


    /*
     * This function checks if the current graph contains a cycle
     */

    bool Graph::containsCycle()
    {

    }


    /*
     * This function returns the maximum MST of all subgraphs of size n-1
     * where n is the number of vertices in this graph
     */

    std::vector<data_t> Graph::maxSubMST() {

    }



    std::pair<int,int> Graph::getMinEdge(int first)
    {
    	std::pair<int,int> p;
    	p.first = -1;
    	p.second = -1;
    	double min_so_far = 99999.9;
    	double min_check = -1.0; //weight of current edge
    	for(int i = 0; i < this->V(); i++)
    	{
    		//if edge exists, then get weight
    		if(edge(i,first))//if(edge(first,i))
    		{
    			min_check = getEdge(i,first)->second;
    			//cout << "edge " << first << "-" << i << " exists. min_check = " << min_check << endl;
    			if(min_check < min_so_far)
    			{
    				min_so_far = min_check;
    				p.first = i;
    				p.second = first;
    			}
    		}
    		else
    		{
    			min_check = -1.0;
    			//cout << "edge " << first << "-" << i << " does not exist. min_check = " << min_check << endl;
    		}
    	}

    	return p;
    }

    void Graph::getParents(int c,std::vector<int>& v)
    {
    	bool already = false;
    	for(map< pair<int,int> , double >::iterator it = edge_map.begin(); it != edge_map.end(); it++)
    	{
    		if(it->first.second == c)
    		{
    			for(int i = 0; i < v.size(); i++)
    			{
    				if(v[i] == it->first.first)
    					already = true;
    			}

    			if(already)
    				break;
    			else
    				v.push_back(it->first.first);
    		}

    	}
    }

    bool Graph::pathExists(int x, int y)
    {
    	std::vector<int> parents;
    	getParents(y,parents);

    	bool first = false;
    	bool second = false;

    	for(int i = 0; i < parents.size(); i++)
    	{
    	    getParents(parents[i],parents);
    	}

    	for(int i = 0; i < parents.size(); i++)
    	{
    		if(parents[i] == x)
    		{
    			//cout << "path exists" << endl;
    			return true;
    		}
    	}
    	//cout << "path DOES NOT exist" << endl;
    	return false;

    }

    void Graph::dijkstra(int d)
    {
    	std::vector<int> parents;
    	getParents(d,parents);

       	for(int i = 0; i < parents.size(); i++)
    	{
    		getParents(parents[i],parents);
    	}
    }


    double Graph::minParentPath(int x)
    {
    	std::vector<int> parents;
    	getParents(x,parents);
        int i, j;
        double parent1, parent2, min_parent;

    	if(parents.size() == 1)
    	{
    		min_parent = parents[0];
    		return min_parent;
    	}

       for( i = 0, j = 1; j < parents.size(); j++, i++)
       {
    	   parent1 = getEdge(parents[i],x)->second;
    	   parent2 = getEdge(parents[j],x)->second;

    	   if(parent1 <= parent2)
    		   min_parent = parent1;
    	   else
    		   min_parent = parent2;
       }

	  return min_parent;

    }

    double Graph::getWeight(int x, int y)
    {
    	std::pair<int,int> p;
    	p.first = x;
    	p.second = y;
    	for( std::map< std::pair<int,int>, double >::iterator it = edge_map.begin(); it != edge_map.end(); it++)
    	{
    		if(it->first == p)
    			return it->second;
    	}
    	return -1;
    }

