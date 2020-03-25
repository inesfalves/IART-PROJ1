#include <iostream>
#include <vector>
#include "board.h"

using namespace std;

Board::Board(){}

Board::Board(int b[6][5]){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            this->board[i][j] = b[i][j];
        } 
    } 
}

void Board::display(){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            cout << " " << this->board[i][j] << " ";
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

    this->board[y][x] = 0;
    
}

int Board::touchBubble(int x, int y){
    if(x < 0 || y < 0 || x >= 5 || y >= 6){
        return -1;
    }
    if(this->board[y][x] == 1){
        this->burstBubble(x,y);
    }
    else if(this->board[y][x] > 1){
        this->board[y][x]--;  
    }
    return 0;
}


/*void Board::stepTinyBubbles(){
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).display();
        if(i%4 == 0)
            cout<<endl;
    }
    cout << endl;
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).move();
        TinyBubble tiny = this->tiny_bubbles.at(i);
        if(tiny.x_position < 0 || tiny.y_position < 0 || tiny.x_position >= 5 || tiny.y_position >= 6){
            tiny_bubbles.erase(tiny_bubbles.begin() + i);
            i--;
        }
        else if(this->board[tiny.y_position][tiny.x_position] > 0){
            this->touchBubble(tiny.x_position, tiny.y_position);
            tiny_bubbles.erase(tiny_bubbles.begin() + i);
            i--;
        }
    }
    this->display();
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).display();
        if(i%4 == 0)
            cout<<endl;
    }
    cout << endl;
}*/

void Board::stepTinyBubbles(){
    vector<TinyBubble> tiny_final;
    cout << "BEFORE MOVE" << endl;
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).display();
        if(i%4 == 0)
            cout<<endl;
    }
    cout << endl;
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).move();
        TinyBubble tiny = this->tiny_bubbles.at(i);
        if(tiny.x_position < 0 || tiny.y_position < 0 || tiny.x_position >= 5 || tiny.y_position >= 6){
            continue;
        }
        else if(this->board[tiny.y_position][tiny.x_position] > 0){
            this->touchBubble(tiny.x_position, tiny.y_position);
        }
        else{
            tiny_final.push_back(tiny);
        }
    }

    this->display();

    cout << "AFTER MOVE" << endl;
    this->tiny_bubbles = tiny_final;
    for(size_t i = 0; i < this->tiny_bubbles.size(); i++){
        this->tiny_bubbles.at(i).display();
        if(i%4 == 0)
            cout<<endl;
    }
    cout << endl;
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

