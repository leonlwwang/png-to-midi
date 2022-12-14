/**
 * @file AStar.h
 *
 * Definition for A* Algorithm run on a NoteGraph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include "NoteGraph.h"

namespace notealgorithm {
    /**
     * Runs A* algorithm on a graph and constructs
       a minimum spanning tree out of the pathway.
     * Since a NoteGraph is a grid-like graph with a maximum of four directions 
       from each node, we opted to use Manhattan Distance as the heuristic.
     * Internally, A* picks the next node based on F, a parameter based on
       the sum of G and H. G is the cost of moving from the current node to the
       candidate node, and H is the Manhattan Distance starting from the candidate
       node to the very last node.
     * @param graph the NoteGraph
     * @return the Minimum Spanning Tree (MST)
     */
    NoteGraph aStar(const NoteGraph &graph);
}
