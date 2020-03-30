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
    srand(time(NULL));

    cout << "Welcome to Bubble Blast! Do you want to play or check a search strategy?" << endl;
    cout << "1. I want to play the game!" << endl;
    cout << "2. Show me search algorithms!" << endl;
    cout << "Choose:";
    inputHandler(gameOption);
    while (gameOption != 1 && gameOption != 2)
    {
        cout << "Invalid input. Please try again: " << endl;
        inputHandler(gameOption);
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Choose a level from 1 to 35!" << endl;
    cout << "Level:";
    inputHandler(option);
    while (option < 1 && option > 35)
    {
        cout << "Invalid input. Please try again: " << endl;
        inputHandler(gameOption);
    }
    string levelOption = "levels/level";
    string optionString = to_string(option);
    levelOption.append(optionString);
    levelOption.append(".txt");
    maxMoves = getFileInfo(levelOption, &playerChooseBoard);

    switch (gameOption)
    {
    case 1:
        cout << "Let's play! Here's your starting board." << endl;
        cout << "----------------------------------------" << endl;
        playGamer(playerChooseBoard, maxMoves);
        return;
    case 2:
        cout << "----------------------------------" << endl;
        cout << "Choose a type of search strategy:" << endl;
        cout << "1. Uninformed Search" << endl;
        cout << "2. Informed (Heuristic) Search" << endl;
        cout << "Option:";
        inputHandler(option);
        while (option != 1 && option != 2)
        {
            cout << "Invalid input. Please try again: " << endl;
            inputHandler(option);
        }
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
        while (algorithm != 1 && algorithm != 2 && algorithm != 3)
        {
            cout << "Invalid input. Please try again: " << endl;
            inputHandler(algorithm);
        }
        handleUninformedAlgorithm(algorithm, playerChooseBoard, maxMoves);
        break;

    case 2:
        cout << "------------------------" << endl;
        cout << "Choose your algorithm:" << endl;
        cout << "1. Greedy search" << endl;
        cout << "2. A* search" << endl;
        cout << "Option:";
        inputHandler(algorithm);
        while (algorithm != 1 && algorithm != 2)
        {
            cout << "Invalid input. Please try again: " << endl;
            inputHandler(algorithm);
        }
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

        auto t1 = std::chrono::high_resolution_clock::now();
        moveList = tree->BFS(chosenBoard, maxMoves);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

        printMove(chosenBoard, moveList);
        break;
    }
    case 2:
    {
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;

        auto t1 = std::chrono::high_resolution_clock::now();
        moveList = tree->DFS(chosenBoard, maxMoves);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

        printMove(chosenBoard, moveList);

        break;
    }
    case 3:
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;

        auto t1 = std::chrono::high_resolution_clock::now();
        moveList = tree->UniformCost(chosenBoard, maxMoves);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

        printMove(chosenBoard, moveList);
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

        auto t1 = std::chrono::high_resolution_clock::now();
        moveList = tree->greedy(chosenBoard, maxMoves);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

        printMove(chosenBoard, moveList);
        break;
    }
    case 2:
        Tree *tree = new Tree();
        vector<pair<int, int>> moveList;

        auto t1 = std::chrono::high_resolution_clock::now();
        moveList = tree->AStar(chosenBoard, maxMoves);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

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

void playGamer(vector<vector<int>> playerChooseBoard, int maxMoves)
{
    Board chosenBoard = Board(playerChooseBoard);
    chosenBoard.display();
    int x, y;

    cout << "You have " << maxMoves << " moves to complete this level! Good luck :)" << endl;
    for (int i = 0; i <= maxMoves; i++)
    {
        if (i == maxMoves)
        {
            cout << "Level couldn't be completed within the move limit :( Please try again!" << endl;
            break;
        }

        cout << "-----------------------------------------------" << endl;
        cout << "Please choose what bubble you want to click on:" << endl;

        bool invalid = false;
        vector<pair<int, int>>::iterator it;
        vector<pair<int, int>> plays;

        do
        {
            do
            {
                if (invalid)
                {
                    cout << "Those moves are not possible! Try again please:" << endl;
                }
                cout << "x:";
                inputHandler(x);
                cout << "y:";
                inputHandler(y);
                invalid = true;
            } while ((x >= 5 && y >= 6) || (x < 0 && y < 0));

            plays = chosenBoard.possiblePlays();
            pair<int, int> move(x, y);
            it = find(plays.begin(), plays.end(), move);
        } while (it == plays.end());

        chosenBoard.playerTouch(x, y);

        if (chosenBoard.isSolution())
        {
            cout << "You won! Congrats" << endl;
            break;
        }

        cout << "You have " << maxMoves - i - 1 << " moves remaining :)" << endl;
    }
}