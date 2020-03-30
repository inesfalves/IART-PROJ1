#ifndef MENU_H
#define MENU_H

#include "tinybubble.h"
#include "board.h"
#include "solution_graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <ctime>
#include <chrono>

using namespace std;

/* Function to let the player choose a level */
vector<vector<int>> chooseLevelForPlayer(int playerChooseLevel);
/* Starts the program menu */
void start();
/* Handles the uninformed search strategies */
void handleUninformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard, int maxMoves);
/* Handles the informed search strategies */
void handleInformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard, int maxMoves);
/* Validates user input */
void inputHandler(int &input);
/* Prints a move */
void printMove(Board board, vector<pair<int,int>> moveList);
/* Used for playing the game */
void playGamer(vector<vector<int>> playerChooseBoard, int maxMoves);

#endif
