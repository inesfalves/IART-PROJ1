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

bool TinyBubble::operator< (const TinyBubble left) const{

    int rightValue = 0, leftValue = 0;

    if (left.direction == 'L' || left.direction == 'R')
    {
        leftValue = 2;
    }
    else
    {
        leftValue = 1;
    }

    if (this->direction == 'L' || this->direction == 'R')
    {
        rightValue = 2;
    }
    else
    {
        rightValue = 1;
    }

    return leftValue < rightValue;
}

