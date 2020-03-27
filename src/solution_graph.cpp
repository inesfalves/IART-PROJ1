#include "solution_graph.h"

#include <utility>



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

    queue<Node*> queue;
    Node* start = new Node(nullptr, std::move(starting_board));
    this->root = start;

    Node* currentNode, *solutionNode = nullptr;

    queue.push(start);

    bool finished = false;

    while (!queue.empty() && !finished) {
       currentNode = queue.front();
       Board currentBoard = currentNode->board;
       queue.pop();
       vector<pair<int, int>> plays = currentBoard.possiblePlays();

       cout << "Current Board " << endl;
       currentBoard.display();

       cout << "Plays" << endl;
       for(int i = 0; i < plays.size(); i++){
           cout << plays.at(i).first << " " << plays.at(i).second << endl;
       }
       cout << "----------------------------------------------------" << endl;

       for(auto & play : plays){
           Board newBoard = Board(currentBoard.simulatePlayerTouch(play.first, play.second));
           Node* newNode = new Node(currentNode, newBoard);
           currentNode->children.push_back(newNode);
           newNode->touchedBubble = play;
           if(newBoard.isSolution()){
               solutionNode = newNode;
               finished = true;
               break;
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