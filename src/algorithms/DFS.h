/**
 * @file DFS.h
 *
 * Definition for DFS traversal through a graph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include <list>
#include <stack>
#include "NoteGraph.h"

namespace notealgorithm {
    /**
     * Runs DFS on a NoteGraph and outputs all the edges into
       a linked list. Traverse the list to get the sequence in order. 
     * @param graph the NoteGraph
     * @return a list of Notes
     */
    std::list<int> DFS(const NoteGraph &graph);
}
