#include <iostream>
#include <vector>
#include "algorithm"
#include "iterator"
#include "board.h"

using namespace std;

Board::Board()= default;

Board::Board(vector<vector<int>> b){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            this->board.at(i).at(j) = b.at(i).at(j);
            this->oldBoard.at(i).at(j) = b.at(i).at(j);
            this->simulatedBoard.at(i).at(j) = b.at(i).at(j);
        } 
    }
}

void Board::display(){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            cout << " " << this->board.at(i).at(j) << " ";
        } 
        cout << endl;
    }
    cout << endl;    
}

void Board::burstBubble(int x, int y){
    
    TinyBubble tiny_bubble1 = TinyBubble('L',x,y);
    TinyBubble tiny_bubble2 = TinyBubble('R',x,y);
    TinyBubble tiny_bubble3 = TinyBubble('U',x,y);
    TinyBubble tiny_bubble4 = TinyBubble('D',x,y);

    this->tiny_bubbles.push_back(tiny_bubble1);
    this->tiny_bubbles.push_back(tiny_bubble2);
    this->tiny_bubbles.push_back(tiny_bubble3);
    this->tiny_bubbles.push_back(tiny_bubble4);

    this->board.at(y).at(x) = 0;
    
}

int Board::touchBubble(int x, int y){
    if(x < 0 || y < 0 || x >= 5 || y >= 6){
        return -1;
    }
    if(this->board.at(y).at(x) == 1){
        this->burstBubble(x,y);
    }
    else if(this->board.at(y).at(x) > 1){
        this->board.at(y).at(x)--;
    }
    return 0;
}

bool Board::compare(const TinyBubble left, const TinyBubble right) {
    int rightValue = 0, leftValue = 0;

    if(left.direction == 'L' || left.direction == 'R'){
        leftValue = 2;
    }else{
        leftValue = 1;
    }

    if(right.direction == 'L' || right.direction == 'R'){
        rightValue = 2;
    }else{
        rightValue = 1;
    }

    return leftValue > rightValue;
}

void Board::stepTinyBubbles(){
    sort(tiny_bubbles.begin(), tiny_bubbles.end(), &compare);
    this->bursting_bubbles = this->tiny_bubbles;

    this->tiny_bubbles.clear();


    for(auto & tiny : this->bursting_bubbles){
        tiny.move();
        if(!(tiny.x_position < 0 || tiny.y_position < 0 || tiny.x_position >= 5 || tiny.y_position >= 6)){
            if(this->board.at(tiny.y_position).at(tiny.x_position) > 0){
                this->touchBubble(tiny.x_position, tiny.y_position);
            }else{
                this->tiny_bubbles.push_back(tiny);
            }
        }
    }
    if(this->board != this->oldBoard){
        this->display();
        this->oldBoard = this->board;
    }
}


void Board::moveTinyBubbles(){
    while(!this->tiny_bubbles.empty()){
        this->stepTinyBubbles();
    }
    if(this->board != this->oldBoard){
        this->display();
        this->oldBoard = this->board;
    }
}

void Board::playerTouch(int x, int y){
    this->tiny_bubbles.clear();
    this->touchBubble(x,y);
    this->moveTinyBubbles();
}

bool Board::isSolution(){
    for(size_t i = 0; i < this->board.size(); i++){
        for(size_t j=0; j < this->board.at(0).size(); j++){
            if(this->board.at(i).at(j) != 0){
                return false;
            }
        }
    }
    return true;
}

//returns next bubble coordinates, if there is no next bubble returns (0,0)
pair<int,int> Board::getNextBubble(pair<int,int> bubble_coords){
    for(size_t i = bubble_coords.second+1; i < this->board.size(); i++){
        for(size_t j = bubble_coords.first+1; j < this->board.at(0).size(); j++){
            if(this->board.at(i).at(j) !=0){
                return make_pair(j,i);
            }
        }
    }
    return make_pair(0,0);
}



void Board::simulateStepTinyBubbles(){
    sort(tiny_bubbles.begin(), tiny_bubbles.end(), &compare);
    this->bursting_bubbles = this->tiny_bubbles;
    this->tiny_bubbles.clear();


    for(auto & tiny : this->bursting_bubbles){
        tiny.move();
        if(!(tiny.x_position < 0 || tiny.y_position < 0 || tiny.x_position >= 5 || tiny.y_position >= 6)){
            if(this->board.at(tiny.y_position).at(tiny.x_position) > 0){
                this->simulateTouchBubble(tiny.x_position, tiny.y_position);
            }else{
                this->tiny_bubbles.push_back(tiny);
            }
        }
    }

}


void Board::simulateMoveTinyBubbles(){
    while(!this->tiny_bubbles.empty()){
        this->simulateStepTinyBubbles();
    }
}

int Board::simulateTouchBubble(int x, int y){
    if(x < 0 || y < 0 || x >= 5 || y >= 6){
        return -1;
    }
    if(this->simulatedBoard.at(y).at(x) == 1){
        this->simulateBurstBubble(x,y);
    }
    else if(this->simulatedBoard.at(y).at(x) > 1){
        this->simulatedBoard.at(y).at(x)--;
    }
    return 0;
}

void Board::simulateBurstBubble(int x, int y){

    TinyBubble tiny_bubble1 = TinyBubble('L',x,y);
    TinyBubble tiny_bubble2 = TinyBubble('R',x,y);
    TinyBubble tiny_bubble3 = TinyBubble('U',x,y);
    TinyBubble tiny_bubble4 = TinyBubble('D',x,y);

    this->tiny_bubbles.push_back(tiny_bubble1);
    this->tiny_bubbles.push_back(tiny_bubble2);
    this->tiny_bubbles.push_back(tiny_bubble3);
    this->tiny_bubbles.push_back(tiny_bubble4);

    this->simulatedBoard.at(y).at(x) = 0;

}

vector<vector<int>> Board::simulatePlayerTouch(int x, int y) {
    this->tiny_bubbles.clear();
    this->simulateTouchBubble(x,y);
    this->simulateMoveTinyBubbles();

    return this->simulatedBoard;
}

