#ifndef MENU_H
#define MENU_H

#include "tinybubble.h"
#include "board.h"
#include "solution_graph.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* Function to let the player choose a level */
vector<vector<int>> chooseLevelForPlayer(int playerChooseLevel);
/* Starts the program menu */
void start();
/* Handles the uninformed search strategies */
void handleUninformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard);
/* Handles the informed search strategies */
void handleInformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard);
/* Validates user input */
void inputHandler(int &input);

void printMove(Board board, vector<pair<int,int>> moveList);

#endif
