#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "tinybubble.h"

using namespace std;

class Board {

    public:
        vector<vector<int>> board{{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        vector<vector<int>> simulatedBoard{{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        vector<vector<int>> oldBoard{{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        Board();
        Board(vector<vector<int>>);
        vector<TinyBubble> tiny_bubbles;
        vector<TinyBubble> bursting_bubbles;
        void display();
        void burstBubble(int x, int y);
        int touchBubble(int x, int y);
        void stepTinyBubbles();
        void moveTinyBubbles();
        void playerTouch(int x, int y);
        static bool compare(TinyBubble left, TinyBubble right);
        bool isSolution();
        pair<int,int> getNextBubble(pair<int,int> bubble_coords);

        vector<vector<int>> simulatePlayerTouch(int x, int y);
        int simulateTouchBubble(int x, int y);
        void simulateMoveTinyBubbles();
        void simulateStepTinyBubbles();
        void simulateBurstBubble(int x, int y);

    int possiblePlays();
};

#endif