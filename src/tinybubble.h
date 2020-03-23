#ifndef TINYBUBBLE_H
#define TINYBUBBLE_H

#include <iostream>

using namespace std;

class TinyBubble {

    public:
        char direction;
        int x_position, y_position;
        void move();
        TinyBubble(char direction, int x_position, int y_position);
};

#endif
