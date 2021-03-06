#ifndef SOL_GRAPH_H
#define SOL_GRAPH_H

#include <utility>
#include <queue>
#include "board.h"

using namespace std;

class Node{

    public:
        int depth;
        Board board;
        pair<int,int> touchedBubble;
        Node *parent;
        vector<Node *> children;

        Node(Node *parent, Board board) : board(std::move(board))
        {
            if(parent != nullptr){
                this->parent = parent;
                this->depth = parent->depth + 1;
            }else{
                this->parent = nullptr;
                this->depth = 0;
            }
        }

        void add_child(Node *child) { children.push_back(child); }

        float getGreedyValue();
};

class Tree{
    public:
        Node *root;

        vector<pair<int,int>> DFS(Board starting_board, int max_moves);
        Node* DFS_helper(Node* current_node, int max_moves, int depth);
        vector<pair<int,int>> BFS(Board starting_board, int max_moves);
        vector<pair<int, int>> greedy(Board starting_board, int max_moves);
        Node* greedy_helper(Node *current_node, int max_moves, int depth);
        vector<pair<int, int>> AStar(Board starting_board, int max_moves);
        vector<pair<int, int>> UniformCost(Board starting_board, int max_moves);

};


#endif