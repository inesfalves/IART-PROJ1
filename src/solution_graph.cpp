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

    queue<Node*> queue;
    Node* root = new Node(nullptr, starting_board);
    this->root = root;

    Node* currentNode, *solutionNode;

    queue.push(root);

    bool finished = false;

    while (!queue.empty() && !finished) {
       currentNode = queue.front();
       Board currentBoard = currentNode->board;
       queue.pop();
       vector<pair<int, int>> plays = currentBoard.possiblePlays();
       for(size_t i = 0; i < plays.size(); i++){
           Board newBoard = Board(currentBoard.simulatePlayerTouch(plays.at(i).first, plays.at(i).second));
           Node* newNode = new Node(currentNode, newBoard);
           currentNode->children.push_back(newNode);
           newNode->touchedBubble = plays.at(i);
           if(newBoard.isSolution()){
               solutionNode = newNode;
               finished = true;
           } else{
               queue.push(newNode);
           }
       }
    }


    bool gotMoves = false;
    while(!gotMoves){
        if(solutionNode->parent != nullptr){
            moves.push_back(solutionNode->touchedBubble);
            solutionNode = solutionNode->parent;
        } else{
            gotMoves = true;
        }
    }


    return moves;
}