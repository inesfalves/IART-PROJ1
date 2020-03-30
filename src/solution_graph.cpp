#include "solution_graph.h"
#include <algorithm>

#include <utility>

float Node::getGreedyValue(){
    if(this->board.getBoardTotalScore() == 0) return 0;
    else if(this->board.getRedPercentage() == 0) return 4000;
    else return this->board.getBoardTotalScore() / this->board.getRedPercentage();
}

bool compareNodesGreedy(Node *N1, Node *N2){
    return N1->getGreedyValue() < N2->getGreedyValue();
}

vector<pair<int, int>> Tree::DFS(Board starting_board, int max_moves)
{
    this->root = new Node(nullptr, std::move(starting_board));
    vector<pair<int, int>> possible_plays = this->root->board.possiblePlays();
    vector<pair<int, int>> solution;

    for (size_t i = 0; i < possible_plays.size(); i++)
    {
        Node *final_node = DFS_helper(this->root, max_moves, 0);
        if (final_node != nullptr)
        {
            while (final_node->parent != nullptr)
            {
                solution.push_back(final_node->touchedBubble);
                final_node = final_node->parent;
            }
            reverse(solution.begin(), solution.end());
            return solution;
        }
    }
    return solution;
}

Node *Tree::DFS_helper(Node *current_node, int max_moves, int depth)
{
    if (current_node->board.isSolution())
    { 
        return current_node;
    }
    else if (depth >= max_moves)
    {
        return nullptr;
    }
    vector<pair<int, int>> possible_plays = current_node->board.possiblePlays();
    
    for (size_t i = 0; i < possible_plays.size(); i++)
    {   
        pair<int,int> possible_play = possible_plays.at(i);
        current_node->board.simulatePlayerTouch(possible_play.first, possible_play.second);
        Node *new_node = new Node(current_node, current_node->board.getSimulatedBoard());
        new_node->touchedBubble = possible_play;
        new_node->depth = depth + 1;
        Node *final_node = DFS_helper(new_node, max_moves, new_node->depth);
        if (final_node != nullptr)
        {
            return final_node;
        }
    }
    return nullptr;
}

vector<pair<int, int>> Tree::BFS(Board starting_board, int max_moves)
{
    vector<pair<int, int>> moves;
    int max_depth = max_moves - 1;

    queue<Node *> queue;
    Node *start = new Node(nullptr, std::move(starting_board));
    this->root = start;

    Node *currentNode, *solutionNode = nullptr;

    queue.push(start);

    bool finished = false;

    while (!queue.empty() && !finished) {
       currentNode = queue.front();
       Board currentBoard = currentNode->board;
       queue.pop();
       vector<pair<int, int>> plays = currentBoard.possiblePlays();

       if(currentNode->depth > max_depth){
           pair<int,int> impossible(-1,-1);
           moves.push_back(impossible);
           return moves;
       }

/*
        cout << "Parent Board " << endl;
        if(currentNode->parent != nullptr)
            currentNode->parent->board.display();
        cout << "Current Board " << endl;
        currentBoard.display();


       cout << "Plays" << endl;
       for(auto & play : plays){
           cout << play.first << " " << play.second << endl;
       }
       cout << "----------------------------------------------------" << endl;*/

        for (auto &play : plays)
        {
            Board newBoard = Board(currentBoard.simulatePlayerTouch(play.first, play.second));
            Node *newNode = new Node(currentNode, newBoard);
            currentNode->add_child(newNode);
            newNode->touchedBubble = play;
            if (newBoard.isSolution())
            {
                solutionNode = newNode;
                finished = true;
                break;
            }
            else
            {
                queue.push(newNode);
            }
        }
    }

    bool gotMoves = false;
    while (!gotMoves)
    {
        if (solutionNode->parent != nullptr)
        {
            moves.push_back(solutionNode->touchedBubble);
            solutionNode = solutionNode->parent;
        }
        else
        {
            gotMoves = true;
        }
    }

    reverse(moves.begin(), moves.end());

    return moves;
}

vector<pair<int, int>> Tree::greedy(Board starting_board, int max_moves){
    this->root = new Node(nullptr, std::move(starting_board));
    vector<pair<int, int>> possible_plays = this->root->board.possiblePlays();
    vector<pair<int, int>> solution;

    vector<Node *> nodes;

    for (size_t i = 0; i < possible_plays.size(); i++)
    {   
        pair<int,int> possible_play = possible_plays.at(i);
        this->root->board.simulatePlayerTouch(possible_play.first, possible_play.second);
        Node *new_node = new Node(this->root, this->root->board.getSimulatedBoard());
        new_node->touchedBubble = possible_play;
        new_node->depth = 1;
        nodes.push_back(new_node);
    }

    sort(nodes.begin(), nodes.end(), compareNodesGreedy);

    for (size_t i = 0; i < nodes.size(); i++){
        Node *final_node = greedy_helper(this->root, max_moves, 0);
        if (final_node != nullptr)
        {
            while (final_node->parent != nullptr)
            {
                solution.push_back(final_node->touchedBubble);
                final_node = final_node->parent;
            }
            reverse(solution.begin(), solution.end());
            return solution;
        }
    }

    return solution;
}

Node *Tree::greedy_helper(Node *current_node, int max_moves, int depth)
{
    if (current_node->board.isSolution())
    {
        return current_node;
    }
    else if (depth >= max_moves)
    {
        return nullptr;
    }
    vector<pair<int, int>> possible_plays = current_node->board.possiblePlays();
    vector<Node *> nodes;
    for (size_t i = 0; i < possible_plays.size(); i++)
    {   
        pair<int,int> possible_play = possible_plays.at(i);
        current_node->board.simulatePlayerTouch(possible_play.first, possible_play.second);
        Node *new_node = new Node(current_node, current_node->board.getSimulatedBoard());
        new_node->touchedBubble = possible_play;
        new_node->depth = depth + 1;
        nodes.push_back(new_node);
    }

    sort(nodes.begin(), nodes.end(), compareNodesGreedy);

    for (size_t i = 0; i < nodes.size(); i++){
        Node *final_node = greedy_helper(nodes.at(i), max_moves, nodes.at(i)->depth);
        if (final_node != nullptr)
        {
            return final_node;
        }
    }
    
    return nullptr;
}

bool compareNodesAStar(Node *N1, Node *N2){

    return (N1->getGreedyValue() + N1->board.cost + N1->depth) < (N2->getGreedyValue() + N2->board.cost + N2->depth);
}

queue<Node *> sortQueue(queue<Node *> q){

    vector<Node *> helperVector;
    queue<Node *> sortedQueue;

    while(!q.empty()){
        helperVector.push_back(q.front());
        q.pop();
    }

    sort(helperVector.begin(), helperVector.end(), compareNodesAStar);

    cout << "Pre" << endl;
    for(auto i : helperVector){
        float val = (float)i->board.costCalculation() + (float)i->depth+ i->getGreedyValue();
        cout << val << " ";
        sortedQueue.push(i);
    }
    cout << "Pos" << endl;

    return sortedQueue;
}


vector<pair<int, int>> Tree::AStar(Board starting_board, int max_moves)
{
    vector<pair<int, int>> moves;
    int max_depth = max_moves - 1;

    queue<Node *> queue;
    Node *start = new Node(nullptr, std::move(starting_board));
    this->root = start;

    Node *currentNode, *solutionNode = nullptr;

    queue.push(start);

    bool finished = false;

    while (!queue.empty() && !finished) {
        queue = sortQueue(queue);
        currentNode = queue.front();
        Board currentBoard = currentNode->board;
        queue.pop();
        vector<pair<int, int>> plays = currentBoard.possiblePlays();

        if(currentNode->depth > max_depth){
            cout << queue.size() << " ";
            continue;
        }

        for (auto &play : plays)
        {
            Board newBoard = Board(currentBoard.simulatePlayerTouch(play.first, play.second));
            Node *newNode = new Node(currentNode, newBoard);
            currentNode->add_child(newNode);
            newNode->touchedBubble = play;
            if (newBoard.isSolution())
            {
                solutionNode = newNode;
                finished = true;
                break;
            }
            else
            {
                queue.push(newNode);
            }
        }
    }

    if(solutionNode == nullptr){
        pair<int,int> impossible(-1,-1);
        moves.push_back(impossible);
        return moves;
    }

    bool gotMoves = false;
    while (!gotMoves)
    {
        if (solutionNode->parent != nullptr)
        {
            moves.push_back(solutionNode->touchedBubble);
            solutionNode = solutionNode->parent;
        }
        else
        {
            gotMoves = true;
        }
    }

    reverse(moves.begin(), moves.end());

    return moves;
}
