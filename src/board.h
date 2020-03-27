#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "tinybubble.h"

using namespace std;

class Board
{

    vector<vector<int>> board{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<vector<int>> simulatedBoard{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<vector<int>> oldBoard{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<TinyBubble> tiny_bubbles;
    vector<TinyBubble> bursting_bubbles;

public:
    Board();
    Board(vector<vector<int>>);

    vector<vector<int>> getBoard() const;
    vector<vector<int>> getSimulatedBoard() const;
    vector<vector<int>> getOldBoard() const;
    vector<TinyBubble> getTinyBubbles() const;
    vector<TinyBubble> getBurstingBubbles() const;
    void setTinyBubbles(vector<TinyBubble> tiny_bubbles);
    void setBurstingBubbles(vector<TinyBubble> bursting_bubbles);
    void setBoard(vector<vector<int>> board);
    void setSimulatedBoard(vector<vector<int>> simulatedBoard);
    void setOldBoard(vector<vector<int>> oldBoard);

    void display();
    void burstBubble(int x, int y, bool simulation);
    int touchBubble(int x, int y, bool simulation);
    void stepTinyBubbles(bool simulation);
    void moveTinyBubbles(bool simulation);
    void playerTouch(int x, int y);
    bool isSolution();
    pair<int, int> getNextBubble(pair<int, int> bubble_coords);
    vector<vector<int>> simulatePlayerTouch(int x, int y);
    int possiblePlays();
};

#endif