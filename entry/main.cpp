#include <iostream>
#include "NoteGraph.h"

int main()
{
    NoteGraph n = NoteGraph("../images/basic/10x10.png");
    std::cout << n.graph().size() << "x";
    std::cout << n.graph()[0].size() << '\n';
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
