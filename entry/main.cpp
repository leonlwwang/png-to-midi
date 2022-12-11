#include <iostream>
#include "algorithms/Prim.h"
#include "algorithms/AStar.h"

using namespace std;

int main()
{
    /* full demonstration */
    std::cout << "\n\t\t\t\t\t\tORIGINAL GRAPH \n\n";
    NoteGraph test = NoteGraph("../images/basic/5x5.png");
    test.printGraph();
    std::cout << "\n\t\t\t\t\t\tPRIM MST \n\n";
    NoteGraph primMST = notealgorithm::prim(test);
    primMST.printGraph();
    std::cout << "\n\t\t\t\t\t\tASTAR MST \n\n";
    NoteGraph aStarMST = notealgorithm::aStar(test);
    aStarMST.printGraph();
    return 0;
}