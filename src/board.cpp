#include <iostream>
#include <vector>
#include "algorithm"
#include "iterator"
#include "board.h"

using namespace std;

Board::Board() = default;

Board::Board(vector<vector<int>> b)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            this->board.at(i).at(j) = b.at(i).at(j);
            this->oldBoard.at(i).at(j) = b.at(i).at(j);
            this->simulatedBoard.at(i).at(j) = b.at(i).at(j);
        }
    }
}

void Board::display()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << " " << this->board.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<TinyBubble> Board::getTinyBubbles() const{
    return tiny_bubbles;
}

vector<TinyBubble> Board::getBurstingBubbles() const{
    return bursting_bubbles;
}

void Board::setTinyBubbles(vector<TinyBubble> tiny_bubbles){
    this->tiny_bubbles = tiny_bubbles;
}

void Board::setBurstingBubbles(vector<TinyBubble> bursting_bubbles){
    this->bursting_bubbles = bursting_bubbles;
}


vector<vector<int>> Board::getBoard() const{
    return board;
}

vector<vector<int>> Board::getSimulatedBoard() const{
    return simulatedBoard;
}

vector<vector<int>> Board::getOldBoard() const{
    return oldBoard;
}

void Board::setBoard(vector<vector<int>> board){
    this->board = board;
}

void Board::setSimulatedBoard(vector<vector<int>> simulatedBoard){
    this->simulatedBoard = simulatedBoard;
}

void Board::setOldBoard(vector<vector<int>> oldBoard){
    this->oldBoard = oldBoard;
}

void Board::burstBubble(int x, int y, bool simulation)
{
    TinyBubble tiny_bubble1 = TinyBubble('L', x, y);
    TinyBubble tiny_bubble2 = TinyBubble('R', x, y);
    TinyBubble tiny_bubble3 = TinyBubble('U', x, y);
    TinyBubble tiny_bubble4 = TinyBubble('D', x, y);

    this->tiny_bubbles.push_back(tiny_bubble1);
    this->tiny_bubbles.push_back(tiny_bubble2);
    this->tiny_bubbles.push_back(tiny_bubble3);
    this->tiny_bubbles.push_back(tiny_bubble4);

    if (simulation)
    {
        this->simulatedBoard.at(y).at(x) = 0;
    }
    else
    {
        this->board.at(y).at(x) = 0;
    }
}

int Board::touchBubble(int x, int y, bool simulation)
{
    if (x < 0 || y < 0 || x >= 5 || y >= 6)
    {
        return -1;
    }

    if (simulation)
    {

        if (this->simulatedBoard.at(y).at(x) == 1)
        {
            this->burstBubble(x, y, simulation);
        }
        else if (this->simulatedBoard.at(y).at(x) > 1)
        {
            this->simulatedBoard.at(y).at(x)--;
        }
    }
    else
    {
        if (this->board.at(y).at(x) == 1)
        {
            this->burstBubble(x, y, simulation);
        }
        else if (this->board.at(y).at(x) > 1)
        {
            this->board.at(y).at(x)--;
        }
    }

    return 0;
}

void Board::stepTinyBubbles(bool simulation)
{
    sort(tiny_bubbles.begin(), tiny_bubbles.end());
    this->bursting_bubbles = this->tiny_bubbles;
    this->tiny_bubbles.clear();

    for (auto &tiny : this->bursting_bubbles)
    {
        tiny.move();
        if (!(tiny.getXPosition() < 0 || tiny.getYPosition() < 0 || tiny.getXPosition() >= 5 || tiny.getYPosition() >= 6))
        {
            if(simulation){
                if (this->simulatedBoard.at(tiny.getYPosition()).at(tiny.getXPosition()) > 0)
                {
                    this->touchBubble(tiny.getXPosition(), tiny.getYPosition(), simulation);
                }
                else
                {
                    this->tiny_bubbles.push_back(tiny);
                }
            }else{
                if (this->board.at(tiny.getYPosition()).at(tiny.getXPosition()) > 0)
                {
                    this->touchBubble(tiny.getXPosition(), tiny.getYPosition(), simulation);
                }
                else
                {
                    this->tiny_bubbles.push_back(tiny);
                }
            }
        }
    }

    if (!simulation)
    {
        if (this->board != this->oldBoard)
        {
            this->display();
            this->oldBoard = this->board;
        }
    }
}

void Board::moveTinyBubbles(bool simulation)
{
    while (!this->tiny_bubbles.empty())
    {
        this->stepTinyBubbles(simulation);
    }

    if (!simulation)
    {
        if (this->board != this->oldBoard)
        {
            this->display();
            this->oldBoard = this->board;
        }
    }
}

void Board::playerTouch(int x, int y)
{
    this->tiny_bubbles.clear();
    this->touchBubble(x, y, false);
    this->moveTinyBubbles(false);
}

vector<pair<int, int>>  Board::possiblePlays(){

    vector<pair<int, int>> plays;

    for(size_t i = 0; i < this->board.size(); i++){
        for(size_t j = 0; j < this->board.at(i).size(); j++){
            if(this->board.at(i).at(j) != 0){
                pair<int,int> position(j,i);
                plays.push_back(position);
            }
        }
    }

    return plays;
}

bool Board::isSolution(){
    for(auto & i : this->board){
        for(int j : i){
            if(j != 0){
                return false;
            }
        }
    }
    return true;
}

//returns next bubble coordinates, if there is no next bubble returns (0,0)
pair<int, int> Board::getNextBubble(pair<int, int> bubble_coords)
{
    for (size_t i = bubble_coords.second + 1; i < this->board.size(); i++)
    {
        for (size_t j = bubble_coords.first + 1; j < this->board.at(0).size(); j++)
        {
            if (this->board.at(i).at(j) != 0)
            {
                return make_pair(j, i);
            }
        }
    }
    return make_pair(0, 0);
}

vector<vector<int>> Board::simulatePlayerTouch(int x, int y)
{
    this->tiny_bubbles.clear();
    this->simulatedBoard = this->board;
    this->touchBubble(x, y, true);
    this->moveTinyBubbles(true);

    return this->simulatedBoard;
}

int Board::getBoardTotalScore(){

    int total = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            total += this->board.at(i).at(j);
        }
    }

    return total;
}

float Board::getRedPercentage(){

    float reds = 0;
    float total = 0;
    int bubble;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bubble = this->board.at(i).at(j);
            if(bubble != 0){
                total += 1.0f;
            }
            if(bubble == 1){
                reds += 1.0f;
            }
        }
    }
    
    if(!total)
        return 1;

    return reds/total;
}