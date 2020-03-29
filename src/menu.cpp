#include "menu.h"

//é diferente em ios lol
//vector<vector<int>> level15 = {{2,4,1,0,4}, {1,2,0,2,1}, {2,1,1,2,2}, {2,3,1,2,0}, {0,3,4,2,4}, {3,1,1,3,2}};

//é diferente em ios??
//vector<vector<int>> level19 = {{0,4,0,1,3}, {3,4,1,2,4}, {3,3,2,2,1}, {2,2,1,4,1}, {2,3,1,3,3}, {2,1,1,3,3}};

int getFileInfo(string filename, vector<vector<int>> *board)
{
    ifstream file;
    file.open(filename);
    int maxMoves;
    if (file.is_open())
    {
        for (int i = 0; i < 6; i++)
        {
            string stringBoard;
            int number;
            vector<int> myNumbers;
            getline(file, stringBoard);

            stringstream iss(stringBoard);
            while (iss >> number)
            {
                myNumbers.push_back(number);
            }
            board->push_back(myNumbers);
        }

        string noMoves;
        getline(file, noMoves);
        maxMoves = stoi(noMoves);
    }

    file.close();

    return maxMoves;
}


void start()
{
    int option, algorithm, maxMoves;
    vector<vector<int>> playerChooseBoard;

    cout << "Welcome to Bubble Blast! Choose a level from 1 to 20!" << endl;
    cout << "Level:";
    inputHandler(option);
    string levelOption = "levels/level";
    string optionString = to_string(option);
    levelOption.append(optionString);
    levelOption.append(".txt");
    maxMoves = getFileInfo(levelOption, &playerChooseBoard);

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
        handleUninformedAlgorithm(algorithm, playerChooseBoard, maxMoves);
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

void handleUninformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard, int maxMoves)
{
    Board chosenBoard = Board(playerChooseBoard);

    switch (algorithm)
    {
    case 1:
    {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        moveList = tree->BFS(chosenBoard, maxMoves);

        printMove(chosenBoard, moveList);
        break;
    }
    case 2:
    {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        moveList = tree->DFS(chosenBoard, maxMoves);

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
        cout << "Not implemented yet :(" << endl;
        break;
    case 2:
        cout << "Not implemented yet :(" << endl;
        break;
    }
}

void inputHandler(int &input)
{

    while (!(cin >> input))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input. Please try again: ";
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void printMove(Board board, vector<pair<int, int>> moveList)
{

    if (moveList.empty())
    {
        cout << "Level can't be complete within the move limit :(" << endl;
        cout << endl
             << "Initial Board:" << endl;
        board.display();
        return;
    }
    else if (moveList.at(0).first == -1 && moveList.at(0).second == -1)
    {
        cout << "Level can't be complete within the move limit :(" << endl;
        cout << endl
             << "Initial Board:" << endl;
        board.display();
        return;
    }

    for (size_t i = 0; i < moveList.size(); i++)
    {
        cout << "MOVE " << i + 1 << ": "
             << "x=" << moveList.at(i).first << " y=" << moveList.at(i).second << endl;
    }

    cout << endl
         << "Initial Board:" << endl;
    board.display();

    for (size_t i = 0; i < moveList.size(); i++)
    {
        cout << "MOVE " << i + 1 << endl;
        board.playerTouch(moveList.at(i).first, moveList.at(i).second);
    }
}