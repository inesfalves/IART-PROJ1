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

    vector<vector<int>> level17= {{0,4,3,2,2}, {1,2,2,2,1}, {1,2,2,2,2}, {0,3,1,1,3}, {3,2,0,2,0}, {2,4,2,2,0}};

    vector<vector<int>> level3 = {{0,0,0,0,0}, {2,2,2,2,2}, {2,1,1,1,2}, {2,1,1,1,2}, {2,2,2,2,2}, {0,0,0,0,0}};

    vector<vector<int>> level8 = {{1,2,2,2,1}, {2,4,3,4,2}, {2,2,2,2,2}, {2,2,2,2,2}, {1,2,2,2,1}, {1,2,1,2,1}};

    vector<vector<int>> levelx = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,1,0,0}};

    //int level3[6][5] = {{}, {}, {}, {}, {}, {}};

    board = Board(level8);

    board.display();

    cout << "MOVE 1 ----------------------"<<endl;

    board.playerTouch(1,3);

    cout << "MOVE 2 ----------------------"<<endl;

    board.playerTouch(2,3);

    cout << "MOVE 3 ----------------------"<<endl;

    board.playerTouch(2,3);


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