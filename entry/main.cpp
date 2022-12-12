#include <iostream>
#include "NoteGraph.h"
#include "algorithms/Prim.h"
#include "algorithms/AStar.h"
#include "algorithms/DFS.h"

using namespace std;

int main()
{
    NoteGraph test = NoteGraph("../images/basic/3x3.png");
    std::list<int> dfs = notealgorithm::DFS(test);
    for (auto const& i : dfs) {
        std::cout << i << std::endl;
    }   
    return 0;
}