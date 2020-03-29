#include "menu.h"

vector<vector<int>> level1 = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

vector<vector<int>> level2 = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

vector<vector<int>> level3 = {{1, 0, 1, 0, 1}, {0, 0, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 0, 1, 0, 1}};

vector<vector<int>> level4 = {{0, 0, 0, 0, 0}, {2, 2, 2, 2, 2}, {2, 1, 1, 1, 2}, {2, 1, 1, 1, 2}, {2, 2, 2, 2, 2}, {0, 0, 0, 0, 0}};

vector<vector<int>> level5 = {{0, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 2, 0, 0, 1}, {0, 2, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}};

vector<vector<int>> level6 = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 2, 1, 1, 2}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

vector<vector<int>> level7 = {{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {1, 2, 1, 2, 1}, {0, 2, 0, 2, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 0, 0}};

vector<vector<int>> level8 = {{1, 2, 2, 2, 1}, {2, 4, 3, 4, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {1, 2, 2, 2, 1}, {1, 2, 1, 2, 1}};

vector<vector<int>> level9 = {{1, 0, 1, 0, 1}, {2, 0, 1, 0, 2}, {2, 0, 1, 0, 2}, {2, 0, 1, 0, 2}, {2, 0, 1, 0, 2}, {2, 3, 1, 3, 2}};

vector<vector<int>> level10 = {{2, 2, 2, 2, 2}, {2, 1, 2, 1, 2}, {2, 0, 1, 0, 2}, {2, 0, 1, 0, 2}, {2, 1, 3, 1, 2}, {2, 2, 2, 2, 2}};

vector<vector<int>> level11 = {{4, 2, 2, 3, 1}, {0, 2, 0, 1, 2}, {4, 1, 3, 4, 4}, {4, 1, 1, 4, 1}, {1, 2, 3, 1, 1}, {1, 0, 3, 3, 0}};

vector<vector<int>> level12 = {{1, 4, 3, 1, 2}, {1, 0, 3, 1, 4}, {1, 1, 3, 4, 4}, {2, 2, 1, 2, 1}, {2, 2, 1, 0, 3}, {0, 0, 1, 2, 1}};

vector<vector<int>> level13 = {{1, 2, 3, 0, 1}, {3, 2, 4, 4, 3}, {0, 2, 1, 1, 2}, {3, 1, 3, 2, 2}, {4, 2, 1, 3, 2}, {1, 4, 0, 2, 4}};

vector<vector<int>> level14 = {{4, 3, 1, 2, 4}, {1, 1, 4, 2, 3}, {3, 0, 1, 1, 2}, {2, 1, 1, 0, 0}, {0, 2, 0, 4, 2}, {2, 0, 1, 3, 0}};

//é diferente em ios lol
//vector<vector<int>> level15 = {{2,4,1,0,4}, {1,2,0,2,1}, {2,1,1,2,2}, {2,3,1,2,0}, {0,3,4,2,4}, {3,1,1,3,2}};

vector<vector<int>> level16 = {{2, 4, 4, 1, 1}, {2, 2, 2, 0, 4}, {0, 4, 2, 2, 2}, {1, 1, 1, 3, 1}, {1, 4, 0, 1, 4}, {4, 0, 3, 2, 0}};

vector<vector<int>> level17 = {{0, 4, 3, 2, 2}, {1, 2, 2, 2, 1}, {1, 2, 2, 2, 2}, {0, 3, 1, 1, 3}, {3, 2, 0, 2, 0}, {2, 4, 2, 2, 0}};

vector<vector<int>> level18 = {{0, 3, 2, 4, 0}, {1, 1, 1, 2, 0}, {0, 1, 4, 1, 2}, {0, 4, 2, 0, 1}, {1, 1, 1, 2, 2}, {0, 4, 0, 1, 1}};

//é diferente em ios??
//vector<vector<int>> level19 = {{0,4,0,1,3}, {3,4,1,2,4}, {3,3,2,2,1}, {2,2,1,4,1}, {2,3,1,3,3}, {2,1,1,3,3}};

vector<vector<int>> level20 = {{3, 4, 3, 0, 2}, {3, 1, 1, 2, 4}, {1, 3, 1, 0, 1}, {0, 2, 0, 3, 1}, {4, 4, 1, 1, 2}, {4, 1, 4, 4, 1}};

vector<vector<int>> chooseLevelForPlayer(int playerChooseLevel)
{
    switch (playerChooseLevel)
    {
    case 1:
        return level1;
    case 2:
        return level2;
    case 3:
        return level3;
    case 4:
        return level4;
    case 5:
        return level5;
    case 6:
        return level6;
    case 7:
        return level7;
    case 8:
        return level8;
    case 9:
        return level9;
    case 10:
        return level10;
    case 11:
        return level11;
    case 12:
        return level12;
    case 13:
        return level13;
    case 14:
        return level14;
    case 16:
        return level16;
    case 17:
        return level17;
    case 18:
        return level18;
    case 20:
        return level20;
    }

}

void start()
{
    int option, algorithm;
    vector<vector<int>> playerChooseBoard;
    cout << "Welcome to Bubble Blast! Choose a level from 1 to 20!" << endl;
    cout << "Level:";
    inputHandler(option);
    playerChooseBoard = chooseLevelForPlayer(option);
    cout << "----------------------------------" << endl;
    cout << "Choose a type of search strategy:" << endl;
    cout << "1. Uninformed Search" << endl;
    cout << "2. Informed (Heuristic) Search" << endl;
    cout << "Option:";
    inputHandler(option);

    switch (option)
    {
    case 1:
        cout << "------------------------" << endl;
        cout << "Choose your algorithm:" << endl;
        cout << "1. Breadth-first search" << endl;
        cout << "2. Depth-first search" << endl;
        cout << "3. Uniform-cost search" << endl;
        cout << "Option:";
        inputHandler(algorithm);
        handleUninformedAlgorithm(algorithm, playerChooseBoard);
        break;

    case 2:
        cout << "------------------------" << endl;
        cout << "Choose your algorithm:" << endl;
        cout << "1. Greedy search" << endl;
        cout << "2. A* search" << endl;
        cout << "Option:";
        inputHandler(algorithm);
        handleInformedAlgorithm(algorithm, playerChooseBoard);
        break;
    }
}

void handleUninformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard)
{
    Board chosenBoard = Board(playerChooseBoard);

    switch (algorithm)
    {
    case 1:
        {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        //definir o numero de toques para cada board
        moveList = tree->BFS(chosenBoard, 3);

        printMove(chosenBoard, moveList);

        break;
        }
    case 2:
        {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        //definir o numero de toques para cada board
        moveList = tree->DFS(chosenBoard, 3);

        printMove(chosenBoard, moveList);

        break;
        }
    case 3:
        cout << "Not implemented yet :(" << endl;
        break;
    }
}

void handleInformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard)
{
    switch (algorithm)
    {
    case 1:
    {
        Tree *tree = new Tree();
        vector<pair<int, int>> vec;
        //definir o numero de toques para cada board
        vec = tree->greedy(playerChooseBoard, 2);
        for (auto &i : vec)
        {
            cout << i.first << "   " << i.second << endl;
        }
        break;
    }
    case 2:
        cout << "Not implemented yet :(" << endl;
        break;
    }
}

void inputHandler(int &input){

	while(!(cin>>input))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Invalid input. Please try again: ";
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void printMove(Board board, vector<pair<int,int>> moveList){

    if(moveList.empty()){
        cout << "Level can't be complete within the move limit :(" << endl;
        cout << endl << "Initial Board:" << endl;
        board.display();
        return;
    }else if(moveList.at(0).first == -1 && moveList.at(0).second == -1){
        cout << "Level can't be complete within the move limit :(" << endl;
        cout << endl << "Initial Board:" << endl;
        board.display();
        return;
    }

    for (size_t i = 0; i < moveList.size(); i++)
    {
        cout << "MOVE " << i+1 << ": "  << "x=" <<  moveList.at(i).first << " y=" << moveList.at(i).second << endl;
    }

    cout << endl << "Initial Board:" << endl;
    board.display();

    for (size_t i = 0; i < moveList.size(); i++)
    {
        cout << "MOVE " << i+1 << endl;
        board.playerTouch(moveList.at(i).first, moveList.at(i).second);
    }
}