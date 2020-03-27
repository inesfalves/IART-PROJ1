#include "solution_graph.h"

/* Vertex */

Vertex::Vertex(Board vBoard): vertexBoard(vBoard){}

void Vertex::addEdge(int bubble_x, int bubble_y, Vertex* result){
    this->adj.push_back(Edge(bubble_x, bubble_y, result));
}

/* Edge */

Edge::Edge(int x, int y, Vertex* r): bubble_x(x), bubble_y(y), dest(r){}

/* Graph */

void SolGraph::addVertex(Vertex* in){
    this->vertexSet.push_back(in);
}

vector<pair<int,int>> SolGraph::DFS(Board starting_board){
    Vertex starting_vertex = Vertex(starting_board);
    this->addVertex(&starting_vertex);
    vector<pair<int,int>> solution;
    pair<int,int> nextBubble(0,0);
    while(true){
        
    }
}