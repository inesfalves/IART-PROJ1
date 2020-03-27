#ifndef SOL_GRAPH_H
#define SOL_GRAPH_H

#include <utility>   
#include "board.h"

using namespace std;

class Node{

    public:
        int depth;
        Board board;
        pair<int,int> touchedBubble;
        Node *parent;
        vector<Node *> children;

        Node(Node *parent) : parent(parent)
        {
        }

        void add_child(Node *child) { children.push_back(child); }

        vector<pair<int,int>> DFS(Board starting_board);
        vector<pair<int,int>> BFS(Board starting_board);
};


#endif