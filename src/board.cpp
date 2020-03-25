#include <iostream>
#include <vector>
#include "algorithm"
#include "iterator"
#include "board.h"

using namespace std;

Board::Board(){}

Board::Board(vector<vector<int>> b){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            this->board.at(i).at(j) = b.at(i).at(j);
            this->oldBoard.at(i).at(j) = b.at(i).at(j);
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


void Board::stepTinyBubbles(){
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).display();
        if(i%4 == 0)
            cout<<endl;
    }
    cout<<endl;
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).move();
        TinyBubble tiny = this->tiny_bubbles.at(i);
        if(tiny.x_position < 0 || tiny.y_position < 0 || tiny.x_position >= 5 || tiny.y_position >= 6){
            tiny_bubbles.erase(tiny_bubbles.begin() + i);
            i--;
        }
        else if(this->board.at(tiny.y_position).at(tiny.x_position) > 0){
            this->touchBubble(tiny.x_position, tiny.y_position);
            tiny_bubbles.erase(tiny_bubbles.begin() + i);
            i--;
        }
    }
    if(this->board != this->oldBoard){
        this->display();
        this->oldBoard = this->board;
    }
}

void Board::moveTinyBubbles(){
    while(this->tiny_bubbles.size() > 0){
        this->stepTinyBubbles();
    }
}

void Board::playerTouch(int x, int y){
    this->tiny_bubbles.clear();
    this->touchBubble(x,y);
    this->moveTinyBubbles();
}

