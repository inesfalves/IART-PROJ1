#include "solution_graph.h"
#include <algorithm>

using namespace std;

vector<pair<int,int>> Tree::DFS(Board starting_board, int max_moves){
    this->root = new Node(NULL, starting_board);
    vector<pair<int,int>> possible_plays = this->root->board.possiblePlays();
    vector<pair<int,int>> solution;
    for(size_t i=0; i<possible_plays.size(); i++){
        Node* final_node = DFS_helper(this->root, max_moves, 1);
        if(final_node != NULL){
            while(final_node->parent != NULL){
                solution.push_back(final_node->touchedBubble);
                final_node = final_node->parent;
            }
            reverse(solution.begin(), solution.end());
            return solution;
        }
    }
    return solution;
}

Node* Tree::DFS_helper(Node* current_node, int max_moves, int depth){
    if(current_node->board.isSolution){
        return current_node;
    }
    else if(depth>=max_moves){
        return NULL;
    }
    vector<pair<int,int>> possible_plays = this->root->board.possiblePlays();
    for(size_t i=0; i<possible_plays.size(); i++){
        current_node->board.simulatePlayerTouch(possible_plays.at(i).first, possible_plays.at(i).second);
        Node* new_node = new Node(current_node, current_node->board.getSimulatedBoard());
        Node* final_node = DFS_helper(new_node, max_moves, depth++);
        if(final_node != NULL){
            return final_node;
        }
    }
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
