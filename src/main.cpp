#include <iostream>
#include "tinybubble.h"
#include "board.h"
#include "solution_graph.h"

// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    Board board;

    vector<vector<int>> level1 = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

    vector<vector<int>> level2 = {{0,0,0,0,0}, {0,0,0,0,0}, {0,1,0,1,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

    vector<vector<int>> level3 = {{1,0,1,0,1}, {0,0,0,0,0}, {1,0,1,0,1}, {0,0,0,0,0}, {0,0,0,0,0}, {1,0,1,0,1}};

    vector<vector<int>> level4 = {{0,0,0,0,0}, {2,2,2,2,2}, {2,1,1,1,2}, {2,1,1,1,2}, {2,2,2,2,2}, {0,0,0,0,0}};

    vector<vector<int>> level5 = {{0,1,0,0,1}, {0,0,0,0,0}, {0,2,0,0,1}, {0,2,0,0,1}, {0,0,0,0,0}, {0,1,0,0,1}};

    vector<vector<int>> level6 = {{0,0,0,0,0}, {0,0,0,0,0}, {1,2,1,1,2}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

    vector<vector<int>> level7 = {{0,0,0,0,0}, {0,1,0,1,0}, {1,2,1,2,1}, {0,2,0,2,0}, {0,1,0,1,0}, {0,0,0,0,0}};

    vector<vector<int>> level8 = {{1,2,2,2,1}, {2,4,3,4,2}, {2,2,2,2,2}, {2,2,2,2,2}, {1,2,2,2,1}, {1,2,1,2,1}};

    vector<vector<int>> level9 = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

    vector<vector<int>> level10 = {{2,2,2,2,2}, {2,1,2,1,2}, {2,0,1,0,2}, {2,0,1,0,2}, {2,1,3,1,2}, {2,2,2,2,2}};

    vector<vector<int>> level11 = {{4,2,2,3,1}, {0,2,0,1,2}, {4,1,3,4,4}, {4,1,1,4,1}, {1,2,3,1,1}, {1,0,3,3,0}};

    vector<vector<int>> level12 = {{1,4,3,1,2}, {1,0,3,1,4}, {1,1,3,4,4}, {2,2,1,2,1}, {2,2,1,0,3}, {0,0,1,2,1}};

    vector<vector<int>> level13 = {{1,2,3,0,1}, {3,2,4,4,3}, {0,2,1,1,2}, {3,1,3,2,2}, {4,2,1,3,2}, {1,4,0,2,4}};

    vector<vector<int>> level14 = {{4,3,1,2,4}, {1,1,4,2,3}, {3,0,1,1,2}, {2,1,1,0,0}, {0,2,0,4,2}, {2,0,1,3,0}};

    //é diferente em ios lol 
    //vector<vector<int>> level15 = {{2,4,1,0,4}, {1,2,0,2,1}, {2,1,1,2,2}, {2,3,1,2,0}, {0,3,4,2,4}, {3,1,1,3,2}};

    vector<vector<int>> level16 = {{2,4,4,1,1}, {2,2,2,0,4}, {0,4,2,2,2}, {1,1,1,3,1}, {1,4,0,1,4}, {4,0,3,2,0}};

    vector<vector<int>> level17= {{0,4,3,2,2}, {1,2,2,2,1}, {1,2,2,2,2}, {0,3,1,1,3}, {3,2,0,2,0}, {2,4,2,2,0}};

    vector<vector<int>> level18 = {{0,3,2,4,0}, {1,1,1,2,0}, {0,1,4,1,2}, {0,4,2,0,1}, {1,1,1,2,2}, {0,4,0,1,1}};

    //é diferente em ios??
    //vector<vector<int>> level19 = {{0,4,0,1,3}, {3,4,1,2,4}, {3,3,2,2,1}, {2,2,1,4,1}, {2,3,1,3,3}, {2,1,1,3,3}};

    vector<vector<int>> level20 = {{3,4,3,0,2}, {3,1,1,2,4}, {1,3,1,0,1}, {0,2,0,3,1}, {4,4,1,1,2}, {4,1,4,4,1}};

    //vector<vector<int>> level3 = {{0,0,0,0,0}, {2,2,2,2,2}, {2,1,1,1,2}, {2,1,1,1,2}, {2,2,2,2,2}, {0,0,0,0,0}};

    vector<vector<int>> levelx = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,1,0,0}};

    //int level3[6][5] = {{}, {}, {}, {}, {}, {}};

    /*
    board = Board(level8);

    vector<vector<int>> test = board.simulatePlayerTouch(2, 4);

    for (auto & i : test) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    board.display();

    cout << "MOVE 1 ----------------------"<<endl;

    board.playerTouch(1,3);

    cout << "MOVE 2 ----------------------"<<endl;

    board.playerTouch(2,3);

    cout << "MOVE 3 ----------------------"<<endl;

    board.playerTouch(2,3);
    */

    Tree* tree = new Tree();
    vector<pair<int,int>> vec;
    vec = tree->BFS(level8);
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i).first <<  "   " << vec.at(i).second << endl;
    }


    /*
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
    */
    
    return 0; 
} 