#include "menu.h"

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
    int gameOption, option, algorithm, maxMoves;
    vector<vector<int>> playerChooseBoard;

    cout << "Welcome to Bubble Blast! Do you want to play or check a search strategy?" << endl;
    cout << "1. I want to play the game!" << endl;
    cout << "2. Show me search algorithms!" << endl;
    cout << "Choose:";
    inputHandler(gameOption);

    cout << "-----------------------------------------------" << endl;
    cout << "Choose a level from 1 to 20!" << endl;
    cout << "Level:";
    inputHandler(option);
    string levelOption = "levels/level";
    string optionString = to_string(option);
    levelOption.append(optionString);
    levelOption.append(".txt");
    maxMoves = getFileInfo(levelOption, &playerChooseBoard);

    switch (gameOption)
    {
    case 1:
        cout << "let's play xd" << endl;
        break;
    case 2:
        cout << "----------------------------------" << endl;
        cout << "Choose a type of search strategy:" << endl;
        cout << "1. Uninformed Search" << endl;
        cout << "2. Informed (Heuristic) Search" << endl;
        cout << "Option:";
        inputHandler(option);
        break;
    }

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
        handleInformedAlgorithm(algorithm, playerChooseBoard, maxMoves);
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

void handleInformedAlgorithm(int algorithm, vector<vector<int>> playerChooseBoard, int maxMoves)
{
    Board chosenBoard = Board(playerChooseBoard);

    switch (algorithm)
    {
    case 1:
    {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        //definir o numero de toques para cada board
<<<<<<< HEAD
        moveList = tree->greedy(chosenBoard, maxMoves);
=======
        moveList = tree->greedy(chosenBoard, 3);
>>>>>>> 899a5439268a9ea8dea93c743fbf8ebdf45690e0
        printMove(chosenBoard, moveList);
        break;
    }
    case 2:
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;
        //definir o numero de toques para cada board
        moveList = tree->AStar(chosenBoard, maxMoves);
        printMove(chosenBoard, moveList);
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