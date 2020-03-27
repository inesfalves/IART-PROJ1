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
    Node* root = new Node(nullptr, starting_board);
    this->root = root;

    Node* currentNode, *solutionNode;

    queue.push_back(root);

    bool finished = false;

    while (!queue.isEmpty() && !finished) {
       currentNode = queue.front();
       currentBoard = currentNode->board;
       queue.pop_front();
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
               queue.push_back(newNode);
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
