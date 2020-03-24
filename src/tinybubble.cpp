#include "tinybubble.h"

using namespace std;

TinyBubble::TinyBubble(char direction, int x_position, int y_position){
    this->direction = direction;
    this->x_position = x_position;
    this->y_position = y_position;
}

void TinyBubble::move(){
    if(this->direction == 'U'){
        this->y_position--;
    }
    else if(this->direction == 'D'){
        this->y_position++;
    }
    else if(this->direction == 'L'){
        this->x_position--;
    }
    else if(this->direction == 'R'){
        this->x_position++;
    }
}

void TinyBubble::display(){
    cout << "(" << this->direction << "," << this->x_position << "," << this->y_position << ") ";
}