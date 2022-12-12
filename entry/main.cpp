#include <iostream>
#include "NoteGraph.h"

#include "algorithms/Prim.h"
#include "algorithms/AStar.h"

int main()
{
    NoteGraph n = NoteGraph("../images/basic/3x3.png");
    std::cout << "Original Graph\n\n";
    n.printGraph();

    /*
    NoteGraph primMST = notealgorithm::prim(n);
    std::cout << "\nPrim's Algorithm\n\n";
    primMST.printGraph();
    NoteGraph aStarMST = notealgorithm::aStar(n);
    std::cout << "\nA* Algorithm\n\n";
    aStarMST.printGraph();
    */
    
    return 0;
}