#include "solution_graph.h"



vector<pair<int,int>> Tree::DFS(Board starting_board){
    /*Node starting_vertex = Vertex(starting_board);
    this->addVertex(&starting_vertex);
    vector<pair<int,int>> solution;
    pair<int,int> nextBubble(0,0);
    while(true){
        
    }*/
}

vector<pair<int, int>> Tree::BFS(Board starting_board) {

    vector<pair<int, int>> moves;

    Queue queue;
    Node* root(nullptr, starting_board);
    this->root = root;

    Node* currentNode;

    queue.insert(root);

    while (!queue.isEmpty()) {
       currentNode = queue.front();
       queue.pop_front();
    }


    return moves;
}
