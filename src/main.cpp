#include <iostream>
#include "tinybubble.h"
#include "board.h"

// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    Board board;
    
    int level17[6][5] = {{0,4,3,2,2}, {1,2,2,2,1}, {1,2,2,2,2}, {0,3,1,1,3}, {3,2,0,2,0}, {2,4,2,2,0}};

    int level3[6][5] = {{0,0,0,0,0}, {2,2,2,2,2}, {2,1,1,1,2}, {2,1,1,1,2}, {2,2,2,2,2}, {0,0,0,0,0}};

    int level8[6][5] = {{1,2,2,2,1}, {2,4,3,4,2}, {2,2,2,2,2}, {2,2,2,2,2}, {1,2,2,2,1}, {1,2,1,2,1}};

    int levelx[6][5] = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,1,0,0}};

    //int level3[6][5] = {{}, {}, {}, {}, {}, {}};

    board = Board(levelx);

    /*
        LEVEL 8
    board.display();

    board.playerTouch(1,3);

    board.display();

    board.playerTouch(2,3);

    board.display();

    board.playerTouch(2,3);

    board.display();*/

    board.display();

    board.playerTouch(2,0);

    board.display();


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