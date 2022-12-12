#include <list>
#include <iostream>
#include "algorithms/Prim.h"
#include "algorithms/AStar.h"
#include "algorithms/DFS.h"

using namespace std;

int main()
{
    /* full demonstration */
    std::cout << "\n\t\t\t\t\t\tORIGINAL GRAPH \n\n";
    NoteGraph test = NoteGraph("../images/basic/3x3.png");
    test.printGraph();

    std::cout << "\nDFS:\t";
    std::list<int> og = notealgorithm::DFS(test);
    for (auto i : og) {
        std::cout << i << " -> ";
    }
    std::cout << '\n';

    std::cout << "\n\t\t\t\t\t\tPRIM MST \n\n";
    NoteGraph primMST = notealgorithm::prim(test);
    primMST.printGraph();

    std::cout << "\nDFS:\t";
    std::list<int> prim = notealgorithm::DFS(primMST);
    for (auto i : prim) {
        std::cout << i << " -> ";
    }
    std::cout << '\n';

    std::cout << "\n\t\t\t\t\t\tASTAR MST \n\n";
    NoteGraph aStarMST = notealgorithm::aStar(test);
    aStarMST.printGraph();

    std::cout << "\nDFS:\t";
    std::list<int> aStar = notealgorithm::DFS(aStarMST);
    for (auto i : aStar) {
        std::cout << i << " -> ";
    }
    std::cout << "\n\n";

    return 0;
}