#include <iostream>
#include "NoteGraph.h"

using namespace std;

int main()
{
    NoteGraph test = NoteGraph("../images/basic/5x5.png");
    test.printGraph();
    return 0;
}