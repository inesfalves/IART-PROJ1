#ifndef TINYBUBBLE_H
#define TINYBUBBLE_H

#include <iostream>

using namespace std;

class TinyBubble {

    public:
        char direction;
        int x_position, y_position;
        TinyBubble(char direction, int x_position, int y_position);
        void move();
        void display();
};

#endif
