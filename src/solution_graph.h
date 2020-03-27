#ifndef SOL_GRAPH_H
#define SOL_GRAPH_H

#include <utility>   
#include "board.h"

using namespace std;

class Edge;

class Vertex {
    public:
        Board vertexBoard;
        vector<Edge> adj;
        Vertex *path = NULL;

        Vertex(Board vBoard);
        void addEdge(int bubble_x, int bubble_y, Vertex* result);    

};

class Edge {
    public:
        Vertex *dest;
        int bubble_x, bubble_y;

        Edge(int x, int y, Vertex* r); 
};

class SolGraph {
    public:
        vector<Vertex*> vertexSet;

        void addVertex(Vertex *in);
        vector<pair<int,int>> DFS(Board starting_board);
};

#endif