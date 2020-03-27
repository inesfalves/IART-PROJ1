#ifndef TINYBUBBLE_H
#define TINYBUBBLE_H

#include <iostream>

using namespace std;

class TinyBubble {

    char direction;
    int x_position, y_position;

    public:
        TinyBubble(char direction, int x_position, int y_position);
        char getDirection() const;
        int getXPosition() const;
        int getYPosition() const;
        void setDirection(char direction);
        void setXPosition(int x_position);
        void setYPosition(int y_position);
        
        void move();
        void display();
        bool operator< (const TinyBubble bubble) const;
};

#endif
