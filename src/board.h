#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "tinybubble.h"

using namespace std;

class Board {

    public:
        vector<vector<int>> board{{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        vector<vector<int>> oldBoard{{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        Board();
        Board(vector<vector<int>>);
        vector<TinyBubble> tiny_bubbles;
        void display();
        void burstBubble(int x, int y);
        int touchBubble(int x, int y);
        void stepTinyBubbles();
        void moveTinyBubbles();
        void playerTouch(int x, int y);
};

#endif