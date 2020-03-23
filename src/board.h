#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "tinybubble.h"

using namespace std;

class Board {

    public:
        int board[6][5];
        Board();
        Board(int board[6][5]);
        vector<TinyBubble> tiny_bubbles;
        void display();
        void burstBubble(int x, int y);
        int touchBubble(int x, int y);
        void stepTinyBubbles();
        void moveTinyBubbles();
        void playerTouch(int x, int y);
};

#endif